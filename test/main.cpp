#include <bits/stdc++.h>
using namespace std;

ofstream fout("test.out");

int main() {
    ifstream fin;
    fin.open("test.in");
    if(fin.fail()) {
        cout<<"Input file did not open please check it\n";
    }

    int N = 0;
    fin >> N;
    cout << N;

    ofstream fout;
    fout.open("test.out");
    if(fin.fail()) {
        cout<<"Input file did not open please check it\n";
    }



    fout << N;
}
