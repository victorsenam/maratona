#include <bits/stdc++.h>
#define MAX 500005
using namespace std;
typedef long long num;

struct lady {
    int x, y, z;
} in[MAX];

bool operator < (lady a, lady b){
    if(a.x != b.x)
        return a.x < b.x;
    return a.y > b.y;
}

int bit[MAX], n;

int query(int i){
    int maxi = -1;
    for(; i > 0; i -= i & -i)
        maxi = max(bit[i], maxi);
    return maxi;
}

void update(int i, int val){
    for(; i <= n; i += i & -i)
        bit[i] = max(bit[i], val);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &in[i].x);
    for(int i = 0; i < n; i++) scanf("%d", &in[i].y);
    for(int i = 0; i < n; i++) scanf("%d", &in[i].z);

    for(int i = 0; i < n; i++) bit[i] = in[i].y;
    sort(bit, bit+n);
    sort(in, in+n);

    for(int i = 0; i < n; i++)
        in[i].y = n - (lower_bound(bit,bit+n,in[i].y)-bit);

    memset(bit, -1, sizeof bit);

    int ans = 0;
    for(int i = n-1; i >= 0; i--){
        int maxiz = query(in[i].y-1);
        if(maxiz > in[i].z)
            ans++;
        update(in[i].y, in[i].z);
    }
    printf("%d\n", ans);
}