#include <bits/stdc++.h>
using namespace std;

ifstream fin("convention2.in");
ofstream fout("convention2.out");

int N;
vector<vector<int>> cows; //id, arrive, length

bool cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int main() {
    fin >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        fin >> a >> b;
        cows.push_back({i, a, b});
    }

    sort(cows.begin(), cows.end(), cmp);
    set<vector<int>> waiting;

    int current = 0, time = 0, ans = 0;
    while(current < N || !waiting.empty()){
        if(current < N && cows[current][1] <= time){
            waiting.insert(cows[current]);
            current++;
        }else if(waiting.empty()){
            time = cows[current][1] + cows[current][2];
            current++;
        }else{
            vector<int> next = *waiting.begin();
            ans = max(ans, time - next[1]);

            time += next[2];
            waiting.erase(waiting.begin());
        }
    }
    fout << ans;
}
