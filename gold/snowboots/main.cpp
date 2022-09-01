#include <bits/stdc++.h>
using namespace std;

ifstream fin("snowboots.in");
ofstream fout("snowboots.out");

int N, B, snow[100005], sortedSnow[100005], sortedBoots[100005], ans[100005];
pair<int,int> boots[100005]; //depth, dist

bool cmpSnow(int a, int b){
    return snow[a] < snow[b];
}

bool cmpBoots(int a, int b){
    return boots[a].first < boots[b].first;
}

int main() {
    fin >> N >> B;
    for(int i = 0; i < N; i++){
        fin >> snow[i];
        sortedSnow[i] = i;
    }
    for(int i = 0; i < B; i++){
        fin >> boots[i].first >> boots[i].second;
        sortedBoots[i] = i;
    }

    sort(sortedSnow, sortedSnow + N, cmpSnow);
    sort(sortedBoots, sortedBoots + B, cmpBoots);

    set<int> tiles;
    for(int i = 0; i < N; i++) tiles.insert(i);

    int maxgap = 0;
    int q = N-1;
    for(int i = B-1; i >= 0; i--){
        while(q >= 0 && snow[sortedSnow[q]] > boots[sortedBoots[i]].first){
            auto itr = tiles.find(sortedSnow[q]);
            maxgap = max(maxgap, *next(itr) - *prev(itr));
            tiles.erase(itr);
            q--;
        }

        if(maxgap > boots[sortedBoots[i]].second) ans[sortedBoots[i]] = 0;
        else ans[sortedBoots[i]] = 1;
    }
    for(int i = 0; i < B; i++)
        fout << ans[i] << endl;
}
