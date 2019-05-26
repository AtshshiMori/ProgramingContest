#include <bits/stdc++.h>
using namespace std;

struct Res {
    int num;
    string S;
    int P;

    // 演算子オーバーロードで比較関数を定義
    bool operator<(const Res& another) const {
        if (S != another.S)
        return S < another.S; // 高い順に並べたいので演算子を逆に
        if (P != another.P)
        return P > another.P; // 同様に比較演算子を反転
    }
};

int main(){
    int N;
    cin >> N;

    string S[N];
    int P[N];
    vector<Res > p(N);

    for(int i = 0; i < N; i++) {
        cin >> S[i] >> P[i];
        Res tmp = {i, S[i], P[i]};
        p[i] = tmp;
    }

    // firstが小さい順、secondが小さい順にソート
    sort(p.begin(), p.end());

    for (int i = 0; i < N; i++) {
        cout << p[i].num + 1 << endl;
    }
    

    return 0;
}