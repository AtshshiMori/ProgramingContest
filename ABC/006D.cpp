#include <bits/stdc++.h>
using namespace std;

long long* binarySearch(long long x, long long* left, long long* right){
    
    while(right - left > 1){
        long long *ptr = left + (right - left) / 2;
        if( x < *ptr ){
            right = ptr;
        }else{
            left = ptr;
        }  
    }
    if(*left < x)return right;
    else return left;
}

int main(){
    int N;
    cin >> N;

    long long a[N];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    long long dp[N];
    int last = 1;
    dp[0] = a[0];
    for(int i = 1; i < N; i++) {
        if(dp[last-1] < a[i]){
            dp[last++] = a[i];
            continue;
        }
        long long* p = binarySearch(a[i], dp, dp+last);
        *p = a[i];
    }

    cout << N - last << endl;
    return 0;
}