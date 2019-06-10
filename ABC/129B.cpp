#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int W[N];
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> W[i];
        sum += W[i];
    }
    int ans = 99999;
    for(int i = 1; i < N; i++) {
        int x=0;
        for(int j = 0; j < i; j++) {
            x += W[j];
        }
        int y = sum - x;
        ans = min(ans, abs(x - y));
    }
    cout << ans << endl;
    

    return 0;
}