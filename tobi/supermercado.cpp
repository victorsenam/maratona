/*--------------------------------------------------------*/
/* Problema: Supermercado (OBI 2003)                      */
/* Categoria: Ad-Hoc                                      */
/* Data: 18/08/2015                                       */
/*--------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int s, x[1003], y[1003], t = 1;

    while(scanf("%d", &s) && s != 0){
        for(int i = 0; i < s; i++)
            scanf("%d %d", &x[i], &y[i]);
        sort(x, x+s);
        sort(y, y+s);

        printf("Teste %d\n", t++);
        printf("%d %d\n\n", x[s/2], y[s/2]);
    }


}  