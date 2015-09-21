#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long num;

num gcd(int a, int b){
	if(!b) return a;
	return gcd(b, a%b);
}

num modexp(num f, num g){
	num ans = 1;
	while(g){
        if(g%2) ans = (ans * f)%MOD;
        f = (f*f)%MOD;
        g /= 2;
	}
	return ans;
}

int main(){
    num n, a, g, f, in[55];
    scanf("%lld", &n);

    for(int i = 0; i < n; i++)
    	scanf("%lld", &in[i]);

    g = in[0]; f = in[0];

    for(int i = 1; i < n; i++)
    	g = gcd(g, in[i]);
    for(int i = 1; i < n; i++)
    	f = (f * in[i])%MOD;
    
    printf("%lld\n", modexp(f,g));

    return 0;
}