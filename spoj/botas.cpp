#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int v[150];
int n,m;
char l;

int p(char l){
	if(l == 'D') return 60;
	return 0;
}


int main(){
	while(scanf("%d",&n) != EOF){
		memset(v,0,sizeof v);
		for(int i = 0; i < n; i++){
			scanf("%d %c",&m,&l);
			v[m+p(l)]++;
		}
		int ans = 0;
		for(int i = 30; i <= 60; i++)
			ans += min(v[i],v[i+60]);
		printf("%d\n",ans);
	}
}

