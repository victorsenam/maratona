#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

vector<int> adj[MAX];
int cat[MAX], s[MAX];
int ans = 0, soma = 0, m;

void dfs(int v, int c){
	s[v] = 1;
	if(c > m) return;
	if(!cat[v]) c = 0;
	if(adj[v].size() == 1 && v != 1) ans++;
	for(int i = 0; i < adj[v].size(); i++){
		if(!s[adj[v][i]])
			dfs(adj[v][i], c + cat[adj[v][i]]);
	}
}

int main(){
	int n, a, b;

	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &cat[i]);
	for(int i = 1; i <= n; i++)
		s[i] = 0;
	for(int i = 1; i < n; i++){
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, cat[1]);

	printf("%d\n", ans);
}
