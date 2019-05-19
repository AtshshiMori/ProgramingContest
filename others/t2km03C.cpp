#include <bits/stdc++.h>
using namespace std;

int main(){

    string S;
    cin >> S;

    long long K;
    cin >> K;

    int not1_pos;
    int i=0;
    while(S[i] == '1'){
        i++;
    }
    not1_pos = i;

    if(not1_pos < K){
        cout << S[not1_pos] << endl;
    }else{
        cout << 1 << endl;
    }

    return 0;
}