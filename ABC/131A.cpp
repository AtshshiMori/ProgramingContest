#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    string ans = "Good";

    for(int i = 0; i < 3; i++) {
        if(S[i] == S[i+1])ans = "Bad";
    }
    cout << ans << endl;
    return 0;
}