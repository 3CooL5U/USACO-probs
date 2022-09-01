#include <bits/stdc++.h>
#include <iostream>
using namespace std;

ifstream fin("fenceplan.in");
ofstream fout("fenceplan.out");

int N, M, group = 0;
vector<pair<int,int>> cows; //x, y
vector<pair<pair<int,int>, pair<int,int>>> perim; //first = max, first.first = x max
vector<int> adj[100005];
bool visited[100005];
vector<int> groupMembers[100005];

void dfs(int node){
    visited[node] = true;
    groupMembers[group].push_back(node);
    perim[group].first.first = max(perim[group].first.first, cows[node].first);
    perim[group].first.second = max(perim[group].first.second, cows[node].second);
    perim[group].second.first = min(perim[group].second.first, cows[node].first);
    perim[group].second.second = min(perim[group].second.second, cows[node].second);

    for(int i = 0; i < adj[node].size(); i++){
        if(!visited[adj[node][i]]){
            dfs(adj[node][i]);
        }
    }
}

int main() {
    fin >> N >> M;
    for(int i = 0; i < N; i++){
        int a, b; fin >> a >> b;
        cows.push_back({a,b});
    }
    for(int i = 0; i < M; i++){
        int a, b; fin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long long ans = LLONG_MAX;
    for(int i = 0; i < N; i++){
        if(!visited[i]) {
            perim.push_back({{cows[i].first,cows[i].second},{cows[i].first,cows[i].second}});
            dfs(i);
            ans = min(ans, (perim[group].first.first - perim[group].second.first + perim[group].first.second - perim[group].second.second) * 2LL);
            group++;
        }
    }

    /*for(int i = 0; i < group; i++) {
        for (int a: groupMembers[i]) cout << a << " ";
        cout << endl;
        cout << perim[group].first.first << " " << perim[group].second.first << " " << perim[group].first.second << " " << perim[group].second.second << endl;
    }*/
    fout << ans;
}
