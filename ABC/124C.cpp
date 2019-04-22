//
//  124C.cpp
//  Programing Contest
//
//  Created by 森敦史 on 2019/04/13.
//  Copyright © 2019年 森敦史. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    
    int count1 = 0;
    int count2 = 0;
    for(int i=0; i<S.length(); i++){
        if(i % 2==0){
            if(S[i] == '0')count1++;
        }else{
            if(S[i] == '1')count1++;
        }
    }
    
    for(int i=0; i<S.length(); i++){
        if(i % 2==0){
            if(S[i] == '1')count2++;
        }else{
            if(S[i] == '0')count2++;
        }
    }
    
    cout << min(count1, count2) << endl;
    
    return 0;
}
