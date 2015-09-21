#include <bits/stdc++.h>
#define vertex second
#define weight first
using namespace std;
typedef pair<int,int> pii;

vector<pii> adj[10004];
int temp[10004];

void solve(int fim){
	set<pii> pq;
	temp[1] = 0;
	pq.insert(make_pair(0,1));
	while(pq.size()){
		int x = pq.begin()->vertex;
		pq.erase(pq.begin());
		for(int i = 0; i < adj[x].size(); i++){
			pii nxt = adj[x][i];
			if(temp[nxt.vertex] > temp[x] + nxt.weight){
				temp[nxt.vertex] = temp[x] + nxt.weight;
				pq.insert(make_pair(temp[nxt.vertex], nxt.vertex));
			}
		}
	}
}

int main(){
	int t, a, n, m, x, y, c, k, q;

	scanf("%d", &t);
	while(t--){
		int d[10004];
		for(int i = 0; i < 10004; i++){
			adj[i].clear();
			temp[i] = INT_MAX;
		}
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &x, &y, &c);
			adj[x].push_back(make_pair(c,y));
			adj[y].push_back(make_pair(c,x));
		}
		scanf("%d", &q);
		for(int i = 2; i <= n; i++){
			solve(i);
			d[i] = temp[i];
		}

		while(q--){
			scanf("%d %d", &a, &k);
			int ans = k - (2 * d[a]);
			if(ans < 0) ans = 0;
			printf("%d\n", ans);
		}
	}
}
