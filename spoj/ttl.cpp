/*--------------------------------------------------------*/
/* Problema: Time to Live (GCPC11J)                       */
/* Categoria: Graphs                                       */
/* Data: 12/08/2015                                       */
/*--------------------------------------------------------*/

#include <bits/stdc++.h>
#define pb push_back
#define mset(x,v) memset(x, v, sizeof(x))
const int MAXN = 100005;
 
using namespace std;
 
vector<int> adj[MAXN];
int d[MAXN], t, f;
 
void bfs(int v){
	f = 0;
	d[v] = 0;
	queue<int> q;
	q.push(v);
 
	while(q.size()){
		v = q.front();
		q.pop();
		for(int i = 0; i < adj[v].size(); i++){
			int child = adj[v][i];
			if(d[child] == -1){
				d[child] = d[v] + 1;
				if(d[child] >= f){
					t = child;
					f = d[child];
				}
				q.push(child);
			}
		}
	}
}
 
int main(){
	int c, n, a, b;
 
	scanf("%d", &c);
	while(c--){
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++)
			adj[i].clear();
 
		for(int i = 0; i < n-1; i++){
			scanf("%d %d", &a, &b);
			adj[a].pb(b);
			adj[b].pb(a);
		}
 
		mset(d, -1);
		bfs(1);
		mset(d, -1);
		bfs(t);
 
		printf("%d\n", (f+1)/2);
	}
} 