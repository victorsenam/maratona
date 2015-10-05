#include <bits/stdc++.h>
using namespace std;
typedef long long num;
 
int main(){
    int n, v[25], pd[25];
 
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", v+i);
 
    v[0] = INT_MIN;
    for(int i = n; i >= 0; i--){
        pd[i] = 1;
        for(int j = i+1; j <= n; j++)
            if(v[j] > v[i] && pd[j] + 1 > pd[i])
                pd[i] = pd[j] + 1;
 
    }
    printf("%d\n", pd[0]-1);
} 