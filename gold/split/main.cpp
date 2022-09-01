#include <bits/stdc++.h>
using namespace std;

ifstream fin("split.in");
ofstream fout("split.out");

int N, loc[50005];
pair<int,int> cows[50005];

bool cmpx (int a, int b){
    if(cows[a].first == cows[b].first)
        return cows[a].second < cows[b].second;
    return cows[a].first < cows[b].first;
}

bool cmpy (int a, int b){
    if(cows[a].second == cows[b].second)
        return cows[a].first < cows[b].first;
    return cows[a].second < cows[b].second;
}

int main() {
    multiset<int> leftx, lefty, rightx, righty, allx, ally;

    fin >> N;
    for(int i = 0; i < N; i++) {
        loc[i] = i;
        fin >> cows[i].first >> cows[i].second;
        allx.insert(cows[i].first);
        ally.insert(cows[i].second);
    }

    sort(loc, loc + N, cmpx);
    int x1 = *allx.rbegin(), x2 = *allx.begin(), y1 = *ally.rbegin(), y2 = *ally.begin();
    long long total = (x1 - x2) * 1LL * (y1 - y2);
    long long ans = 0;

    for(int temp = 0; temp <= 1; temp++){
        leftx.clear(); lefty.clear();
        rightx = allx; righty = ally;
        for(int i = 0; i < N; i++){
            long long areaL = 0, areaR = 0;
            leftx.insert(cows[loc[i]].first);
            lefty.insert(cows[loc[i]].second);
            rightx.erase(rightx.find(cows[loc[i]].first));
            righty.erase(righty.find(cows[loc[i]].second));

            x1 = *leftx.begin();
            y1 = *lefty.begin();
            x2 = *leftx.rbegin();
            y2 = *lefty.rbegin();
            areaL = (x2 - x1) * 1LL * (y2 - y1);
            if (!rightx.empty()) {
                x1 = *rightx.begin();
                y1 = *righty.begin();
                x2 = *rightx.rbegin();
                y2 = *righty.rbegin();
                areaR = (x2 - x1) * 1LL * (y2 - y1);
            }

            ans = max(ans, total - areaL - areaR);
        }
        sort(loc, loc + N, cmpy);
    }
    fout << ans;
}