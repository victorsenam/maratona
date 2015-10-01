#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<pii> f(int n, int k){
	if(n == 0) return vector<pii>();
	if(!(n&1)) return f(n/2, k+1);

	long long foo = 1;
	int pow = -1;

	while(foo <= n){
		foo *= 3;
		pow++;
	}
	foo /= 3;

	pii p(k, pow);
	vector<pii> ans = f(n-foo, k);
	ans.push_back(p);
	
	return ans;
}

int main(){
	int c, n;

	scanf("%d", &c);
	for(int t = 1; t <= c; t++){
		scanf("%d", &n);
		vector<pii> ans = f(n,0);
		printf("%d %d", t, (int)ans.size());
		for(int i = 0; i < ans.size(); i++)
			printf(" [%d, %d]", ans[i].first, ans[i].second);
		printf("\n");
	}
}
