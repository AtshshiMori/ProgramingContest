#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;

    cin >> N;

    long long upper = N / (sqrt(N+1) + 1);
    long long  ans = 0;
    for(long long i = 1; i < upper; i++) {
        if(N % i == 0){
           ans += N/i - 1;
        }
    }
    cout << ans << endl;

    return 0;
}