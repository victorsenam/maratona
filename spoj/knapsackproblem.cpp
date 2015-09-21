#include <bits/stdc++.h>
using namespace std;
 
int S, N;
int s[2003], v[2003];
int pd[2003][2003];
 
int solve(int size, int i){
	if(size > S) return INT_MIN;
	if(i == N) return 0;
 
	if(pd[size][i] != -1) return pd[size][i];
	pd[size][i] = max(solve(size+s[i], i+1)+v[i], solve(size, i+1)); 
	return pd[size][i];
}
 
int main(){
 
	scanf("%d %d", &S, &N);
	memset(pd, -1, sizeof pd);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &s[i], &v[i]);
	}
 
	int ans = solve(0,0);
	printf("%d\n", ans);
}