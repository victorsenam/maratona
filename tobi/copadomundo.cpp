#include <bits/stdc++.h>
#define pb push_back
#define ss second
#define ff first
#define mp make_pair
#define all(x) x.begin(), x.end()
#define scan3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define mset(x,v) memset(x, v, sizeof x)
#define MOD 1e9+7
#define MAX 100005
typedef long long num;

using namespace std;

vector<char> v[5];

void cmp(int a, int b, int i, int j){
	if(a > b) v[i].pb(v[i-1][j]);
	else v[i].pb(v[i-1][j+1]);
}

int main(){
	int a, b;
	for(char c = 'A'; c <= 'P'; c++)
		v[0].pb(c);

	for(int i = 1; i <= 4; i++){

		for(int j = 0; j < v[i-1].size(); j += 2){
			cin >> a >> b;
			cmp(a,b,i,j);
		}
	}
	
	cout << v[4][0] << endl;

}
