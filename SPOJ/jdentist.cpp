/*--------------------------------------------------------*/
/* Problema: Dentista (OBI2010, Fase 2, Nível Júnior)     */
/* Categoria: Greedy                                      */
/* Data: 06/08/2015                                       */
/*--------------------------------------------------------*/


#include <bits/stdc++.h>
#define saida first
#define entrada second
#define pb push_back
#define mp make_pair
using namespace std;

int main(){
	int n, x, y;
	vector<pair<int,int> > h;

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &x, &y);
		h.pb(mp(y,x));
	}

	sort(h.begin(), h.end());

	int j = 0, ans = 1;
	for(int i = 1; i < n; i++){
		if(h[i].entrada >= h[j].saida){
			ans++;
			j = i;
		}
	}

	printf("%d\n", ans);

}
