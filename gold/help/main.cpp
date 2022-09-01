#include <bits/stdc++.h>
using namespace std;

ifstream fin("help.in");
ofstream fout("help.out");

const int MOD = 1e9+7;

int N, pref[100005 * 2];
long long powers[100005 * 2];

int main() {
    fin >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        fin >> a >> b;
        pref[a]++;
        pref[b]--;
    }

    powers[0] = 1;
    for(int i = 1; i < N; i++)
        powers[i] = powers[i-1] * 2 % MOD;

    int current = 0;
    long long ans = 0;
    for(int i = 1; i <= 2 * N; i++){
        current += pref[i];

        if(pref[i] == 1){
            ans = (ans + powers[N - current]) % MOD;
        }
    }
    fout << ans;
}
