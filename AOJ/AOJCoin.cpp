//
//  AOJCoin.cpp
//  Programing Contest
//
//  Created by 森敦史 on 2019/04/09.
//  Copyright © 2019年 森敦史. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

#define INF 999999

int main() {
    int n,m;
    cin >> n >> m;
    
    int c[m];
    for(int i=0; i<m; i++){
        cin >> c[i];
    }
    
    int dp[m][n+1];
    for(int i=0; i<m; i++){
        for(int j=0; j<n+1; j++){
            dp[i][j] = INF;
        }
    }
    
    //そのコイン１種類で表せるものを先に埋めておく
    for(int i=0; i<m; i++){
        for(int j=0; j<n+1; j++){
            if(j % c[i] == 0){
                dp[i][j] = j/c[i];
            }
        }
    }
    
    for(int i=1; i<m; i++){
        for(int j=0; j<n+1; j++){
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if(j-c[i] > 0){
                dp[i][j] = min(dp[i][j], dp[i][j-c[i]] + 1);
            }
        }
    }
    
    cout << dp[m-1][n] << endl;
    return 0;
}
