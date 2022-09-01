#include <bits/stdc++.h>
using namespace std;

ifstream fin("sort.in");
ofstream fout("sort.out");

int N, sorted[100005];
multimap<int, int> loc;

int main() {
    fin >> N;
    for(int i = 0; i < N; i++) {
        int temp = 0;
        fin >> temp;
        loc.insert({temp, i});
        sorted[i] = temp;
    }
    sort(sorted, sorted + N);
    int ans = 0;
    for(int i = 0; i < N; i++)
        ans = max(ans, abs(loc.find(sorted[i])->second) - i);
    fout << ans + 1;
}
