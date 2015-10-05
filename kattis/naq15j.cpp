#include <bits/stdc++.h>
#define pb push_back
using namespace std;
map<string, int> m;
char s[100005];
int n;
char foo[30];
string bar;
vector<int> adj[1500];
string hue[1500];
int path[1500];
int d[1500];

void bfs (int ini){
    queue<int> q;
    q.push(ini);
    d[ini] = 0;
    while(q.size()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < adj[x].size(); i++)
            if(d[adj[x][i]] > d[x] + 1){
                d[adj[x][i]] = d[x] + 1;
                q.push(adj[x][i]);
                path[adj[x][i]] = x;
            }
    }
}

void trace(int no){
    if(path[no] == no) {
        return;
    }
    else {
        trace(path[no]);
        printf(" %s",hue[no].c_str());
    }
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < 1500; i++)
        d[i] = INT_MAX;
    for(int i = 0; i < 1500; i++)
        path[i] = i;
    int w = 1;
    for(int i = 0; i < n; i++){
        scanf(" %[^\n]",s);
        int k = 0, a, b;
        while(s[k] != ' ') {
            foo[k] = s[k];
            k++;
        }
        foo[k++] = '\0';
        bar = foo;
        if(!m[bar]) m[bar] = w++; 
        a = m[bar];
        int p = 0;
        for(int j = k; ; j++){
            if(s[j] == ' ' || s[j] == '\0'){
                foo[p] = '\0';
                bar = foo;
                if(!m[bar]) m[bar] = w++;
                b = m[bar];
                adj[a].pb(b);
                adj[b].pb(a);
                p = 0;   
                if(s[j] == '\0') break;
            }
            else {
                foo[p++] = s[j];
            }   
        }
    }
    map<string,int>::iterator it;
    for(it = m.begin(); it != m.end(); it++)
        hue[it->second] = it->first;
    scanf(" %s %s",s,foo);
    if(m[s])
        bfs(m[s]);
    if(!m[foo] || d[m[foo]] == INT_MAX) puts("no route found");
    else {
        printf("%s",hue[m[s]].c_str());
        trace(m[foo]);
        printf("\n");
    }
}
