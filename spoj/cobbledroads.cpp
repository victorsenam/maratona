#include <bits/stdc++.h>
#define weigth first
#define vertex second
#define pb push_back
#define mp make_pair
#define mset(x,v) memset(x, v, sizeof(x));
typedef long long ll;
using namespace std;
 
vector<pair<int,int> > adj[1003];
bool seen[1003];
 
int prim (int src){
    set<pair<int,int> > s;
    set<pair<int,int> >::iterator it;
    int minCost = 0;
 
    s.insert(mp(0, src));
    while(s.size()){
        int v = s.begin()->vertex;
        int w = s.begin()->weigth;
        it = s.begin(); s.erase(it);
        if(seen[v]) continue;
         
        minCost += w;
        seen[v] = true;
         
        for(int i = 0; i < adj[v].size(); i++){
            int y = adj[v][i].vertex;
            if(!seen[y])
                s.insert(adj[v][i]);
        }
    }
 
    return minCost;
}
 
int main(){
    int t, p, n, m, a, b, c;
     
    scanf("%d", &t);
    while(t--){
        mset(seen, 0);
        scanf("%d %d %d", &p, &n, &m);
        for(int i = 0; i <= n; i++)
            adj[i].clear();
         
        while(m--){
            scanf("%d %d %d", &a, &b, &c);
            adj[a].pb(mp(c,b));
            adj[b].pb(mp(c,a));
        }
         
        int ans = p * prim(1);
        printf("%d\n", ans);
    }
 
} 
