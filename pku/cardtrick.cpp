#include <iostream>
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int main(){
    int n, aux, cartas[16][2], i, j, k;
    int t;
    
    cin >> t;
    for(int p = 0; p < t; p++){
        scanf("%d", &n); 
        aux = n;
    
    
    
        for(i = 0; i <= 15; i++)
            cartas[i][0] = i;
    
        for(i = 1; i <= n; i++){
            for(j = i; j > 0; j--){
                cartas[0][0] = cartas[1][0];
            
                for(k = 2; k <= aux; k++)
                    cartas[k-1][0] = cartas[k][0];
            
                cartas[k-1][0] = cartas[0][0];
            }
        
            cartas[cartas[1][0]][1] = i;
            for(k = 2; k <= aux; k++)
                cartas[k-1][0] = cartas[k][0];
        
            aux--;
            
        }
    
        for(i = 1; i <= n; i++)
            printf("%d ", cartas[i][1]);
        
        printf("\n");
    }
        
}
