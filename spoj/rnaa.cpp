#include <bits/stdc++.h>
using namespace std;
typedef long long num;
 
int main(){
    char str[305];
 
    while(scanf(" %s", str) != EOF){
        stack<char> s;
        int tam = strlen(str);
        int ans = 0;
        s.push(str[0]);
        for(int i = 1; i < tam; i++){
            char c = str[i];
            if(s.size() &&  (c == 'B' && s.top() == 'S' ||
                             c == 'S' && s.top() == 'B' ||
                             c == 'C' && s.top() == 'F' ||
                             c == 'F' && s.top() == 'C')){
                s.pop();
                ans++;
            }
            else s.push(str[i]);
        }
        printf("%d\n", ans);
    }
} 