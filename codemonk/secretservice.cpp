#include <bits/stdc++.h>
using namespace std;
#define n N
int T,N,M,X,Y,C,S,A,H;

long long d[104][104];

void solve(int n){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];		
}

int main(){
	
	scanf("%d", &T);
	while(T--){
		for(int i = 1; i < 103; i++)
			for(int j = 1; j < 103; j++){
				if(j == i) d[i][j] = 0;
				else d[i][j] = INT_MAX;
			}

		scanf("%d %d", &N, &M);
		for(int i = 0; i < M; i++){
			scanf("%d %d %d", &X, &Y, &C);
			if(d[X][Y] > C){
				d[X][Y] = C;
				d[Y][X] = C;
			}
		}
		scanf("%d %d %d", &S, &A, &H);
		solve(n);
		long long  ans = 0;
		for(int i = 1; i <= n; i++)
			if(i != H && i != S && i != A)
				ans = max(ans, (d[S][i] + 2*(d[i][A]) + d[i][H]));
		printf("%lld\n", ans);
	}
}
