#include <bits/stdc++.h>
using namespace std;

ifstream fin("countcross.in");
ofstream fout("countcross.out");

int N, K, R, farm[105][105];
bool roadsX[105][105], roadsY[105][105]; //raods x [i][q] == raod between [i][q] and [i][q+1]
pair<int,int> locations[105];
bool visitedCow[105], visited[105][105];

void dfs(int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= N) return;
    if(visited[x][y]) return;
    visited[x][y] = true;
    if(farm[x][y] != -1) {
        if (visitedCow[farm[x][y]]) return;
        else visitedCow[farm[x][y]] = true;
    }

    if(!roadsX[x][y]) dfs(x, y+1);
    if(y > 0 && !roadsX[x][y-1]) dfs(x, y-1);
    if(!roadsY[x][y]) dfs(x+1, y);
    if(x > 0 && !roadsY[x-1][y]) dfs(x-1, y);
}

int main() {
    fin >> N >> K >> R;
    for(int i = 0; i < R; i++) {
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        if(a == c)
            roadsX[a][min(b,d)] = true;
        else
            roadsY[min(a,c)][b] = true;
    }

    for(int i = 0; i <= N; i++)
        for(int q = 0; q <= N; q++)
            farm[i][q] = -1;

    for(int i = 0; i < K; i++){
        int a, b;
        fin >> a >> b;
        a--; b--;
        farm[a][b] = i;
        locations[i] = {a,b};
    }

    int ans = 0;
    for(int i = 0; i < K; i++){
        for(int q = 0; q <= K; q++) visitedCow[q] = false;
        for(int x = 0; x < N; x++)
            for(int y = 0; y < N; y++) visited[x][y] = false;

        dfs(locations[i].first, locations[i].second);

        for(int q = 0; q < K; q++)
            if(!visitedCow[q]) ans++;
    }

    fout << ans/2;
}
