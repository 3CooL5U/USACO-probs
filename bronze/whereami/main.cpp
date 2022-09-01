#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ifstream fin("whereami.in");
ofstream fout("whereami.out");

int n;
string s;

int main(){
    fin >> n >> s;
    int ans = 1;
    while(true){
        set<string> color;
        int temp = ans;
        for(int i = 0; i <= n - ans; i++){
            if(color.count(s.substr(i, ans))){
                ans++;
                break;
            }else
                color.insert(s.substr(i, ans));
        }

        if(ans == temp)
            break;
    }
    fout << ans;
}