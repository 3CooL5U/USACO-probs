#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ifstream fin ("cownomics.in");
ofstream fout ("cownomics.out");

int n, m;

int main(){
    fin >> n >> m;
    vector<vector<int>> plain(n, vector<int>(m));
    vector<vector<int>> spotted(m, vector<int>(m));

    for(int i = 0; i < n; i++){
        string genome; fin >> genome;
        for(int q = 0; q < m; q++)
            if (genome[q] == 'A')
                spotted[i][q] = 0;
            else if (genome[q] == 'T')
                spotted[i][q] = 1;
            else if (genome[q] == 'C')
                spotted[i][q] = 2;
            else if (genome[q] == 'G')
                spotted[i][q] = 3;
    }

    for(int i = 0; i < n; i++){
        string genome; fin >> genome;
        for(int q = 0; q < m; q++)
            if (genome[q] == 'A')
                plain[i][q] = 0;
            else if (genome[q] == 'T')
                plain[i][q] = 1;
            else if (genome[q] == 'C')
                plain[i][q] = 2;
            else if (genome[q] == 'G')
                plain[i][q] = 3;
    }

    int count = 0;

    for(int i = 0; i < m; i++)
        for(int q = i+1; q < m; q++)
            for(int z = q+1; z < m; z++){
                vector<bool> spotted_ids(64);
                for(int v = 0; v < n; v++)
                    spotted_ids[spotted[v][i] + spotted[v][q] * 4 + spotted[v][z] * 16] = true;

                bool valid = true;
                for(int v = 0; v < n; v++){
                    int total = plain[v][i] + plain[v][q] * 4 + plain[v][z] * 16;
                    if(spotted_ids[total]){
                        valid = false;
                        break;
                    }
                }

                if(valid) count++;
            }

    fout << count;
}