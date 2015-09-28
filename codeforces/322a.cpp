#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	
	scanf("%d %d", &a, &b);
	printf("%d %d\n", min(a,b), max((a-min(a,b))/2, ((b-min(a,b))/2)));	
}
