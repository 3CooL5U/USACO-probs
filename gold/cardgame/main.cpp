#include <bits/stdc++.h>
using namespace std;

ifstream fin("cardgame.in");
ofstream fout("cardgame.out");

int N, elise[50005];
bool cards[2*50005];
vector<int> besie1, besie2;

int main() {
    fin >> N;
    for(int i = 0; i < N; i++){
        fin >> elise[i];
        cards[elise[i]] = 1;
    }
    for(int i = 1; i <= 2 * N; i++)
        if(!cards[i] && besie1.size() < N/2) besie1.push_back(i);
        else if(!cards[i]) besie2.push_back(i);

    sort(elise, elise + N / 2);
    sort(elise + N / 2, elise + N);

    int ans = 0;
    int q = 0;
    for(int i = 0; i < N/2; i++){
        while(q < N/2 && besie2[q] < elise[i]) q++;
        if(q == N/2) break;
        ans++;
        q++;
    }

    q = N/2 - 1;
    for(int i = N - 1; i >= N/2; i--){
        while(q >= 0 && besie1[q] > elise[i]) q--;
        if(q == -1) break;
        ans++;
        q--;
    }

    fout << ans;
}
