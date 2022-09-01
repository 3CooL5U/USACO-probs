#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int N;
set<long long> hay;

bool checkRight(int x, int r){
    auto ending = hay.end(); ending--;
    auto itr = hay.end(); itr--;
    if(*itr > x + r){
        auto current = hay.upper_bound(x + r); current--;
        r -= 2;
        while(current != ending){
            auto temp = hay.upper_bound(*current + r); temp--;
            if(*temp <= *current) return false;
            current = temp;
            r -= 2;
        }
    }
    return true;
}

bool checkLeft(int x, int r) {
    if(*hay.begin() < x - r){
        long long current = *hay.lower_bound(x-r);
        r -= 2;
        while(current != *hay.begin()){
            if(*hay.lower_bound(current - r) >= current) return false;
            current = *hay.lower_bound(current-r);
            r -= 2;
        }
    }
    return true;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    cin >> N;
    for(int i = 0; i < N; i++){
        long long temp; cin >> temp;
        hay.insert(temp * 2);
    }

    auto ending = hay.end(); ending--;
    long long min = 0, max = *ending;
    while(min < max){
        long long r = (min + max)/2;
        long long l = *hay.begin(), right = *ending;
        while(l < right){
            long long x = (l + right + 1)/2;
            if(checkLeft(x, r))
                l = x;
            else
                right = x-1;
        }
        if(checkRight(l, r))
            max = r;
        else
            min = r+1;
    }
    printf("%.1f\n", min / 2.0);
}
