/*--------------------------------------------------------*/
/* Problema: Escada Rolante (OBI 2010)                    */
/* Categoria: Ad-Hoc                                      */
/* Data: 18/08/2015                                       */
/*--------------------------------------------------------*/

#include <bits/stdc++.h>

int main(){
    int n, t;

    scanf("%d", &n);

    int total = 0, timer = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &t);
        if(t >= timer)
            total += 10;
        else
            total += t + 10 - timer;

        timer = t + 10;
    }

    printf("%d\n", total);
}  