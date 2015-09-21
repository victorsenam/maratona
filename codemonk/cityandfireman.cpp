#include <bits/stdc++.h>
#define MAXN 1003
#define MOD 1000000007
using namespace std;

int e[MAXN], sz[MAXN], p[MAXN], minR[MAXN];

int find(int a){
	if(p[p[a]] != p[a]) p[a] = find(p[a]);
	return p[a];
}

void join(int a, int b){
	int x = find(a);
	int v = find(b);

	if(x == v) return;
	if(sz[x] < sz[v]) swap(x,v);
	sz[x] += sz[v];
	p[v] = x;
	minR[x] = min(minR[v], minR[x]);
}

int main(){
	int n, k, a, b;

	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &e[i]);
		minR[i] = e[i];
		p[i] = i;
		sz[i] = 1;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d %d", &a, &b);
		join(a,b);
	}
	int ans = 1;
	for(int i = 1; i <= n; i++){
		int cont = 0;
		int j = find(i);
		if(minR[j] == -1) continue;
		for(int k = i; k <= n; k++){
            int pk = find(k);
			if(e[k] == minR[j] && pk == j)
				cont++;
		}
		minR[j] = -1;
		ans = (ans * cont)%MOD;
	}
	printf("%d\n", ans);
}