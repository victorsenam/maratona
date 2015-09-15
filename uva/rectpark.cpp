/*
   		Praça dos Retângulos - Problema H
	Maratona de Programação da SBC - ACM ICPC 2015
													  */

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
	int n, a, b;

	while(scanf("%d", &n) != EOF){
		vector<pii> p;

		for(int i = 0; i < n; i++){
			scanf("%d %d", &a, &b);
			p.push_back(make_pair(a,b));
		}
		sort(p.begin(), p.begin()+n);
		int ans = 0;
		for(int i = 0; i < n; i++){
			int maxi = INT_MAX;
			int mini = INT_MIN;
			for(int j = i-1; j >= 0; j--){
				if(p[j].second < p[i].second && p[j].second >= mini){
					ans++;
					mini = p[j].second;
				}
				if(p[j].second > p[i].second && p[j].second <= maxi){
					ans++;
						maxi = p[j].second;
				}
			
			}
		}
		printf("%d\n", ans);
	}

}
