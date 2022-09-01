#include <bits/stdc++.h>
using namespace std;

ifstream fin("maxcross.in");
ofstream fout("maxcross.out");

int N, K, B, broken[100005], pref[100005];

int main(){
    fin >> N >> K >> B;
    for(int i = 0; i < B; i++) {
        int temp = 0;
        fin >> temp;
        broken[temp-1] = 1;
    }

    if(broken[0] == 0) pref[0] = 1;
    for(int i = 1; i < N; i++)
        if(broken[i] == 0)
            pref[i] = pref[i-1] + 1;
        else
            pref[i] = pref[i-1];


    int m = 0;
    for(int i = K; i < N; i++) {
        m = max(pref[i] - pref[i-K], m);
    }

    fout << K - m;
}