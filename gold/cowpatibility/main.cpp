#include <bits/stdc++.h>
using namespace std;

ifstream fin("cowpatibility.in");
ofstream fout("cowpatibility.out");


int N, pie[] = {-1, 1, -1, 1, -1, 1};

struct key{
    int size;
    int flavor[5];
};

bool operator< (const key &a, const key &b)
{
    for (int i = 0; i < 5; i++) {
        if (a.flavor[i] < b.flavor[i]) return true;
        if (a.flavor[i] > b.flavor[i]) return false;
    }
    return false;
}


vector<vector<int>> cows;
map<key, int> subsets;

int main() {
    fin >> N;
    for(int i = 0; i < N; i++){
        vector<int> temp;
        for(int q = 0; q < 5; q++) {
            int a;
            fin >> a;
            temp.push_back(a);
        }
        sort(temp.begin(), temp.end());
        cows.push_back(temp);

        for(int q = 1; q < 32; q++){
            key subsetKey = {0, {0,0,0,0,0}};
            int keySize = 0;
            for(int x = 0; x < 5; x++)
                if(q & (1<<x)){
                    subsetKey.flavor[subsetKey.size] = temp[x];
                    subsetKey.size++;
                }

            subsets[subsetKey]++;
        }
    }

    long long ans = 0;
    for(auto &s : subsets)
        ans += pie[s.first.size] * (s.second * (s.second - 1)) / 2;

    fout << (N * (N - 1))/ 2 - ans;
}
