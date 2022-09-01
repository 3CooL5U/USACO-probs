#include <bits/stdc++.h>
#include <iostream>
using namespace std;

ifstream fin("breedflip.in");
ofstream fout("breedflip.out");

int N;
string A, B;

int main() {
    fin >> N >> A >> B;
    int count = 0;
    for(int i = 0; i < N; i++)
        if((i == 0 || B[i-1] == A[i-1]) && B[i] != A[i]) count++;
    fout << count;
}
