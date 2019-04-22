//
//  121C.cpp
//  Programing Contest
//
//  Created by 森敦史 on 2019/04/21.
//  Copyright © 2019年 森敦史. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

struct Shop {
    int A;
    int B;
};

bool cmp(const Shop &a, const Shop &b)
{
    return a.A < b.A;
}

int main(){
    int N,M;
    cin >> N >> M;

    long long ans = 0;
    vector<Shop> shop(N);

    for(int i=0; i<N; i++){
        cin >> shop[i].A >> shop[i].B;
    }

    sort(shop.begin(), shop.end(), cmp);

    while(M > 0){
        ans += shop[0].A;

        if(shop[0].B == 1)
            shop.erase(shop.begin());
        else
            shop[0].B -= 1;

        M--;
    }

    cout << ans << endl;
    return 0;
}
