#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
using namespace std;

const int MAXN = 105;
typedef pair<int,int> pii;

char mapa[MAXN][MAXN];
int let[256];
int d[MAXN][MAXN], bit;
int mx[4] = {0, 0, -1, 1};
int my[4] = {1, -1, 0, 0};

int bfs(pii ini, pii fim){
	queue<pii> q;
	d[ini.x][ini.y] = 1;
	q.push(ini);

	while(q.size()){
		pii v = q.front();
		q.pop();
		if(v == fim) return d[fim.x][fim.y];

		for(int i = 0; i < 4; i++){
			int nx = v.x+mx[i];
			int ny = v.y+my[i];
			if(d[nx][ny] > d[v.x][v.y] + 1){
				bool ok = (bit & (1<<let[mapa[nx][ny]])) != 0;
				if(ok == (!!isupper(mapa[nx][ny]))){
					d[nx][ny] = d[v.x][v.y] + 1;
					q.push(mp(nx,ny));
				}

			}
		}		
	}

	return INT_MAX;
}

int main(){
	int n;

	for(int i = 'A'; i <= 'J'; i++)
		let[i] = i - 'A';

	for(int i = 'a'; i <= 'j'; i++)
		let[i] = i - 'a';


	while(scanf("%d", &n) != EOF){
		for(int i = 0; i <= n+1; i++)
			for(int j = 0; j <= n+1; j++)
				d[i][j] = -1;
	
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				scanf(" %c", &mapa[i][j]);
				


		int ans = INT_MAX;
		pii ini = mp(1,1);
		pii fim = mp(n, n);
		for(bit = 0; bit < 1024; bit++){
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++){
					d[i][j] = INT_MAX;
				}
			if(!!(bit & (1<<let[mapa[1][1]])) == !!isupper(mapa[1][1]))
				ans = min(ans, bfs(ini,fim));
		}

		if(ans == INT_MAX) printf("-1\n");
		else printf("%d\n", ans);
	}

}
