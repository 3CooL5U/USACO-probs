#include <bits/stdc++.h>
using namespace std;

ifstream fin("clocktree.in");
ofstream fout("clocktree.out");

int N, times[2505], groups[2505], A, B, sizeA, sizeB;
vector<int> adj[2505];
bool visited[2505];

void dfs(int node, bool group){
    if(visited[node]) return;
    visited[node] = true;
    groups[node] = group;
    if(group){
        A += times[node];
        sizeA++;
    }
    else{
        B += times[node];
        sizeB++;
    }

    for(int i = 0; i < adj[node].size(); i++){
        dfs(adj[node][i], !group);
    }
}

int main() {
    fin >> N;
    for(int i = 0; i < N; i++)
        fin >> times[i];

    for(int i = 0; i < N-1; i++){
        int a, b;
        fin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, 0);

    A %= 12;
    B %= 12;
    if(A == B) fout << N;
    else if(A - B == 1) fout << sizeA;
    else if(B - A == 1) fout << sizeB;
    else fout << 0;
}
