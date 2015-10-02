#include <bits/stdc++.h>
using namespace std;
const int C = 1004;

int v[C];
int pl[100005];
int n,c,p,q;
char foo;

int main(){
	while(scanf("%d %d",&c,&n) != EOF) {
		memset(v,0,sizeof v);
		int ans = 0;
		for(int i = 0; i < n; i++){
			scanf(" %c",&foo); 
			if(foo == 'C'){
				scanf("%d %d",&p,&q);
				int i, j;
				i = j = 0;
				while(i < c){
					if(v[i] == 0){
						j = i;
						while(j < c && !v[j]) j++;
						if(j-i >= q) {
							v[i] = q, pl[p] = i;
							ans += 10;
							break;
						}
						else i = j;
					}
					i += v[i];
				}
			}
			else {
				scanf("%d",&p);
				v[pl[p]] = 0;
			}
		}
		printf("%d\n",ans);
	}
}
