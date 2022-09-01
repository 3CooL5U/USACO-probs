#include <bits/stdc++.h>
using namespace std;

ifstream fin("teamwork.in");
ofstream fout("teamwork.out");

int N, K, skill[10005], dp[10005];

int main() {
    fin >> N >> K;
    for(int i = 1; i <= N; i++)
        fin >> skill[i];

    set<int> group;
    dp[1] = skill[1];
    for(int i = 2; i <= N; i++){
        dp[i] = dp[i-1] + skill[i];
        group.insert(skill[i]);
        for(int q = 2; q <= K && i - q >= 0; q++){
            group.insert(skill[i-q+1]);
            dp[i] = max(dp[i], dp[i-q] + (q) * *group.rbegin());
            //cout << *group.rbegin() << endl;
        }
        group.clear();
    }

    fout << dp[N];
}
