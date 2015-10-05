#include <bits/stdc++.h>
using namespace std;


int qd[10004];
char m[105][105];

int calc(){
    int i;
    for(i = 1; i*i <= 10000; i++)
        qd[i] = i*i;
    return i-1;
}


int main() {
    int n;
    char s[10004];
    int k = calc();
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf(" %s",s);
        int x = strlen(s);
        int lo = 1, hi = k;
        while(lo != hi){
            int mid = (lo+hi)/2;
            if(qd[mid] >= x) hi = mid;
            else lo = mid+1;
        }
        int k = 0;
        for(int i = 0; i < lo; i++){
            for(int j = 0; j < lo; j++){
                if(k < x) m[i][j] = s[k++];
                else m[i][j] = '*';
            }
        }
        for(int j = 0; j < lo; j++)
            for(int i = lo-1; i >= 0; i--)
                if(m[i][j] != '*') printf("%c",m[i][j]);
        printf("\n");
        
    }    
}
