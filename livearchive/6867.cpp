#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p[59][110], s[59][110], q[59];
ll memo[310][59];


ll dp(ll n, ll w){
    if(n == 0 || w == 0) return memo[n][w]= 0;
    ll &k = memo[n][w];
    if(k != -1) return k;
    ll ans = 0;
    for(int i = 0; i < q[w]; i++)
        ans = max(ans,p[w][i] * min(n,s[w][i]) + dp(n-min(n,s[w][i]),w-1));
    return memo[n][w] = ans;
}

int main(){
    ll n,w,k;
    while(scanf("%lld %lld",&n,&w) != EOF){
        memset(memo,-1,sizeof memo);
        w++;
        for(int i = w; i > 0; i--){
            scanf("%lld",&k);
            q[i] = k;
            for(int j = 0; j < k; j++)
                scanf("%lld",&p[i][j]);
            for(int j = 0; j < k; j++)
                scanf("%lld",&s[i][j]);
        }
        ll ans = dp(n,w);
        printf("%lld\n",ans);
        ll fr = INT_MAX;
        for(int i = 0; i < q[w]; i++){
            if(p[w][i]*min(n,s[w][i]) + memo[n-min(n,s[w][i])][w-1] == ans)
                fr = min(fr,p[w][i]);
        }

        printf("%lld\n",fr);
    }
}
