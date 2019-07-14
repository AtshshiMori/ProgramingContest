#include <bits/stdc++.h>
using namespace std;

int main(){
    int L;
    cin >> L;

    vector<int> pow2(21);
    pow2[0] = 1;
    for(int i = 1; i <= 20; i++) {
        pow2[i] = 2 * pow2[i-1];
    }

    int stop = 0;
    for(int i = 0; i <= 20; i++) {
        if(L-1 < pow2[i]){
            stop = i;
            break;
        }
    }

    // 頂点数 と 辺の数
    cout << stop << " " << (stop-2) * 2 + 4 << endl;

    // 頂点１から頂点２は例外として作成
    cout << 1 << " " << 2 << " " << 0 << endl;
    cout << 1 << " " << 2 << " " << 1 << endl;

    if(L > 2){
        cout << 1 << " " << 2 << " " << 2 << endl;
    }
    if(L > 3){
        cout << 1 << " " << 2 << " " << 3 << endl;
    }

    // 頂点２からLまでを作る
    for(int i=2; i < stop; i++){
        cout << i << " " << i+1 << " " << 0 << endl;
    }

    for(int i=2; i < stop; i++){
        cout << i << " " << i+1 << " " << pow2[i] << endl;
    }
    return 0;
}