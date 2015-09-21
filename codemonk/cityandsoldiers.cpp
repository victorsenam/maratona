#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int sz[MAX], p[MAX];

int find(int a){
	if(p[p[a]] != p[a]) p[a] = find(p[a]);
	return p[a];
}

void update(int a){
	int pa = find(a);
	p[a] = a;
	p[pa] = a;
	sz[a] = sz[pa];
}

void join(int a, int b){
	int pa = find(a);
	int pb = find(b);
	int l = pb;

	if(pa == pb) return;
	if(sz[pa] < sz[pb]) swap(pa,pb);
	sz[pa] += sz[pb];
	p[pb] = pa;
	update(l);	
}

int main(){
	int n, q, a, b, in;

	scanf("%d %d", &n, &q);
	for(int i = 0; i < MAX; i++){
		p[i] = i;
		sz[i] = 1;
	}
	while(q--){
		scanf("%d", &in);
		if(in == 1){
			scanf("%d %d", &a, &b);
			join(a,b);
		}
		if(in == 2){
			scanf("%d", &a);
			update(a);
		}
		if(in == 3){
			scanf("%d", &a);
			printf("%d\n", find(a));
		}
	}
}
