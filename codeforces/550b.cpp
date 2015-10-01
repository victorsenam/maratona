#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l, r, x;
    int in[20];

    scanf("%d %d %d %d", &n, &l, &r, &x);
    for(int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    sort(in, in+n);

    int cont = 0;
    for(int bit = 0; bit < (1<<n); bit++){
        int sum = 0, np = 0;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            if((bit & (1<<i))){
                if(in[i] < mini) mini = in[i];
                if(in[i] > maxi) maxi = in[i];
                sum += in[i];
                np++;
            }
        }
        if(sum >= l && sum <= r && np > 1)
            if((maxi - mini) >= x)
                cont++;
    }

    printf("%d\n", cont);
}