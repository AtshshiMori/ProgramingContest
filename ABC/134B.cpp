#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,D;
    cin >> N >> D;

    int range = 2*D + 1;

    cout << (N-1) / range + 1 << endl;
    return 0;
}