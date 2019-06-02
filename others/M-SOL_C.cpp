#include <bits/stdc++.h>
using namespace std;

int comb(int n, int r){
    if(r == 0)return 1;
    return comb(n, r-1) * (n-r+1) / r;
}

int main(){
    int N,A,B,C;
    cin >> N >> A >> B >> C;

    double pa = A/100;
    double pb = B/100;
    double pan = 1 - pa;
    double pbn = 1 - pb;
    
    double ans = 0;
    while(true){

    }
    return 0;
}