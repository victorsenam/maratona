#include <bits/stdc++.h>
#define MAX 10004
using namespace std;
typedef long long num;
 
int n;
num bit[MAX];
 
num query(int idx){
    num sum = 0;
    for(int i = idx; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}
 
void update(int idx, int val){
    for(int i = idx; i <= n; i += i & -i)
        bit[i] += val;
}
 
int main(){
    int u, q, a, b, t, x;
 
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &u);
        for(int i = 0; i <= n; i++)
            bit[i] = 0;
        while(u--){
            scanf("%d %d %d", &a, &b, &x);
            update(a+1,x);
            update(b+2, -x);
        }
        scanf("%d", &q);
        while(q--){
            scanf("%d", &x);
            printf("%lld\n", query(x+1));
        }
    }
} 