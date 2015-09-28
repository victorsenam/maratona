#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int main(){
	int n, h[MAX], ans[MAX];

	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", h+i);

	int maxh = 0;
	for(int i = n-1; i >= 0; i--){
		if(h[i] > maxh) ans[i] = 0;
		else ans[i] = 1 + maxh - h[i];
		maxh = max(maxh, h[i]);

	}	
	for(int i = 0; i < n; i++)
		printf("%d ", ans[i]);
}
