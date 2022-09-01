#include <iostream>
#define ll long long
using namespace std;


int n;
ll grid[1000][1000];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int q = 0; q < n; q++)
            cin >> grid[i][q];
    int x = 0;
    for(int i = 0; i < n; i++){
        int temp[2] = {0,0};
        for(int q = 0; q < n; q++)
            temp[q % 2] += grid[i][q];
        x += max(temp[0], temp[1]);
    }
    int y = 0;
    for(int i = 0; i < n; i++){
        int temp[2] = {0,0};
        for(int q = 0; q < n; q++)
            temp[q % 2] += grid[q][i];
        y += max(temp[0], temp[1]);
    }
    cout << max(x,y);
}