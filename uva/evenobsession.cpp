/*
              Mania de Par - Problema A
    Maratona de Programação da SBC - Primeira Fase
                  ACM ICPC - 2015
                                                        */
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define weight first
#define vertex second
using namespace std;

typedef pair<int,int> pii;

vector<pii> adj[20008];
int c, d[20008];

void solve(int ini){
    set<pii> s;
    d[ini] = 0;
    s.insert(mp(0,ini));
    while(s.size()){
        int x = s.begin()->vertex;
        s.erase(s.begin());
        for(int i = 0; i < adj[x].size(); i++){
            pii nxt = adj[x][i];
            if(d[nxt.vertex] > d[x] + nxt.weight){
                d[nxt.vertex] = d[x] + nxt.weight;
                s.insert(mp(d[nxt.vertex], nxt.vertex));
            }
        }
    }
}

int main(){
    int v, a, b, w;

    while(scanf("%d %d", &c, &v) != EOF){
        for(int i = 0 ; i < 20008; i++){
            d[i] = INT_MAX;
            adj[i].clear();
        }
        for(int i = 0; i < v; i++){
            scanf("%d %d %d", &a, &b, &w);
            adj[a].pb(mp(w,c+b));
            adj[c+a].pb(mp(w,b));
            adj[b].pb(mp(w,c+a));
            adj[c+b].pb(mp(w,a));
        }
        solve(1);
        if(d[c] != INT_MAX)
            printf("%d\n", d[c]);
        else
            printf("-1\n");
    }
}
