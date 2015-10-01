#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int m,n,k,vis[250], foo;
vector<int> adj[250];

void dfs(int no){
    if(vis[no]) return;
    vis[no] = 1;
    for(int i = 0; i < adj[no].size(); i++)
        dfs(adj[no][i]);
}

int main(){

    while(scanf("%d %d %d",&m,&n,&k) != EOF){
        for(int i = 0; i <= m+n; i++){
            adj[i].clear();
            vis[i] = 0;
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                scanf("%d",&foo);
                if(!foo){
                    adj[i].pb(m+j);
                    adj[m+j].pb(i);
                }
            }


        int ans = 0;
        for(int i = m; i < m+n; i++){
            if(!vis[i]){
                dfs(i);
                ans++;
            }
            if(!adj[i].size()){
                ans = 1234;
                break;
            }
        }
        if(ans <= k) printf("yes\n");
        else printf("no\n");
    }    

}
