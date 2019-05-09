/********************************
  
  nCr program
    Input is n,r.
    Output is count of combination.
********************************/

#include <bits/stdc++.h>
using namespace std;

int comb(int n, int r){
    if(r == 0)return 1;
    return comb(n, r-1) * (n-r+1) / r;
}

int main(){
    int N,R;
    cin >> N >> R;

    cout << comb(N,R) << endl;
return 0;
}