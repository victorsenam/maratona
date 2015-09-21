#include <bits/stdc++.h>
using namespace std;

int p[100005], sz[100005];
set<int> ans;

int find(int i){
	if(p[p[i]] != p[i]) p[i] = find(p[i]);
	return p[i];
}

void join(int v, int x){
	int pv = find(v);
	int px = find(x);
	
	if(sz[pv] < sz[px]) swap(px,pv);
	sz[pv] += sz[px];
	p[px] = pv;	
}

int main(){
	int n, k, a, b;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		p[i] = i;
		sz[i] = 1;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d %d", &a, &b);
		join(a,b);
	}

	for(int i = 1; i <= n; i++){
		int j = find(i);
		ans.insert(j);
	}
	printf("%d\n", ans.size());		
}