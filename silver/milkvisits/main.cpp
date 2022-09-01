#include <bits/stdc++.h>
using namespace std;

ifstream fin("milkvisits.in");
ofstream fout("milkvisits.out");

int N, M, curGroup, assignment[100005];
vector<int> adj[100005];
string type;
pair<int, char> groups[100005];
bool visited[100005];

void dfs(int node){
    if(visited[node]) return;
    if(type[node] == groups[curGroup].second) groups[curGroup].first++;
    else return;
    visited[node] = true;
    assignment[node] = curGroup;

    for(int i = 0; i < adj[node].size(); i++){
        if(type[adj[node][i]] == groups[curGroup].second)
            dfs(adj[node][i]);
    }
}

int main() {
    fin >> N >> M;
    fin >> type;
    for(int i = 0; i < N-1; i++){
        int a, b;
        fin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < N; i++){
        if(!visited[i]) {
            groups[curGroup].second = type[i];
            dfs(i);
            curGroup++;
        }
    }

    //fout << endl;
    for(int i = 0; i < M; i++){
        int a, b;
        char c;
        fin >> a >> b >> c;
        a--; b--;
        if(assignment[a] != assignment[b]) fout << 1;
        else if(assignment[a] == assignment[b] && c == groups[assignment[a]].second) fout << 1;
        else fout << 0;
    }
}
