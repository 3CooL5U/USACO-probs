#include <bits/stdc++.h>
#include <iostream>
using namespace std;

ifstream fin("wormsort.in");
ofstream fout("wormsort.out");

int N, M, p[100005], group[100005];
vector<pair<int,int>> adj[100005];

void dfs(int node, int current, int min){
    if(group[node] != -1) return;
    group[node] = current;

    for(auto next : adj[node])
        if(next.second >= min && group[next.first] == -1)
            dfs(next.first, current, min);
}

bool check(int min){
    fill(group, group + N, -1);
    int current = 0;

    for(int i = 0; i < N; i++){
        if(group[i] == -1)
            dfs(i, current, min);
        current++;
    }

    for(int i = 0; i < N; i++)
        if(group[i] != group[p[i]]) return false;

    return true;
}

int main() {
    fin >> N >> M;
    for(int i = 0; i < N; i++) {
        int a; fin >> a; a--;
        p[i] = a;
    }
    for(int i = 0; i < M; i++){
        int a, b, c;
        fin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }


    int l = 1, r = 1000000000;
    int top = -1;
    while(l < r){
        int mid = (l + r + 1)/2;
        if(check(mid)){
            top = max(top, mid);
            l = mid;
        }else
            r = mid - 1;
    }
    if(top == 1000000000) fout << -1;
    else fout << l;
}
