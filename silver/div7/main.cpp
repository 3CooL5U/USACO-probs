#include <bits/stdc++.h>
using namespace std;

ifstream fin("div7.in");
ofstream fout("div7.out");

long long N, id[50005], pref[50005];

int main(){
    fin >> N;
    for(int i = 0; i < N; i++)
        fin >> id[i];

    pref[0] = id[0];
    for(int i = 1; i < N; i++)
        pref[i] = id[i] + pref[i-1];

    int a, b, ans = 0;
    for(int mod = 1; mod < 7; mod++){
        a = N, b = 0;
        for(int i = 0 ; i < N; i++)
            if(pref[i] % 7 == mod){
                b = max(b, i);
                a = min(a, i);
            }
        ans = max(b-a, ans);
    }
    fout << ans;
}