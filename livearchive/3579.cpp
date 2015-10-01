#include <bits/stdc++.h>
#define MAX 505

using namespace std;

int t, n, pos, v[MAX], ans[MAX];

int main () {
    while (scanf ("%d", &t) && t != 0) {
        for (int i = 0; i < t; i++) 
            scanf ("%d", &v[i]);
        int tam = 0;
        for (int i = t - 1; i >= 0; i--) {
            pos = v[i];
            for (int j = tam; j >= pos; j--)
                ans[j+1] = ans[j];
            ans[pos] = i + 1;
            tam++;
        }
        for (int i = 0; i < t; i++) 
            printf ("%d%c", ans[i],i == t-1 ? '\n' : ',');
    }
}
