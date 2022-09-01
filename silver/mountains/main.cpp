#include <bits/stdc++.h>
using namespace std;

ifstream fin("mountains.in");
ofstream fout("mountains.out");

int N;
pair<int,int> mount[100005];

bool cmp(int a,int b)
{
    if(mount[a].first - mount[a].second == mount[b].first - mount[b].second)
        return mount[a].first + mount[a].second > mount[b].first+ mount[a].second;
    return mount[a].first - mount[a].second < mount[b].first - mount[b].second;
}

int main() {
    fin >> N;
    int temp[N+5];
    for(int i = 0; i < N; i++)
        temp[i] = i;
    for(int i = 0; i < N; i++)
        fin >> mount[i].first >> mount[i].second;

    sort(temp, temp + N, cmp);
    int ans = 0, max = 0;
    for(int i = 0; i < N; i++){
        if(mount[temp[i]].first + mount[temp[i]].second > max){
            ans++;
            max = mount[temp[i]].first + mount[temp[i]].second;
        }
    }
    fout << ans;
}
