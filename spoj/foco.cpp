#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<pii> seg;

int main(){
	int n, a, b;

	while(scanf("%d", &n) != EOF){
		seg.clear();
		for(int i = 0; i < n; i++){
			scanf("%d %d", &a, &b);
			seg.push_back(pii(b,a));
		}
		sort(seg.begin(), seg.end());
		int cont = 0;
		int x = -1;
		for(int i = 0; i < n; i++){
			if(seg[i].second > x){
				cont++;
				x = seg[i].first;
			}
		}
		printf("%d\n", cont);
	}

}
