#include <bits/stdc++.h>
using namespace std;



vector<int> find_all(const string str, const string subStr) {
    vector<int> result;
 
    int subStrSize = subStr.size();
    int pos = str.find(subStr);
 
    while (pos != string::npos) {
        result.push_back(pos);
        pos = str.find(subStr, pos + subStrSize);
    }
 
    return result;
}


int main(){
    int N;

    cin >> N;
    string s[N];
    int count[N];
    int lastA = 0;
    int firstB = 0;
    int bothAB = 0;
    int ans = 0;

    for(int i = 0; i < N; i++) {
        cin >> s[i];

        count[i] = find_all(s[i], "AB").size();
        if(*(s[i].end()-1) == 'A' && *s[i].begin() == 'B'){
            bothAB++;
        }else if(*(s[i].end()-1) == 'A'){
            lastA++;
        }else if(*s[i].begin() == 'B'){
            firstB++;
        }

        ans += count[i];
    }
    if(lastA != 0 || firstB != 0){
        ans += bothAB;
        ans += min(lastA, firstB);

    }else if(bothAB == 0){
        
    }else{
        ans += bothAB - 1;
    }

    
    cout << ans << endl;
    

    // for(int i = 0; i < N; i++) {
    //     cout << count[i] << endl;
    // }
    // cout << bothAB << endl;
    // cout << lastA << endl;
    // cout << firstB << endl;


    return 0;
}
