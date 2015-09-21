#include <bits/stdc++.h>
using namespace std;

int N, T;
int cost[5][100005]; 
int dp[5][100005];
int solve(int j, int i){
	if(i == N) return 0;

	int &r = dp[j][i];
	if(r != -1) return r;
	r = INT_MAX;
	for(int k = 1; k <= 3; k++)
		if(k != j)
			r = min(r, solve(k,i+1) + cost[k][i]);

	return r;
}

int main(){
	scanf("%d", &T);
	while(T--){
		memset(dp, -1, sizeof dp);
		memset(cost, -1, sizeof cost);
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			scanf("%d %d %d", &cost[1][i], &cost[2][i], &cost[3][i]);
		}

		printf("%d\n", solve(4,0));
	}
}
