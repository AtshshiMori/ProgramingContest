//
//  0420A.cpp
//  Programing Contest
//
//  Created by 森敦史 on 2019/04/20.
//  Copyright © 2019年 森敦史. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    
    int A,B,C;
    
    cin >> A >> B >> C;
    
    if((A < C && B > C) || (A > C && B < C)){
        cout << "Yes" << endl;
}else{
     cout << "No" << endl;
    }
    
    return 0;
    
}
