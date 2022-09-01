#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ifstream fin("angry.in");
ofstream fout("angry.out");

int n, x[105];

int explode(int start, int direction){
    int prev = start, radius = 1;
    while(true){
        int next = prev;
        while(next + direction >= 0 && next + direction < n && abs(x[next+direction] - x[prev]) <= radius)
            next += direction;

        if(next == prev) break;

        prev = next;
        radius++;
    }
    return abs(prev - start);
}

int main() {
    fin >> n;
    for(int i = 0; i < n; i++) fin >> x[i];
    sort(x, x + n);

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, explode(i, -1) + explode(i, 1) + 1);

    fout << ans;
}