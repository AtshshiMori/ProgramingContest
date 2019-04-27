#include <bits/stdc++.h>
using namespace std;

long long getGcd(long long a, long long b){
    if(a < b){
        long long tmp = a;
        a = b;
        b = tmp;
    }
    
    if(b == 0)return a;
    
    return getGcd(b, a%b);
}

int main(){

    int N;
    cin >> N;

    long long a[N];
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }

    long long gcd_s[N];
    gcd_s[0] = a[0];
    for(int i = 1; i < N; i++) {
        gcd_s[i] = getGcd(gcd_s[i-1], a[i]);
    }

    long long gcd_e[N];
    gcd_e[N-1] = a[N-1];
    for(int i = N-2; i >= 0; i--) {
        gcd_e[i] = getGcd(gcd_e[i+1], a[i]);
    }

    long long ans;
    ans = gcd_e[1];
    ans = max(ans, gcd_s[N-2]);
    for(int i = 1; i < N-1; i++) {
        ans = max(ans, getGcd(gcd_s[i-1], gcd_e[i+1]));
    }
    
    cout << ans << endl;

    return 0;
}