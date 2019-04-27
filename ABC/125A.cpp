#include <bits/stdc++.h>
using namespace std;

int main(){

    int A,B,T;
    cin >> A >> B >> T;

    int count = T/A;
    cout << B * count << endl;

    return 0;
}