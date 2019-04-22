//
//  KUPC2015.cpp
//  Programing Contest
//
//  Created by 森敦史 on 2019/04/10.
//  Copyright © 2019年 森敦史. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

#define INF 999999

int main() {
    int T;
    cin >> T;
    
    string S[T];
    
    for(int i=0; i<T; i++){
        cin >> S[i];
    }
    
    for(int i=0; i<T; i++){
        int count=0;
        int pos1 = (int)S[i].find("tokyo");
        int pos2 = (int)S[i].find("kyoto");
        int pos = 0;
        
        while(pos1 != string::npos || pos2 != string::npos){
            
            if(pos1 == string::npos)pos1 = INF;
            if(pos2 == string::npos)pos2 = INF;
            pos = min(pos1, pos2);
            count++;
            pos += 5;
            
            pos1 = (int)S[i].find("tokyo", pos);
            pos2 = (int)S[i].find("kyoto", pos);
        }
        cout << count << endl;
    }
    
    return 0;
}

