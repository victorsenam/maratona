#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int p[MAX], sz[MAX], maxi;
multiset<int> sizes;

int find(int a){
	if(p[p[a]] != p[a]) p[a] = find(p[a]);
	return p[a];
}

void join(int a, int b){
	if(sz[a] < sz[b]) swap(a,b);
	sz[a] += sz[b];
	sizes.insert(sz[a]);
	if(sz[a] > maxi) maxi = sz[a];
	p[b] = a;
}

int main(){
	int n, q, a, b;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++){
		p[i] = i;
		sz[i] = 1;
		sizes.insert(1);
	}
	maxi = 1;
	while(q--){
		scanf("%d %d", &a, &b);
		int x = find(a);
		int v = find(b);
		if(x == v)
			printf("%d\n", maxi-*(sizes.begin()));
		else {
			sizes.erase(sizes.find(sz[x]));
			sizes.erase(sizes.find(sz[v]));
			join(x,v);
			printf("%d\n", maxi-*(sizes.begin()));
		}
		
	}
}
