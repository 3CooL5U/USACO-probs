#include <bits/stdc++.h>
using namespace std;

int N, A[25], B[25], possible[25];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    sort(A, A+N, greater<int>());

    for(int i = 0; i < N; i++)
        for(int q = 0; q < N; q++)
            if(B[q] >= A[i]) possible[i]++;

    long long ans = 1;
    for(int i = 0; i < N; i++)
        ans *= (possible[i] - i);

    cout << ans;
}
