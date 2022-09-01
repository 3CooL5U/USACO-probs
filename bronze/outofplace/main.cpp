#include <bits/stdc++.h>
#include <iostream>
using namespace std;

ifstream fin("outofplace.in");
ofstream fout("outofplace.out");

int N, sorted[105], height[105];

int main() {
    fin >> N;
    for(int i = 0; i < N; i++){
        fin >> height[i];
        sorted[i] = height[i];
    }
    sort(sorted, sorted + N);
    int count = 0;
    for(int i = 0; i < N; i++)
        if(sorted[i] != height[i])
            count++;
    fout << count - 1;
}