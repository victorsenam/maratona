#include <bits/stdc++.h>
using namespace std;
typedef long long num;

const int MAX = 100005;

int main(){
    int n, m, x, in[MAX], s[MAX], b[MAX];

    scanf("%d %d", &n, &m);

    memset(s, 0, sizeof s);
    memset(b, 0, sizeof b);

    for(int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    for(int i = n-1; i >= 0; i--){
        b[i] = (!s[in[i]]) + b[i+1];
        s[in[i]] = 1;
    }

    for(int i = 0; i < m; i++){
        scanf("%d", &x);
        printf("%d\n", b[x-1]);
    }

}