/********************************
  Prime Factorization
    input is P (prime number)
    output is ret (array of prime and expornential)
********************************/

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
    int P;
    cin >> P;

    vector<pair<int,int>> x = primeFact(P);
    for(auto v : x){
        cout << v.first << " " << v.second << endl;
    }
    return 0;
}