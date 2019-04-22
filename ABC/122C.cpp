//
//  122C.cpp
//  Programing Contest
//
//  Created by 森敦史 on 2019/04/10.
//  Copyright © 2019年 森敦史. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    int l[Q],r[Q];
    for(int i=0; i<Q; i++){
        cin >> l[i] >> r[i];
    }
    
    vector<int> pos_ac(N, 0);//nまでにいくつACがあるか
    int pos =(int)S.find("AC");
    int count = 0;
    
    //O(N)
    while(pos != string::npos){
        pos_ac[pos] = ++count;
        pos+=2;
        
        pos = (int)S.find("AC", pos);
    }
    
    //O(N)
    count = 0;
    for(int i=0; i<N; i++){
        if(pos_ac[i] != 0){
            count = pos_ac[i];
        }
        pos_ac[i] = count;
    }
    
    //O(Q)
    for(int i=0; i<Q; i++){
        if(l[i] == 0)cout << pos_ac[r[i]] << endl;
        if(r[i] == 0)cout << 0 << endl;
        cout << pos_ac[r[i]-2] - pos_ac[l[i]-2] << endl;
    }
    
    return 0;
}
