#include <bits/stdc++.h>
using namespace std;

ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

long long N, a[100005], counter[100005], ans;
queue<long long> q;

int main() {
    fin >> N;
    ans = N;
    for(int i = 0; i < N; i++){
        fin >> a[i];
        a[i]--;
        counter[a[i]]++;
    }

    for(int i = 0; i < N; i++){
        if(counter[i] == 0){
            q.push(i);
            ans--;
        }
    }

    while (!q.empty()){
        long long current = q.front();
        q.pop();
        counter[a[current]]--;
        if(counter[a[current]] == 0){
            q.push(a[current]);
            ans--;
        }
    }

    fout << ans;
}
