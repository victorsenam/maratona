#include <bits/stdc++.h>
using namespace std;

struct pos {
	int x, y, z;
	pos(int a = 0, int b = 0, int c = 0){
		x = a; y = b; z = c;
	}
};

bool cmp(pos a, pos b){
	return (a.x == b.x && a.y == b.y && a.z == b.z);
}

int maze[40][40][40];
int x[6] = {0, 0, 0, 0, 1, -1};
int y[6] = {0, 0, 1, -1, 0, 0};
int z[6] = {1, -1, 0, 0, 0, 0};

int main(){
	int l, r, c;
	char in;
	pos p, fim, prox;

	while(scanf("%d %d %d", &l, &r, &c) && r != 0){
		memset(maze, -1, sizeof maze);
		for(int i = 1; i <= l; i++){
			for(int j = 1; j <= r; j++){
				for(int k = 1; k <= c; k++){
					scanf(" %c", &in);
					if(in == 'S'){
						p = pos(j,k,i);
						maze[j][k][i] = 0;
					}
					else if(in == 'E'){
						fim = pos(j,k,i);
						maze[j][k][i] = INT_MAX;
					}
	
					else if(in != '#')
						maze[j][k][i] = INT_MAX;
				}
			}
		}

		queue<pos> q;
		q.push(p);
		while(q.size()){
			p = q.front();
			q.pop();
			if(cmp(p,fim)) break;
			for(int i = 0; i < 6; i++){
				int nx = p.x + x[i];
				int ny = p.y + y[i];
				int nz = p.z + z[i];
				if(maze[nx][ny][nz] > maze[p.x][p.y][p.z] + 1){
					maze[nx][ny][nz] = maze[p.x][p.y][p.z] + 1;
					prox = pos(nx, ny, nz);
					q.push(prox);
				}
			}
		}
		
		if(maze[fim.x][fim.y][fim.z] != INT_MAX)
			printf("Escaped in %d minute(s).\n", maze[fim.x][fim.y][fim.z]);
		else
			printf("Trapped!\n");

	}

}
