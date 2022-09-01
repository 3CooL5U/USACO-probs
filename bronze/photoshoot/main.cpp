#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int N;
string A;

int main() {
    cin >> N >> A;
    vector<bool> condensed;
    for(int i = 0; i < N-1; i+=2){
        if(A[i] == 'G' && A[i+1] == 'H') condensed.push_back(false);
        else if(A[i] == 'H' && A[i+1] == 'G') condensed.push_back(true);
    }

    int count = 0;
    int prev = condensed[0];
    for(int i = 1; i < condensed.size(); i++){
        if(condensed[i] != prev){
            prev = !prev;
            count++;
        }
    }
    if(!condensed[condensed.size()-1]) count++;
    cout << count;
}