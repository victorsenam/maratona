/*--------------------------------------------------------*/
/* Problema: Little Jhool and his addiction! [2]          */
/* Categoria: Greedy                                      */
/* Data: 06/08/2015                                       */
/*--------------------------------------------------------*/


#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define mset(x,v) memset(x, v, sizeof(x))
#define scan(x) scanf("%d", &x)
#define scan2(x,y) scanf("%d %d", &x, &y)
#define scan3(x, y, z) scanf("%d %d %d", &x, &y, &z)
typedef long long ll;

using namespace std;

int main(){
	int t, m, n, k, lista[1000006];

	scan(t);
	while(t--){
		int ans;

		scan2(m, k); n = m/2;
		for(int i = 0; i < m; i++){
			scan(lista[i]);
		}

		sort(lista, lista+m);
		if(n != 1){
			int mini = INT_MAX, maxi = INT_MIN;
			int j = m-1;


			for(int i = 0; i < m/2; i++){
				int sum = lista[i] + lista[j];
				if(sum > maxi) maxi = sum;
                if(sum < mini) mini = sum;
				j--;
			}

            ans = maxi - mini;
		}

		else 
			ans = 0;

        printf("%d\n", ans);
		if(ans == k) printf("Lucky chap!\n");
		else if(ans > k) printf("No more girlfriends!\n");
		else printf("Chick magnet Jhool!\n");
	}

}
