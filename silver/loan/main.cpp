#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long N, M, K;

bool check(int x){
    long long total = 0, day = K;
    while(total < N && day > 0){
        long long y = (N - total)/x;
        if(y <= M){
            if(total + day * M >= N) return true;
            else return false;
        }

        long long mod = (N-total)%x;
        long long numdays = mod / y + 1;
        if(numdays > K) numdays = K;

        total += y * numdays;
        day -= numdays;
    }
    if(total >= N) return true;
    return false;
}

int main() {
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);

    cin >> N >> K >> M;
    long long min = 1, max = K;
    while(min < max){
        long long x = (min + max + 1)/2;
        if(check(x))
            min = x;
        else
            max = x - 1;
    }
    cout << min;
}
