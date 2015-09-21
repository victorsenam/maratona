#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1000001
using namespace std;

long long memo[MAXN];

int main(){
	int T, N;

	memo[0] = 1;
	memo[1] = 1;
	for(int i = 2; i <= MAXN; i++)
		memo[i] = (memo[i-1] + (i-1) * memo[i-2]) % MOD;

	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
        printf("%lld\n", memo[N]);
	}
}