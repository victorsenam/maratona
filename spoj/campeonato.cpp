#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int,int> pii;
pii cd[15];
double d[15][15];
double memo[140][12][12][12];
char s[160];
int t;
int v[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int f[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

void plan(){
	cd[0] = pii(1,0);
	cd[10] = pii(2,0);
	for(int i = 1; i <= 9; i++)
		cd[i] = pii((i-1)%3, 3 - (i-1)/3);	
}

int qd(int a) { return a*a; }

int where(char c){
	if(c == ' ') return 0;
	c -= 'a';
	return f[c];
}

int qtd (char c){
	if(c == ' ') return 1;
	c -= 'a';
	return v[c];
}

double dp(int i, int dd, int de, int ult){
	if(i == t) return 0;
	double &k = memo[i][dd][de][ult];
	if(k != -1) return k;
	int go = where(s[i]);
	double ans;
	if(go == ult) ans = 0.2 + min(d[dd][10] + dp(i,10,de,11), d[de][10] + dp(i,dd,10,11));
	else {
		ans = 0.2*qtd(s[i]) + min(d[dd][go] + dp(i+1,go,de,go), d[de][go] + dp(i+1,dd,go,go));
	}
	return k = ans;
}

int main(){
	plan();
	for(int i = 0; i <= 10; i++)
		for(int j = 0; j <= 10; j++){
			d[i][j] = d[j][i] = sqrt(qd(cd[i].ff - cd[j].ff) + qd(cd[i].ss - cd[j].ss))/30;
		}

	while(scanf(" %[^\n]",s) != EOF){
		t = strlen(s);
		for(int i = 0; i < t; i++)
			for(int j = 0; j < 12; j++)
				for(int k = 0; k < 12; k++)
					for(int l = 0; l < 12; l++)
						memo[i][j][k][l] = -1;
		printf("%.2f\n",dp(0,6,4,11));
	}

	
}
