#include <iostream>
#include <bits/stdc++.h>
using namespace std;

ifstream fin("meetings.in");
ofstream fout("meetings.out");

int N;
vector<pair<int,int>> cow;
vector<vector<int>> comp;

bool cmpY(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        cow.push_back({a,b});
    }

    sort(cow.begin(), cow.end());
    int x = 0, prev = cow[0].first;
    for(int i = 0; i < cow.size(); i++){
        if(cow[i].first != prev){
            prev = cow[i].first;
            x++;
        }
        cow[i].first = x;
    }
    int xmax = x;

    sort(cow.begin(), cow.end(), cmpY);
    vector<int> temp;
    comp.push_back(temp);
    x = 0, prev = cow[0].second;
    for(int i = 0; i < cow.size(); i++){
        if(cow[i].second != prev){
            prev = cow[i].second;
            vector<int> temp2;
            comp.push_back(temp2);
            x++;
        }
        cow[i].second = x;
        comp[x].push_back(cow[i].first);
    }
    int ymax = x;

    cout << xmax << " " << ymax << endl;

    for(int i = 1; i < comp.size(); i++) {
        int min = 0, max = xmax;
        while(min < max){
            int mid = (min + max + 1)/2;
            if(left < right){
                mind =
            }
        }
    }
}
