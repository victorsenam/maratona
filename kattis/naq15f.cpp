#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, f[256];
    char s[256];

    scanf("%d", &n);
    while(n--){
        scanf(" %[^\n]", s);
        memset(f, 0, sizeof f);
        for(int i = 0; s[i] != '\0'; i++){
            s[i] = tolower(s[i]);
            if(isalpha(s[i]))
                f[s[i]-'a']++;
        }
        bool p = true;
        for(int i = 0; i < 26; i++)
            if(!f[i])
                p = false;

        if(p) printf("pangram\n");
        else {
            printf("missing ");
            for(int i = 0; i < 26; i++)
                if(!f[i]) printf("%c", i+'a');
            printf("\n");
        }
    }
}
