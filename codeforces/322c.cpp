#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int main(){
	int n, k, a[MAX], r[MAX];

	scanf("%d %d", &n, &k)

	int sum = 0;
	for(int i = 0; i < n; i++){
	   	int n;
		scanf("%d", a+i);
		sum += a[i]/10;
		n = (a[i] + 9)/10;
		n *= 10;
		r[i] = n - a[i];
	}
	
	sort(r, r+n);
	for(int i = 0; i < n; i++){
		if(r[i] && r[i] <= k){
			k -= r[i];
			sum++;
		}			
	}
	sum += k/10;
	if(sum > n*10) sum = n*10;
	printf("%d\n", sum);

}
