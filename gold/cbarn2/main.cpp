#include <bits/stdc++.h>
using namespace std;

ifstream fin("cbarn2.in");
ofstream fout("cbarn2.out");

int N, K, A[105];
long long dp[10][105]; //first i doors, q unlocks

int main() {
    fin >> N >> K;
    for(int i = 0; i < N; i++)
        fin >> A[i];

    long long ans = 9999999999999;
    for(int j = 0; j < N; j++) {
        for(int q = 0; q <= K; q++)
            for(int i = 0; i <= N; i++)
                dp[q][i] = 9999999999999;

        dp[0][0] = 0;
        for(int q = 1; q <= K; q++)
            for(int i = 0; i < q; i++)
                dp[q][i] = 0;

        for(int i = 1; i < N; i++)
            dp[1][i] = dp[1][i-1] + A[i] * i;

        for (int q = 2; q <= K; q++) {
            for (int i = q; i < N; i++) {
                for (int x = i; x >= q; x--) {
                    long long sum = 0;
                    for(int w = x+1; w <= i; w++) sum += A[w] * (w - x);
                    dp[q][i] = min(dp[q][i], dp[q-1][x-1] + sum);
                }
            }
        }
        ans = min(ans, dp[K][N-1]);
        rotate(A, A + 1, A + N);
    }

    fout << ans;
}
