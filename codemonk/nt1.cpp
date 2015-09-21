#include <bits/stdc++.h>
typedef long long ll;

int main(){
	ll a,b;
	char s[100005];

	scanf("%lld %lld", &a, &b);
	scanf(" %s", s);

	int l = strlen(s);
	ll ans = 0;
	for(int i = 0; i < l; i++){
		if(s[i] == '1')
			ans = (ans + a)%b;
		a = (a*a)%b;
	}
	printf("%lld\n", ans%b);