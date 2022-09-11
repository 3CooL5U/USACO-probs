#include <bits/stdc++.h>
using namespace std;

ifstream fin("exercise.in");
ofstream fout("exercise.out");

int N;
bool composite[10005];
long long M, dp[10005][1000];
vector<int> primes;

int main() {

    fin >> N >> M;
    for(int i = 2; i <= N; i++)
        if(!composite[i]) {
            primes.push_back(i);
            for (int q = 2 * i; q <= N; q += i) composite[q] = 1;
        }

    if(primes.size() == 0){
        fout << 1;
        return 0;
    }

    for(int i = 0; i <= N; i++) dp[i][0] = 1;

    for(int q = 1; q <= primes.size(); q++)
        for(int i = 0; i <= N; i++){
            dp[i][q] = dp[i][q-1];
            for(int pow = primes[q-1]; pow <= i; pow *= primes[q-1])
                dp[i][q] = (dp[i][q] + (dp[i-pow][q-1] * pow + M)%M + M)%M;
        }

    fout << dp[N][primes.size()];
    fout.close();
}
