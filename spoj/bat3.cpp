#include <bits/stdc++.h>
using namespace std;
typedef long long num;
typedef pair<int,int> pii;
 
const int MAX = 1003;
 
int main(){
    int t, n, m, v[MAX], pd[MAX];
 
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        for(int i = n-1; i >= 0; i--){
            pd[i] = 1;
            if(i == m)
                for(int j = i + 1; j < n; j++)
                    pd[i] = max(pd[i], 1 + pd[j]);
            else
                for(int j = i+1; j < n; j++)
                    if(v[j] < v[i])
                        pd[i] = max(pd[i], 1 + pd[j]);
        }
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++)
            if(pd[i] > maxi)
                maxi = pd[i];
        printf("%d\n", maxi);
    }
} 