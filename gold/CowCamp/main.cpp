#include <bits/stdc++.h>
using namespace std;

int T, K;
double expected, cutOff, ans, pastCut;
long long dp[1005][1005];


double binpow(double x, long long n) {
    double res = 1;
    while (n > 0) {
        if (n % 2 == 1)
            res = res * x;
        x = x * x;
        n /= 2;
    }
    return res;
}

int main() {
    cout << fixed << setprecision(20);
    cin >> T >> K;

    for (int i = 0; i <= T; i++) {
        dp[i][0] = 1;
        if (i <= T)
            dp[i][i] = 1;
    }

    for (int i = 0; i <= T; i++)
        for (int j = 1; j <= min(i, T); j++)
            if (i != j)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

    double base = binpow(2, T-1);

    for(int i = 0; i < T; i++)
        expected += (i + 1) * dp[T - 1][i] / base;

    for(int i = 0; i <= expected - 1; i++)
        cutOff += dp[T-1][i] / base;

    for(int i = (int)expected; i < T; i++)
        pastCut += dp[T-1][i] * (i+1) / base;

    cout << expected << " " << cutOff <<  " " << pastCut << endl;

    ans += pastCut * (binpow(cutOff, K-1) - 1) / (cutOff - 1);

    cout << ans << endl;

    ans += binpow(cutOff, K-1) * expected;

    cout << ans;
}
//6.1167895793914794922
//6.11678957939147949219

//6.2835035854950547218
//6.25795586500316858292
//6.25796