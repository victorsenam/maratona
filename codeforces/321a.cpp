#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, in[100005], max;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &in[i]);
	int ans = max = 1;
	for(int i = 0; i < n-1; i++){
		if(in[i+1] >= in[i]){
		   	ans++;
			if(ans > max) max = ans;
		}
		else ans = 1;
	}
	printf("%d\n", max);
}
