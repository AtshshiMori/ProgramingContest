//
//  124D.cpp
//  Programing Contest
//
//  Created by 森敦史 on 2019/04/13.
//  Copyright © 2019年 森敦史. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    
    vector<int> v; // 1-0-1-.....-0-1
    int count=0;
    char now01 = '1';//最初が0だった時にv[0]に0が入る
    
    for(int i=0; i<N; i++){
        if(S[i]==now01){
            count++;
            
        }else{
            v.push_back(count);
            count = 1;
            now01 = S[i];
        }
    }
    if(count != 0)v.push_back(count);
    if(v.size() % 2 == 0)v.push_back(0); //1-0-1-...-0の時に最後に0を入れる
    
    int L = (int)v.size();
    
    vector<int> sum_array;
    int sum=0;
    for(int i=0; i<L; i++){
        sum += v[i];
        sum_array.push_back(sum);
    }
    
    int max_v=0;

    if(K*2 >= L){
        max_v = max(max_v, sum_array[L-1]);
    }
    
    for(int i=0; i<L-K*2; i+=2){
        if(i==0){
            max_v = max(max_v, sum_array[i+K*2]);
        }else{
            max_v = max(max_v, sum_array[i+K*2] - sum_array[i-1]);
        }
    }
    
    cout << max_v << endl;

    return 0;
}

