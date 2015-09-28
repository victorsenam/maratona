#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n;

void update(int bit[], int x, int v){
	for(int i = x; i <= n; i += i & -i){
		bit[i] += v;
	}
}

int query(int bit[], int x){
	int sum = 0;
	for(int i = x; i > 0; i -= i & -i){
		sum += bit[i];
	}
	return sum;
}
int main(){
	int bitneg[100005], bitzero[100005];
	int k, x, a, b;
	char c;

	while(scanf("%d %d", &n, &k) != EOF){
		for(int i = 0; i <= n; i++){
			bitneg[i] = 0;
			bitzero[i] = 0;
		}
		for(int i = 1; i <= n; i++){
			scanf("%d", &x);
			if(x < 0) update(bitneg,i,1);
			else if(x == 0)	update(bitzero,i,1);
		}
		int ans;
		for(int i = 0; i < k; i++){
			scanf(" %c %d %d", &c, &a, &b);
			if(c == 'C'){
				if(query(bitzero,a)-query(bitzero,a-1))
					update(bitzero,a,-1);
				if(query(bitneg,a)-query(bitneg,a-1))
					update(bitneg,a,-1);
				if(b < 0) update(bitneg,a,1);
				else if(b == 0)
					update(bitzero,a,1);
			}
			if(c == 'P'){
				ans = query(bitneg,b) - query(bitneg,a-1);
				int z = query(bitzero,b) - query(bitzero,a-1);
				if(z != 0) printf("0");
				else if(ans%2) printf("-");
				else printf("+");

			}
		}
		printf("\n");
	}
}
