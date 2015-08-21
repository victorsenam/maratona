#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll memo[210][210], k;

ll solve(int n, int m){
    if(n == 0) return 1;
    if(m == 0) return 0;
    if(n < 0 || n < k || m < k) return 0;
    if(memo[n][m] == -1)
        memo[n][m] = solve(n, m-1) + solve(n-m, m);
    return memo[n][m];
}

int main(){
    int t, n;

    scanf("%d", &t);
    while(t--){
        memset(memo, -1, sizeof memo);
        scanf("%d %d", &n, &k);
        printf("%lld\n", solve(n, n));
    }
}
