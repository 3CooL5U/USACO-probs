#include <bits/stdc++.h>
using namespace std;

ofstream fout(".\\talent.out");



int N, W, weight[255], talent[255];
long long dp[1005];

bool check(int A){
    for(int q = 0; q <= W; q++)
        dp[q] = LLONG_MIN + 10000000;

    dp[0] = 0;

    for(int i = 0; i < N; i++)
        for(int q = W; q >= 0; q--)
            if(dp[q] != LLONG_MIN + 10000000) {
                int current = min(W, q + weight[i]);
                dp[current] = max(dp[current], dp[q] + (long long)talent[i] * 1000 - A * (long long)weight[i]);
            }

    if(dp[W] >= 0) return true;
    return false;
}

int main() {
    ifstream fin;
    fin.open("./talent.in");
    if(fin.fail()) {
        cout<<"Input file did not open please check it\n";
        system("pause");
        return 1;
    }

    fin >> N >> W;
    for(int i = 0; i < N; i++)
        fin >> weight[i] >> talent[i];

    int lo = 0, hi = 1000 * 250 * 1000;
    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if(check(mid))
            lo = mid;
        else
            hi = mid;
    }
    fout << lo;
    cout << lo;
}
