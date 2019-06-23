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
    int N;
    cin >> N;

    cout << N << endl;
    return 0;
}