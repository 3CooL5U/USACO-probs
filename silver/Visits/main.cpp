#include <bits/stdc++.h>
using namespace std;

long long N, total;
vector<pair<int, long long>> buddies;
vector<int> adj[100005];
bool visited[100005];

void dfs(int node){
    if(visited[node]) return;
    visited[node] = true;

    for(int i = 0; i < adj[node].size(); i++)
        dfs(adj[node][i]);
}

int cycle(int node){
    int a = buddies[node].first;
    int b = buddies[a].first;
    while(a != b){
        a = buddies[a].first;
        b = buddies[buddies[b].first].first;
    }

    long long m = buddies[a].second;
    a = buddies[a].first;
    while(a != b){
        m = min(m, buddies[a].second);
        a = buddies[a].first;
    }

    dfs(a);
    return m;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        a--;
        buddies.push_back({a, b});
        adj[a].push_back(i);
        total += b;
    }

    for(int i = 0; i < N; i++)
        if(!visited[i])
            total -= cycle(i);

    cout << total;
}
