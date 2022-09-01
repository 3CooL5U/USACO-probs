#include <bits/stdc++.h>
using namespace std;

ifstream fin("planting.in");
ofstream fout("planting.out");

int N;
vector<vector<int>> adj;
vector<int> grassType;

void dfs(int current, int prev){
    int type = 1;
    for(int neighbor : adj[current]){
        if(neighbor == prev) continue;

        if(type == grassType[prev] || type == grassType[current]) type++;
        if(type == grassType[prev] || type == grassType[current]) type++;

        grassType[neighbor] = type;

        dfs(neighbor, current);

        type++;
    }
}

int main() {
    fin >> N;
    adj = vector<vector<int>>(N);
    grassType = vector<int>(N);

    int a, b;
    for(int i = 0; i < N-1; i++){
        fin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }

    grassType[0] = 1;
    dfs(0,0);

    int ans = 0;
    for(int i: grassType)
        ans = max(ans, i);
    fout << ans;
}
