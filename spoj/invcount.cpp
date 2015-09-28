#include <bits/stdc++.h>
#define MAX 200005
using namespace std;
typedef long long num;
 
num n, bit[MAX], a[MAX], b[MAX];
 
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
    int t;
 
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i <= n; i++){
            bit[i] = 0;
            a[i] = 0;
            b[i] = 0;
        }
        for(int i = 0; i < n; i++){
            scanf("%d", a+i);
            b[i] = a[i];
        }
        sort(b,b+n);
        for(int i = 0; i < n; i++){
            int idx = int(lower_bound(b,b+n,a[i]) - b);
            a[i] = idx + 1;
        }
        num inv = 0;
        for(int i = n-1; i >= 0; i--){
            inv += query(a[i]-1);
            update(a[i],1);
        }
        printf("%lld\n", inv);
    }
} 