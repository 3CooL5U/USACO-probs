#include <bits/stdc++.h>

using namespace std;

constexpr int COW_NUM = 7;

int main() {
    ifstream read("notlast.in");
    int N;
    read >> N;

    map<string, int> raw;
    for (int i = 0; i < N; i++) {
        string a;
        int b;
        read >> a >> b;
        raw[a] += b;
    }

    vector<pair<int, string>> cows;
    for (pair<string, int> t : raw) {
        cows.push_back({t.second, t.first});
    }
    sort(cows.begin(), cows.end());

    int ind = 0;
    /*
     * only move the pointer if all cows produced some milk, as
     * any unmentioned cows will have produced 0 milk
     */
    if (cows.size() == COW_NUM) {
        while (ind < cows.size() && cows[ind].first == cows[0].first) {
            ind++;
        }
    }

    if (ind < cows.size()
        && (ind + 1 == cows.size() ||
            cows[ind].first != cows[ind + 1].first)) {
        ofstream("notlast.out") << cows[ind].second << endl;
    } else {
        ofstream("notlast.out") << "Tie" << endl;
    }
}
