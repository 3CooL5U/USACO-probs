#include <bits/stdc++.h>
using namespace std;

ifstream fin("taming.in");
ofstream fout("taming.out");

int N, A[105], dp[105][105][105];

int main() {
    fin >> N;
    for (int i = 0; i < N; i++) fin >> A[i];

    for(int i = 0; i <= N; i++)
        for(int q = 0; q <= N; q++)
            for(int x = 0; x <= N; x++)
                dp[i][q][x] = 9999999;

    if(A[0] == 0) dp[0][1][0] = 0;
    else dp[0][1][0] = 1;

    for (int i = 1; i < N; i++) {
        for (int q = 1; q <= i+1; q++) {
            for (int x = 0; x <= i; x++) {
                if (x < i) dp[i][q][x] = dp[i - 1][q][x];
                else
                    for (int temp = 0; temp < i; temp++)
                        dp[i][q][x] = min(dp[i][q][x], dp[i - 1][q - 1][temp]);
                if (A[i] != i - x)
                    dp[i][q][x]++;
            }
        }
    }

    for (int q = 1; q <= N; q++) {
        int ans = 99999999;
        for (int x = 0; x < N; x++)
            ans = min(ans, dp[N - 1][q][x]);
        fout << ans << endl;
    }
}
