#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, in[100005];

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    int cont = 1, ant, atual;
    ant = 0;
    for(int i = 1; i < n; i++){
        if(in[i] - in[i-1] != in[ant+1] - in[ant]){
            cont++;
            ant = i;
            i++;
        }

    }

    printf("%d\n", cont);
}  