/*--------------------------------------------------------*/
/* Problema: Arjit and Printing Press                     */
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
	int t;

	scan(t);
	while(t--){
		string w, r;
		cin >> w >> r;

		sort(r.begin(), r.end());

		int j = 0;

		for(int i = 0; i < w.length() && j < r.length(); i++){
			if(r[j] < w[i]){
				w[i] = r[j];
				j++;
			}
		}

		cout << w << endl;

	}

}
