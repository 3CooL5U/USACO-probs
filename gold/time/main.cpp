#include <bits/stdc++.h>
using namespace std;

ifstream fin("time.in");
ofstream fout("time.out");

int N, M, C, money[1005], dp[1005][1005]; //time, ending location
vector<int> adj[1005];

int main() {
    fin >> N >> M >> C;
    for(int i = 0; i < N; i++)
        fin >> money[i];

    for(int i = 0; i < M; i++){
        int a, b;
        fin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }

    for(int i = 0; i <= 1000; i++)
        for(int q = 0; q <= N; q++)
            dp[i][q] = -1;

    int ans = 0;
    dp[0][0] = 0;
    for(int t = 0; t <= 1000; t++){
        for(int q = 0; q < N; q++)
            if(dp[t][q] != -1)
                for(int next = 0; next < adj[q].size(); next++)
                    dp[t+1][adj[q][next]] = max(dp[t+1][adj[q][next]], dp[t][q] + money[adj[q][next]]);

        ans = max(ans, dp[t][0] - C * t * t);
    }

    fout << ans;
}

