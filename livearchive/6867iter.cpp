#include <bits/stdc++.h>
using namespace std;

int n, w, k;
int p[59][110], s[59][110], q[59];
int pd[310][59];

int solve(){
    memset(pd,0,sizeof pd);

    for(int i = 0; i <= w; i++){
        for(int j = 1; j <= n; j++){
            pd[j][i] = max( pd[j][i] , pd[j-1][i] );
            for(int k = 0; k < q[i]; k++){
                int a = min( j , s[i][k] );
                int s = (i > 0) ? pd[j-a][i-1] : 0;
                pd[j][i] = max( pd[j-a][i-1] + p[i][k] * a, pd[j][i] );
            }
        }
    }

    return pd[n][w];
}

int main(){

    while(scanf("%d %d", &n, &w) != EOF){
        for(int i = w; i >= 0; i--){
            scanf("%d", &k);
            q[i] = k;
            for(int j = 0; j < k; j++)
                scanf("%d", &p[i][j]);
            for(int j = 0; j < k; j++)
                scanf("%d", &s[i][j]);
        }
        int ans = solve();
        printf("%d\n", ans);
        int bt = INT_MAX;
        for(int i = 0; i < q[w]; i++){
            int a = min( n, s[w][i] );
            if(p[w][i] * a + pd[n-a][w-1] == ans)
                bt = min( bt, p[w][i] );
        }
        printf("%d\n", bt);
    }
}