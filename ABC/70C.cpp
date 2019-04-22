//
//  70C.cpp
//  Programing Contest
//
//  Created by 森敦史 on 2019/04/16.
//  Copyright © 2019年 森敦史. All rights reserved.
//

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
    
    long long T[N];
    for(int i=0; i < N; i++){
        cin >> T[i];
    }
    
    long long lcm=1;
    for(int i=0; i<N; i++){
        lcm = getLcm(T[i], lcm);
    }
    
    cout << lcm << endl;
    
    return 0;
}
