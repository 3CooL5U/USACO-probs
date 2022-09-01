#include <bits/stdc++.h>
using namespace std;

int n, dist[50];

vector<array<int,3>> north, east;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++){
        char temp; int x, y;
        cin >> temp >> x >> y;
        if(temp == 'N') north.push_back({x, y, i});
        else east.push_back({x, y, i});
    }

    fill(dist, dist+n, -1);

    sort(north.begin(), north.end());
    sort(east.begin(), east.end(), [](auto const &a, auto const &b) { return a[1] < b[1]; });

    for(auto n:north){
        for(auto e:east) {
            if(dist[e[2]] != -1) continue;
            if(!(e[0] < n[0] && e[1] > n[1])) continue;
            if (e[1] - n[1] > n[0] - e[0]) {
                dist[n[2]] = e[1] - n[1];
                break;
            } else if (e[1] - n[1] == n[0] - e[0])
                continue;
            else
                dist[e[2]] = n[0] - e[0];
        }
    }

    for(int i = 0; i < n; i++)
        if(dist[i] == -1) cout << "Infinity" << endl;
        else cout << dist[i] << endl;
}