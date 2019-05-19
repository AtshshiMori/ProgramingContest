#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    K--;
    string S;
    cin >> S;

    char c = S[K];
    S[K] = c + 'a' - 'A';

    cout << S << endl;
    return 0;
}