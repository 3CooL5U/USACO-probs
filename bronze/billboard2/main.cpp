#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("billboard.in");
ofstream fout("billboard.out");

int bx1, bx2, by1, by2, tx1, tx2, ty1, ty2;

int main() {
    fin >> bx1 >> by1 >> bx2 >> by2;
    fin >> tx1 >> ty1 >> tx2 >> ty2;

    int corners = 0;
    if (ty1<by1 && by1<ty2 && tx1<bx1 && bx1<tx2) corners++;
    if (ty1<by2 && by2<ty2 && tx1<bx2 && bx2<tx2) corners++;
    if (ty1<by1 && by1<ty2 && tx1<bx2 && bx2<tx2) corners++;
    if (ty1<by2 && by2<ty2 && tx1<bx1 && bx1<tx2) corners++;

    if(corners == 0 || corners == 1){
        fout << (by2-by1)*(bx2-bx1);
    }else if(corners == 4){
        fout << 0;
    }else{
        fout << (by2-by1)*(bx2-bx1) - max(0, (min(bx2, tx2))-max(bx1, tx1)) * max(0, (min(by2, ty2))-max(by1, ty1));
    }
}