#include <bits/stdc++.h>
using namespace std;

int n, v[20];
int memo[35000][2];

int dp(int bit, int s){
    if(bit == 0) return 0;
    int &k = memo[bit][s];
    if(k != -1) return k;
    k = INT_MAX;
    if(s == 0){
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(bit&(1<<i) && bit&(1<<j)) k = min(k, max(v[i],v[j]) + dp(bit^((1<<i)|(1<<j)),1) );
    }
    else {
        for(int i = 0; i < n; i++)
            if(!(bit&(1<<i))) k = min(k,v[i] + dp(bit|(1<<i),0));
    }
    return k;
}

int main(){
    memset(memo, -1, sizeof memo);
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d",v+i);
    printf("%d\n",dp((1<<n)-1,0));
}
