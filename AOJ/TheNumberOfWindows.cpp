//
//  TheNumberOfWindows.cpp
//  Programing Contest
//
//  Created by 森敦史 on 2019/04/14.
//  Copyright © 2019年 森敦史. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,Q;
    cin >> N >> Q;
    
    long long a[N];
    long long x[Q];
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    for(int i=0; i<Q; i++){
        cin >> x[i];
        
        int right=0;
        long long count=0;
        long long sum=0;
        for(int left=0; left<N; left++){
            
            while(right < N){
                if(sum + a[right] > x[i]){
                    break;
                }
                sum += a[right];
                right++;
            }
            
            count += right - left;
            
            if(left == right){
                right++;
            }else{
                sum -= a[left];
            }
            
        }
        cout << count << endl;
    }
    
    
    return 0;
}
