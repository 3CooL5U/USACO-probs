#include <bits/stdc++.h>
using namespace std;

ifstream fin("meetings.in");
ofstream fout("meetings.out");

int N, L, w[50005], x[50005], d[50005], t[50005], r[50005], l[50005], pos[50005], temp[50005];

bool cmp(int a, int b){
    return x[a] < x[b];
}

bool cmpt(int a, int b){
    return t[a] < t[b];
}

int main() {
    fin >> N >> L;
    int totalw = 0;
    for(int i = 0; i < N; i++) {
        pos[i] = i;
        temp[i] = i;
        fin >> w[i] >> x[i] >> d[i];
        totalw += w[i];
    }
    sort(pos, pos + N, cmp);

    int rightCount = 0, leftcount = 0;
    for(int i = 0; i < N; i++)
        if(d[pos[i]] == 1){
            r[rightCount] = pos[i];
            rightCount++;
        }else {
            l[leftcount] = pos[i];
            leftcount++;
        }

    for(int i = 0; i < leftcount; i++)
        t[pos[i]] = x[l[i]];
    for(int i = 0; i < rightCount; i++)
        t[pos[N-1-i]] = L - x[r[rightCount-1-i]];

    sort(temp, temp + N, cmpt);
    int currentw = 0, T = 0;
    for(int i = 0; i < N; i++) {
        currentw += w[temp[i]];
        if(currentw >= totalw/2) {
            T = t[temp[i]];
            break;
        }
    }

    int ans = 0;
    queue<int> meet;
    for(int i = 0; i < N; i++){
        if(d[pos[i]] == -1){
            while(meet.size() && meet.front()+2*T < x[pos[i]]) meet.pop();
            ans += meet.size();
        }else
            meet.push(x[pos[i]]);
    }
    fout << ans;
}
