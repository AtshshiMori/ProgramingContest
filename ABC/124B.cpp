//
//  124B.cpp
//  Programing Contest
//
//  Created by 森敦史 on 2019/04/13.
//  Copyright © 2019年 森敦史. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int H[N];
    
    int max=0;
    int count=0;
    for(int i=0; i<N; i++){
        cin >> H[i];
        if(max <= H[i]){
            max = H[i];
            count++;
        }
    }
    
    cout << count << endl;
    
    
    
    return 0;
}
