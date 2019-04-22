//
//  124A.cpp
//  Programing Contest
//
//  Created by 森敦史 on 2019/04/13.
//  Copyright © 2019年 森敦史. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    
    int sum=0;
    if(A < B){
        sum += B;
        B--;
    }else{
        sum += A;
        A--;
    }
    if(A < B){
        sum += B;
        B--;
    }else{
        sum += A;
        A--;
    }
    cout << sum << endl;
    
    
    
    return 0;
}
