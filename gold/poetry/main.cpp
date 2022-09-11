#include <bits/stdc++.h>
using namespace std;

ifstream fin("poetry.in");
ofstream fout("poetry.out");

long long MOD = 1000000007;

int N, M, K, s[5005], c[5005], numWays[5005], dp[5005];
char e[100005];
unordered_map<char, int> freq;

long long exp(int base, int power){
    if(power == 0) return 1;
    if(base == 1) return (base + MOD) % MOD;
    long long ans = exp(base, power/2);
    ans = (ans * ans + MOD) % MOD;
    if(power % 2) ans = (ans * base + MOD) % MOD;
    return (ans + MOD)%MOD;
}

int main() {
    fin >> N >> M >> K;
    for(int i = 0; i < N; i++)
        fin >> s[i] >> c[i];
    for(int i = 0; i < M; i++) {
        fin >> e[i];
        if(freq.find(e[i]) == freq.end())
            freq[e[i]] = 1;
        else
            freq[e[i]]++;
    }

    dp[0] = 1;

    for(int i = 0; i <= K; i++) {
        for (int q = 0; q < N; q++) {
            if(i+s[q] > K) continue;
            if(i+s[q] == K) numWays[c[q]] = (numWays[c[q]] + dp[i] + MOD)%MOD;
            else dp[i+s[q]] = (dp[i+s[q]] + dp[i] + MOD)%MOD;
        }
    }

    long long ans = 1;
    for(auto i : freq){
        long long sum = 0;
        for(int q = 0; q <= N; q++){
            if(numWays[q] == 0) continue;
            sum = (sum + exp(numWays[q], i.second) + MOD)%MOD;
        }
        ans = (ans * sum + MOD)%MOD;
    }

    fout << (ans + MOD)%MOD;
}
