/*
   		Jogo de Estratégia - Problema J
	Maratona de Programação da SBC - ACM ICPC 2015
													  */

#include <bits/stdc++.h>
using namespace std;

int main(){
	int j, r, a, p[505];

	while(scanf("%d %d", &j, &r) != EOF){
		for(int i = 0; i < 505; i++)
			p[i] = 0;
		for(int i = 0; i < j*r; i++){
			scanf("%d", &a);
			p[i%j] += a;
		}

		int ans;
		int p0 = INT_MIN;
		for(int i = 0; i < j; i++){
			if(p[i] >= p0){
				p0 = p[i];
				ans = i;
			}
		}

		printf("%d\n", ans+1);
	}
}

