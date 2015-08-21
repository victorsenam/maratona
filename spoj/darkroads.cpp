#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define first weigth
#define second vertex
#define mset(x,v) memset(x, v, sizeof(x));
typedef long long ll;
using namespace std;
 
vector<pair<int,int> > adj[200005];
bool seen[200005];
 
ll prim(int source){
    set<pair<int,int> > s;
    set<pair<int,int> >::iterator it;
    ll minCost = 0;
 
    s.insert(mp(0, source));
    while(s.size()){
        //Escolhe a aresta de menor peso
        int x = s.begin()->vertex;
        int w = s.begin()->weigth;
        it = s.begin(); s.erase(it);
         
        if(seen[x]) continue;
         
        minCost += w;
        seen[x] = true;
         
        for(int i = 0; i < adj[x].size(); i++){
            int y = adj[x][i].vertex;
            if(!seen[y])
                s.insert(adj[x][i]);
        }
    }
    
    return minCost;
}
 
int main(){
    int m, n, x, y, z;
    ll ini;
     
    while(scanf("%d %d", &m, &n) && m != 0){
        ini = 0;
        mset(seen, 0);
         
        for(int i = 0; i <= n; i++)
            adj[i].clear();
             
        while(n--){
            scanf("%d %d %d", &x, &y, &z);
            ini += z;
            adj[x].pb(mp(z,y));
            adj[y].pb(mp(z,x));
        }
         
        ll ans = ini - prim(1);
        printf("%lld\n", ans);
    }
 
} 
