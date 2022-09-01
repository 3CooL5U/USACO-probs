#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int N, M, group = 0, chosen[100005]; //n cows, m boxes
vector<pair<int,int>> cows;
vector<int> adj[100005], groups[100005];
bool box[100005], visited[100005];

void dfs(int node){
    if(visited[node]) return;
    visited[node] = true;
    groups[group].push_back(node);
    if(!box[cows[node].first]) {
        chosen[node] = cows[node].first;
        box[cows[node].first] = true;
        for (int i = 0; i < adj[cows[node].first].size(); i++)
            if (!visited[adj[cows[node].first][i]])
                dfs(adj[cows[node].first][i]);
    }else if(!box[cows[node].second]){
        chosen[node] = cows[node].second;
        box[cows[node].second] = true;
        for (int i = 0; i < adj[cows[node].second].size(); i++)
            if (!visited[adj[cows[node].second][i]])
                dfs(adj[cows[node].second][i]);
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        cows.push_back({a,b});
        adj[a].push_back(i);
        adj[b].push_back(i);
    }

    fill(chosen, chosen + N, -1);

    for(int i = 0; i < N; i++){
        if(!visited[i]) {
            dfs(i);
            group++;
        }
    }

    int hungry = 0;
    for(int i = 0; i < N; i++)
        if(chosen[i] == -1) hungry++;
    cout << hungry << endl;

    for(int i = 0; i < group; i++){
        for(int a : groups[i])
            cout << (a + 1)<< endl;
    }

    cout << endl;
    for(int i = 0; i < N; i++)
        cout << chosen[i] << " ";
    cout << endl;
}
