#include <bits/stdc++.h>
using namespace std;

ifstream fin("snakes.in");
ofstream fout("snakes.out");

int N, K, a[400], dp[405][405], total;

int main() {
    fin >> N >> K;
    for(int i = 1; i <= N; i++) {
        fin >> a[i];
        total += a[i];
    }

    int largest_group = -1;
    for(int i = 1; i <= N; i++){
        largest_group = max(largest_group, a[i]);
        dp[i][0] = largest_group * i;

        for(int q = 1; q <= K; q++){
            dp[i][q] = 1000000000;

            int net = a[i];
            for(int c = i-1; c >= 0; c--){
                dp[i][q] = min(dp[i][q], dp[c][q-1] + net * (i-c));
                net = max(net, a[c]);
            }
        }
    }

    fout << dp[N][K] - total;
}
