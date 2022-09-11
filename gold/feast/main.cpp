#include <bits/stdc++.h>
using namespace std;

ifstream fin("feast.in");
ofstream fout("feast.out");

int T, A, B;
bool possible[5000005][2];

int main() {
    fin >> T >> A >> B;
    possible[0][0] = true;
    possible[0][1] = true;

    for(int i = 0; i <= T; i++){
        if((i >= A && possible[i-A][0]) || (i >= B && possible[i-B][0])) possible[i][0] = true;
        if(possible[i][0])
            possible[i/2][1] = true;
    }

    for(int i = 0; i <= T; i++){
        if((i >= A && possible[i-A][1]) || (i >= B && possible[i-B][1])) possible[i][1] = true;
    }

    for(int i = T; i >= 0; i--)
        if(possible[i][1]) {
            fout << i;
            break;
        }
}
