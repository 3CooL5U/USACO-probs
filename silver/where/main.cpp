#include <bits/stdc++.h>
#include <iostream>
using namespace std;

ifstream fin("where.in");
ofstream fout("where.out");

int N, counter[30];
struct temp {
    int x1, y1, x2, y2;
};
vector<temp> PCL;
string img[22];
bool visited[22][22];


void floodfill(int i, int q, int x1, int y1, int x2, int y2, char c){
    if(visited[i][q]) return;
    if(i < x1 || i > x2 || q < y1 || q > y2) return;
    visited[i][q] = true;
    if(i + 1 <= x2 && img[i+1][q] == c) floodfill(i+1, q, x1, y1, x2, y2, c);
    if(q + 1 <= y2 && img[i][q+1] == c) floodfill(i, q+1, x1, y1, x2, y2, c);
    if(i > 0 && img[i-1][q] == c) floodfill(i-1, q, x1, y1, x2, y2, c);
    if(q > 0 && img[i][q-1] == c) floodfill(i, q-1, x1, y1, x2, y2, c);
}

bool isPCL(int x1, int y1, int x2, int y2){
    for(int i = 0; i < N; i++)
        for (int q = 0; q < N; q++)
            visited[i][q] = false;
    for(int i = 0; i < 27; i++) counter[i] = 0;

    for(int i = x1; i <= x2; i++)
        for(int q = y1; q <= y2; q++)
            if(!visited[i][q]) {
                floodfill(i, q, x1, y1, x2, y2, img[i][q]);
                counter[img[i][q] - 'A']++;
            }


    int numberOfColors = 0;
    bool one = false, two = false;
    for(int i = 0; i < 26; i++)
        if(counter[i] != 0){
            if(counter[i] == 1) one = true;
            if(counter[i] > 1) two = true;
            numberOfColors++;
        }

    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    for(int i = 0; i < 3; i++) cout << counter[i] << " ";
    cout << endl;

    if(numberOfColors == 2 && one && two) return true;
    return false;
}

int main() {
    fin >> N;
    for(int i = 0; i < N; i++)
        fin >> img[i];

    for(int x1 = 0; x1 < N; x1++)
        for(int y1 = 0; y1 < N; y1++)
            for(int x2 = x1; x2 < N; x2++)
                for(int y2 = y1; y2 < N; y2++) {
                    if (isPCL(x1, y1, x2, y2)) {
                        temp p = {x1, y1, x2, y2};
                        PCL.push_back(p);
                    }
                }

    for(int i = 0; i < PCL.size(); i++)
        cout << PCL[i].x1 << " " << PCL[i].y1 << " " << PCL[i].x2 << " " << PCL[i].y2 << endl;

    int ans = 0;
    for(int i = 0; i < PCL.size(); i++) {
        bool check = true;
        for (int q = 0; q < PCL.size(); q++) {
            if (q != i) {
                if (PCL[i].x1 >= PCL[q].x1
                    && PCL[i].y1 >= PCL[q].y1
                    && PCL[i].x2 <= PCL[q].x2
                    && PCL[i].y2 <= PCL[q].y2)
                    check = false;
            }
        }
        if(check) ans++;
    }
    fout << ans;
}

/*
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int N;
string img[20];

struct PCL { int i1,j1,i2,j2; };
vector<PCL> V;
bool beenthere[20][20];

void visit(int i, int j, int c, int i1, int j1, int i2, int j2)
{
    beenthere[i][j] = true;
    if (i > i1 && img[i-1][j]-'A'==c && !beenthere[i-1][j])
        visit(i-1,j,c,i1,j1,i2,j2);
    if (i < i2 && img[i+1][j]-'A'==c && !beenthere[i+1][j])
        visit(i+1,j,c,i1,j1,i2,j2);
    if (j > j1 && img[i][j-1]-'A'==c && !beenthere[i][j-1])
        visit(i,j-1,c,i1,j1,i2,j2);
    if (j < j2 && img[i][j+1]-'A'==c && !beenthere[i][j+1])
        visit(i,j+1,c,i1,j1,i2,j2);
}

bool is_PCL(int i1, int j1, int i2, int j2)
{
    int num_colors = 0;
    int color_count[26] = {0};
    for (int i=i1; i<=i2; i++)
        for (int j=j1; j<=j2; j++)
            beenthere[i][j] = false;
    for (int i=i1; i<=i2; i++)
        for (int j=j1; j<=j2; j++)
            if (!beenthere[i][j]) {
                int c = img[i][j] - 'A';
                if (color_count[c] == 0) num_colors++;
                color_count[c]++;
                visit(i,j,c,i1,j1,i2,j2);
            }
    if (num_colors != 2) return false;
    bool found_one=false, found_many=false;
    for (int i=0; i<26; i++) {
        if (color_count[i] == 1) found_one = true;
        if (color_count[i] > 1) found_many = true;
    }
    return found_one && found_many;
}

// is x in y?
bool PCL_in_PCL(int x, int y)
{
    return V[x].i1 >= V[y].i1
           && V[x].i2 <= V[y].i2
           && V[x].j1 >= V[y].j1
           && V[x].j2 <= V[y].j2;
}

bool PCL_maximal(int x)
{
    for (int i=0; i<V.size(); i++)
        if (i!=x && PCL_in_PCL(x,i)) return false;
    return true;
}

int main(void)
{
    ifstream fin ("where.in");
    ofstream fout ("where.out");
    cin >> N;
    for (int i=0; i<N; i++)
        cin >> img[i];
    for (int i1=0; i1<N; i1++)
        for (int j1=0; j1<N; j1++)
            for (int i2=i1; i2<N; i2++)
                for (int j2=j1; j2<N; j2++)
                    if (is_PCL(i1,j1,i2,j2)) {
                        PCL p = {i1,j1,i2,j2};
                        V.push_back(p);
                    }
    int answer = 0;
    for (int i=0; i<V.size(); i++)
        if (PCL_maximal(i)) answer++;
    cout << answer << "\n";

    for(int i = 0; i < V.size(); i++)
        cout << V[i].i1 << " " << V[i].j1 << " " << V[i].i2 << " " << V[i].j2 << endl;

    return 0;
}*/