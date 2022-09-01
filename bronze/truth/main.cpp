#include <bits/stdc++.h>
using namespace std;

ifstream fin("truth.in");
ofstream fout("truth.out");

struct pointer{
    int next;
    int id;
    bool type;
};

int N, M, x[10005], y[10005], groups[10005], groupCount, statement;
bool type[10005], status[10005];
vector<pointer> edge[10005];

bool dfs(int node, bool need){
    if(groups[node] != -1)
        return status[node] == need;

    groups[node] = groupCount;
    status[node] = need;

    for(int i = 0; i < edge[node].size(); i++)
        if(edge[node][i].id <= statement)
            if(edge[node][i].type) {
                if (!dfs(edge[node][i].next, need))
                    return false;
            }else {
                if (!dfs(edge[node][i].next, !need))
                    return false;
            }

    return true;
}

bool check(){
    for(int i = 0; i < N; i++){
        groups[i] = -1;
        status[i] = false;
    }
    groupCount = 0;

    for(int i = 0; i < N; i++){
        if(groups[i] == -1){
            groupCount++;
            if(!dfs(i, true)) return false;
        }
    }

    return true;
}

int main() {
    fin >> N >> M;
    for(int i = 0; i < M; i++){
        fin >> x[i] >> y[i];
        x[i]--; y[i]--;
        char temp; fin >> temp;
        type[i] = (temp == 'T');

        edge[x[i]].push_back({y[i], i, type[i]});
        edge[y[i]].push_back({x[i], i, type[i]});
    }

    int left = 0, right = M-1;
    while(left != right){
        int mid = (left + right + 1) / 2;
        statement = mid;
        if(check()) left = mid;
        else right = mid - 1;
    }

    fout << (left + 1);
}
