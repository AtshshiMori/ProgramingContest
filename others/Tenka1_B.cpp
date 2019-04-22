//
//  0420B.cpp
//  Programing Contest
//
//  Created by 森敦史 on 2019/04/20.
//  Copyright © 2019年 森敦史. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;

#define INF 999999;

int main(){
    
    
    int N;
    string S;
    
    cin >> N;
    cin >> S;
    int ans = INF;
    int count_r = 0;//右にある白い石の個数
    int count_l = 0;//左にある黒い石の個数

    for(int i=0; i<N; i++){
        if(S[i] == '.')count_r++;
    }
    ans = min(ans, count_r);
    
    for(int i=0; i<N; i++){
        if(S[i] == '#'){
            count_l++;
        }else{
            count_r--;
        }
        ans = min(ans, count_r + count_l);
    }
    
    cout << ans << endl;
    
    return 0;
    
}
