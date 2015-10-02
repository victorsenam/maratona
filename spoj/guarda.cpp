#include <cstdio>
#include <cmath>

int main(){
	int d,f,g;
	double t1,t2;
	while(scanf("%d %d %d",&d,&f,&g) != EOF){
		double t1, t2;
		t1 = (double) sqrt(d*d + 144)/g;
		t2 = (double) 12/f;
		if(t1 <= t2) puts("S");
		else puts("N");
	}
}
