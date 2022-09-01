#include <bits/stdc++.h>
using namespace std;

ifstream fin("reststops.in");
ofstream fout("reststops.out");

int L, N, RF, RB;
vector<pair<int,int>> grass; //location, tasty
vector<int> stops;

int main() {
    fin >> L >> N >> RF >> RB;
    for(int i = 0; i < N; i++){
        int a, b;
        fin >> a >> b;
        grass.push_back({a,b});
    }

    int m = 0;
    for(int i = N-1; i >= 0; i--){
        if(grass[i].second > m){
            m = grass[i].second;
            stops.push_back(i);
        }
    }

    sort(stops.begin(), stops.end());

    long long taste = 0, prev = 0;
    for(int i = 0; i < stops.size(); i++){
        taste += grass[stops[i]].second * ((grass[stops[i]].first - prev) * (RF - RB));
        prev = grass[stops[i]].first;
    }

    fout << taste;
}
