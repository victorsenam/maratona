#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y,z;

    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d %d", &x, &y, &z);

    int ans = (x/a)*(y/b)*(z/c);
    printf("%d\n", ans);
}