#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define mset(x,v) memset(x, v, sizeof(x))
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main(){
    int nota[4] = {50, 10, 5, 1};
    int used[4];
    int n, ans, t = 0;

    while(scanf("%d", &n) && n != 0){
        ans = 0; t++;
        mset(used, 0);
        for(int i = 0; i < 4; i++){
            used[i] += n/nota[i];
            if(used[i] != 0) n -= used[i]*nota[i];
        }

        printf("Teste %d\n", t);
        for(int i = 0; i < 4; i++)
            printf("%d ", used[i]);
        printf("\n\n");
    }

}
