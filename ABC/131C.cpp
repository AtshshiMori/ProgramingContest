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

long long getLcm(long long a, long long b){
    long long gcd = getGcd(a, b);
    
    return a/gcd*b;
}


int main(){
    long long A, B, C, D;

    cin >> A >> B >> C >> D;

    A--;
    long long cntC1 = A / C;
    long long cntC2 = B / C;
    long long cntC = cntC2 - cntC1;

    long long cntD1 = A / D;
    long long cntD2 = B / D;
    long long cntD = cntD2 - cntD1;

    long long CD = getLcm(C, D);
    long long cntCD1 = A / CD;
    long long cntCD2 = B / CD;
    long long cntCD = cntCD2 - cntCD1;

    // cout << cntC << endl;
    // cout << cntD << endl;
    // cout << cntCD << endl;

    cout << B - A - cntC - cntD + cntCD << endl;

    return 0;
}