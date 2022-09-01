#include <bits/stdc++.h>
using namespace std;

ifstream fin("diamond.in");
ofstream fout("diamond.out");

int N, K, s[50005];

int main() {
    fin >> N >> K;
    for(int i = 0; i < N; i ++)
        fin >> s[i];
    sort(s, s + N);

    int left = 0, right = 0, ans = 0, maxl = 0, maxr = 0;
    while(left < N && right < N){
        while(right + 1 < N && s[right+1] - s[left] <= K)
            right++;

        if(ans < right - left + 1){
            ans = right - left + 1;
            maxl = left;
            maxr = right;
        }
        left++;
    }

    for(int i = maxr + 1; i < N; i++)
        s[i - ans] = s[i];

    left = 0, right = 0;
    int second = 0;
    while(left < N - ans && right < N - ans){
        while(right + 1 < N - ans && s[right+1] - s[left] <= K)
            right++;

        second = max(second, right - left + 1);
        left++;
    }

    fout << ans + second;
}
