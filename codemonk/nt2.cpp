#include <bits/stdc++.h>
#define MAX 10000007
using namespace std;

int primes[MAX];

void sieve(){
	for(int i = 2; i * i < MAX; i++){
		if(!primes[i])
			for(int j = i*i; j < MAX; j += i)
				primes[j] = i;
	}	
}

bool check(int x){
	int sq = sqrt(x);
	if(!primes[x] || x == 1) return 1;
	if(sq*sq == x && !primes[sq]) return 1;
	return 0;
}

int main(){
	int n, x;
	
	sieve();
	scanf("%d", &n);
	while(n--){
		scanf("%d", &x);
		bool ans = check(x);
		printf("%s\n", (ans == false) ? "YES" : "NO");
	}
}
