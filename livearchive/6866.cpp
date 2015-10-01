#include <bits/stdc++.h>
using namespace std;

int t, cour, ano, mes, dia, biano, bimes, bidia;
char nome[50];

int main () {
    scanf ("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf (" %s %d/%d/%d %d/%d/%d %d", nome, &ano, &mes, &dia, &biano, &bimes, &bidia, &cour); 
        bool f = false;
        if (ano >= 2010)
            f = true;
        else if (biano >= 1991)
            f = true;
        if (!f && cour < 41) {
            printf ("%s coach petitions\n", nome);
            continue;
        }
        if (f)
            printf ("%s eligible\n", nome);
        else 
            printf ("%s ineligible\n", nome);         
    }
}
