#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("blocks.in");
ofstream fout("blocks.out");

int n, ans[26];

void countFreq(string a, int freq[]){
    for(char c:a){
        freq[c - 'a']++;
    }
}

int main() {
    fin >> n;

    for(int i = 0; i < n; i++){
        string a, b;
        fin >> a >> b;
        int freqA[26] = {}, freqB[26] = {};
        countFreq(a, freqA);
        countFreq(b, freqB);
        for(int q = 0; q < 26; q++)
            ans[q] += max(freqA[q], freqB[q]);
    }

    for(int i = 0; i < 26; i++) fout << ans[i] << endl;
}