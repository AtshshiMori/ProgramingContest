#include <bits/stdc++.h>
using namespace std;
bool DEBUG = false;

int main(){
    string S;
    cin >> S;
    
    vector<vector<int>> vec(S.size());
    j=-1;
    for(int i=0; i<S.size(); i++){
        if(i%3 == 0){
            j++;
        }
        vec[j].push_back(int(S[i]));
    }

    

    return 0;
}