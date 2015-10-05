#include <bits/stdc++.h>
using namespace std;

int memo[15][15];

int comb(int n, int k){
    if(k == n || k == 0) return 1;
    if(k == 1) return n;
    if(n == 0) return 0;
    int &me = memo[n][k];
    if(me != -1) return me;
    return me = comb(n-1,k) + comb(n-1,k-1);
}

int main(){
    memset(memo,-1, sizeof memo);
    int n;
    scanf("%d",&n);
    int r,s,x,y,w;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d %d",&r,&s,&x,&y,&w);
        double esp = 0;
        double p = (double) (s-r+1)/s;
        for(int i = x; i <= y; i++){
            esp += (double) comb(y,i)*pow(p,i)*pow(1-p,y-i);
        }
        if( (double) esp*w > 1.0) puts("yes");
        else puts("no");
    }
}
