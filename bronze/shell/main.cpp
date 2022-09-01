#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("shell.in");
ofstream fout("shell.out");

int n;

int main() {
    fin >> n;

    vector<int> shell {0, 1, 2};
    int counter[3] = {0, 0, 0};
    for(int i = 0; i < n; i++){
        int a, b, c;
        fin >> a >> b >> c;
        int temp = shell[a];
        shell[a] = shell[b];
        shell[b] = temp;
        counter[shell[c]]++;
    }

    fout << max(counter[0], max(counter[1], counter[2]));
}