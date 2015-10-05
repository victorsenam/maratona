#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
pii v[45];
int n;
ll memo[850][850][45][2];

ll dp(int x, int y, int i, int f){
    if(i == n){
        if(x == 410 && y == x && f)  return 1;
        else return 0;
    }
    ll &k = memo[x][y][i][f];
    if(k != -1) return k;
    return k = dp(x+v[i].ff,y+v[i].ss,i+1,f|1) + dp(x,y,i+1,f);
}

int main(){
    memset(memo,-1,sizeof memo);
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d %d",&v[i].ff,&v[i].ss);
    printf("%lld\n",dp(410,410,0,0));
}
