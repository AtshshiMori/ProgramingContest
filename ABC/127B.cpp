#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,D,x2000;
    cin >> r >> D >> x2000;

    int x = x2000;
    for(int i = 1; i <= 10; i++) {
        x = r*x - D;
        cout << x << endl;
    }

    return 0;
}