#include <bits/stdc++.h>
using namespace std;

ifstream fin("rental.in");
ofstream fout("rental.out");

int N, M, R, c[100005], rent[100005];
long long f[100005], g[100005]; //f = max money from milk of most productive vows g is from renting
pair<int,int> shop[100005]; //first is cost per gallon, second = # of gallons

bool cmp (const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
}

int main(){
    fin >> N >> M >> R;
    for(int i = 0; i < N; i++) fin >> c[i];
    for(int i = 0; i < M; i++) fin >> shop[i].second >> shop[i].first;
    for(int i = 0; i < R; i++) fin >> rent[i];

    sort(c, c + N, greater<int>());
    sort(shop, shop + M, cmp);
    sort(rent, rent + R, greater<int>());

    for(int i = 1; i <= R; i++) g[i] += rent[i-1] + g[i-1];
    for(int i = R+1; i <= N; i++) g[i] = g[R-1];

    int current = 0;
    for(int i = 1; i <= N; i++){
        f[i] += f[i-1];
        while(c[i-1] && current < R){
            if(shop[current].second > c[i-1]){
                f[i] += c[i-1] * shop[current].first;
                shop[current].second -= c[i-1];
                c[i-1] = 0;
            } else if(shop[current].second == c[i-1]){
                f[i] += c[i-1] * shop[current].first;
                c[i-1] = 0;
                current++;
            } else {
                f[i] += shop[current].second * shop[current].first;
                c[i-1] -= shop[current].second;
                current++;
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i <= N; i++)
        ans = max(ans, f[i] + g[N-i]);

    fout << ans;
}