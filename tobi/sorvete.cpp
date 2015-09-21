#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int p, s, x, y;
    pii atual;

    int t = 1;
    while(scanf("%d %d", &p, &s) && p != 0){
        vector<pii> in;
        printf("Teste %d\n", t);
        t++;
        for(int i = 0; i < s; i++){
            scanf("%d %d", &x, &y);
            in.push_back(make_pair(x,y));
        }

        sort(in.begin(), in.end());

        x = in.begin()->first;
        y = in.begin()->second;

        for(int i = 1; i < s; i++){
            atual = in[i];
            if(atual.first >= x  && atual.first <= y && atual.second > y)
                y = atual.second;
            if(atual.first > y){
                printf("%d %d\n", x, y);
                x = atual.first;
                y = atual.second;
            }
        }
        printf("%d %d\n", x, y);
        printf("\n");
    }
}  