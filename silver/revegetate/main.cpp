#include <bits/stdc++.h>
#include <iostream>
using namespace std;

ifstream fin("revegetate.in");
ofstream fout("revegetate.out");

int N, M, group;
vector<pair<int,bool>> adj[100005]; //if 1, Same
bool visited[100005], color[100005], bad;

void dfs(int node, bool c){
    if(visited[node]) return;
    visited[node] = true;
    color[node] = c;
    for(int i = 0; i < adj[node].size(); i++){
        if(visited[adj[node][i].first]){
            if((adj[node][i].second && color[adj[node][i].first] != color[node])
                || (!adj[node][i].second && color[adj[node][i].first] == color[node]))
                bad = true;
        }
        if(adj[node][i].second)
            dfs(adj[node][i].first, c);
        else
            dfs(adj[node][i].first, !c);
    }
}

int main() {
    fin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; char c;
        fin >> c >> a >> b;
        a--; b--;
        adj[a].push_back({b, c == 'S'});
        adj[b].push_back({a, c == 'S'});
    }

    for(int i = 0; i < N; i++){
        if(!visited[i]){
            bad = false;
            dfs(i, 0);
            if(!bad) group++;
        }
    }

    if(group == 0) fout << 0;
    else{
        fout << 1;
        for(int i = 0; i < group; i++) fout << 0;
    }
}
