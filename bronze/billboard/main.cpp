#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("billboard.in");
ofstream fout("billboard.out");

int bx1, bx2, by1, by2,
        ax1, ax2, ay1, ay2,
        tx1, tx2, ty1, ty2;

int main() {
    fin >> bx1 >> by1 >> bx2 >> by2;
    fin >> ax1 >> ay1 >> ax2 >> ay2;
    fin >> tx1 >> ty1 >> tx2 >> ty2;

    int overlap1 = max(0, (min(bx2, tx2))-max(bx1, tx1)) * max(0, (min(by2, ty2))-max(by1, ty1));
    int overlap2 = max(0, (min(ax2, tx2))-max(ax1, tx1)) * max(0, (min(ay2, ty2))-max(ay1, ty1));
    int area = (bx2-bx1) * (by2-by1) + (ax2-ax1) * (ay2-ay1);

    fout << area - overlap1 - overlap2;
}