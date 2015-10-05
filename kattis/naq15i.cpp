#include <bits/stdc++.h>
using namespace std;

char s[109];
char sm[] = "Simon says";

bool hue(){
    if(strlen(s) < 10) return false;
    for(int i = 0; i < 10; i++){
        if(s[i] != sm[i]) return false;
    }
    return true;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf(" %[^\n]",s);
        if(hue()) printf("%s\n",s+10);
    }
}
