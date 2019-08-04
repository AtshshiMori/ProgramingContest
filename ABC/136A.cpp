#include <bits/stdc++.h>
using namespace std;
bool DEBUG = false;


int main(){
    int A,B,C;
    cin >> A >> B >> C;

    int ans = C - (A - B);
    if(ans < 0){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}