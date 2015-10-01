#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

struct triple {
    int a, b, c;
} v[N];

int t, n, bit[N];

void update(int idx, int val){
    for(int i = idx; i <= n; i += i&-i)
        bit[i] = min(bit[i],val);
}

int query(int idx){
    int q = INT_MAX;
    for(int i = idx; i > 0; i -= i&-i)
        q = min(bit[i],q);
    return q;
}

bool comp(triple x, triple y){ return x.a < y.a; }

int main(){
    
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0; i <= n; i++) bit[i] = INT_MAX;    
        for(int i = 0; i < n; i++)
            scanf("%d %d %d",&v[i].a,&v[i].b,&v[i].c);  
        sort(v,v+n,comp);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(query(v[i].b-1) > v[i].c) ans++;
            update(v[i].b,v[i].c);
        } 
        printf("%d\n",ans);
    }
}
