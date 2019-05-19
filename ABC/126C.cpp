#include <bits/stdc++.h>
using namespace std;

int main(){
    double N,K;
    cin >> N >> K;

    double ans;

    double pow2[20];
    pow2[0] = 1;
    for(int i = 1; i <= 19; i++) {
        pow2[i] = pow2[i-1]*2;
    }

    for(int n = 1; n <= N; n++) {
        if(n >= K){
            ans += 1;
            continue;
        }

        double tmp = K/n;

        int j=0;
        while(tmp > pow2[j]){
            j++;
        }
        ans += (double)1/pow2[j];
    }
    
    cout << std::setprecision(12) <<  (double)ans/N << endl;

    return 0;
}