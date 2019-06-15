/********************************
  
  Binary Indexed Tree
    累積和の応用形
    Segment Tree の機能縮小版（つまりSegmentTreeでもいいが、実装はこっちの方が楽）
    部分和を高速に求めることができ、さらに変更にも強い。累積和は変更に弱い。
    http://hos.ac/slides/20140319_bit.pdf
********************************/

#include <bits/stdc++.h>
using namespace std;

class BIT {
    public:
        int length;
        vector<int> bit;

        BIT(int n){
            length = n;
            bit = vector<int>(length+1,0);
        }

        void add(int a, int w) {
            for (int x = a; x <= length; x += x & -x) bit[x] += w;
        }

        int sum(int a) {
            int ret = 0;
            for (int x = a; x > 0; x -= x & -x){
                ret += bit[x];
            }
            return ret;
        }

        void show(){
            cout << "show:" << length << endl;
            for(int i = 0; i < length; i++) {
                cout << bit[i] << endl;
            }
        }
};


/*  
   例として転倒数の問題を解く
   転倒数についてはここが分かりやすい
   https://note.mu/vain0x/n/n0037d6468812
*/
int main(){
    int N;
    cin >> N;

    int a[N];
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    const int MAX = 100000;
    BIT bit = BIT(MAX);
    int ans = 0;
    for(int i=0; i<N; i++){
        bit.add(a[i], 1);
        ans += bit.sum(MAX) - bit.sum(a[i]);
    }

    cout << ans << endl;

    return 0;
}