#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    int a[M];
    for(int i = 0; i < M; i++) {
        cin >> a[i];
        if(i != 0 && a[i] - a[i-1] <= 1){
            cout << 0 << endl;
            return 0;
        }
    }

    long long num[N+1];
    num[0] = 1;
    num[1] = 1;
    for(int i = 2; i < N+1; i++) {
        num[i] = (num[i-1] + num[i-2]) % 1000000007;
    }

    int now = 0;
    long long ans = 1;
    int i=0;
    for(int i = 0; i < M; i++) {
        ans = (ans * num[a[i] - now - 1]) % 1000000007;
        now = a[i]+1;
    }
    ans = (ans * num[N - now]) % 1000000007;
    
    cout << ans << endl;
    

    return 0;
}