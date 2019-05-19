#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> primeFact(int p){
    vector<pair<int, int>> ret;         //{<素数p1, 指数部分e1>, <素数p2, 指数部分e2>,....,<素数pk, 指数部分ek>} 
    int root = sqrt(p);                 //素数pの平方根まで回す
    for (int i = 2; i <= root; i++){
        int exp = 0;                    //指数部分
        while(p % i == 0){
            exp++;
            p /= i;
        }

        if(exp != 0) ret.push_back(make_pair(i, exp));
    }
    return ret;
}

int main(){
    int N;

    cin >> N;

    int cnt = 0;


    for(int i = 1; i <= N; i+=2) {

        int divNum = 1;    

        vector<pair<int, int>> n_pri = primeFact(i);

        for (int j = 0; j < n_pri.size(); j++){
            int r = n_pri[j].second;
            divNum *= (r+1);
        }

        if(divNum == 8){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}