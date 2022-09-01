#include <bits/stdc++.h>
using namespace std;

int N, Psum[2505][2505];
pair<int,int> points[2505];
bool ycomp(pair<int,int> p, pair<int,int> q) { return p.second < q.second; }

int rsum(int x1, int y1, int x2, int y2)
{
    return Psum[x2+1][y2+1] - Psum[x2+1][y1] - Psum[x1][y2+1] + Psum[x1][y1];
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> points[i].first >> points[i].second;
    }
    sort(points, points+N);
    for(int i = 0; i < N; i++) points[i].first = i + 1;
    sort(points, points+N, ycomp);
    for(int i = 0; i < N; i++) points[i].second = i + 1;

    for(int i = 0; i < N; i++) Psum[points[i].first][points[i].second] = 1;
    for(int i = 1; i <= N; i++)
        for(int q = 1; q <= N; q++)
            Psum[i][q] += Psum[i-1][q] + Psum[i][q-1] - Psum[i-1][q-1];

    long long ans = 0;
    for(int i = 0; i < N; i++)
        for(int j = i; j < N; j++)
            ans += rsum(0, i, min(points[i].first, points[j].first) - 1, j)
                    * rsum(max(points[i].first, points[j].first) - 1, i, N-1, j);

    cout << ans + 1;
}
