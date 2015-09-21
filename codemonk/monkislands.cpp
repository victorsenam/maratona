#include <bits/stdc++.h>
using namespace std;

const int MAX = 10004;

vector<int> adj[MAX];
int d[MAX];

int main(){
	int t, n, m, x, y;

	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++){
			d[i] = -1;
			adj[i].clear();
		}
		for(int i = 0; i < m; i++){
			scanf("%d %d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		d[1] = 0;
		queue<int> q;
		q.push(1);
		while(q.size()){
			int v = q.front();
			q.pop();
			for(int i = 0 ; i < adj[v].size(); i++){
				int x = adj[v][i];
				if(d[x] == -1){
					d[x] = d[v] + 1;
					q.push(x);
				}
			}
				
		}

		printf("%d\n", d[n]);
	}
}
