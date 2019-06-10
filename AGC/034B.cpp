#include <bits/stdc++.h>
using namespace std;

std::string replaceAll(std::string &replacedStr, std::string from, std::string to) {
    int pos = replacedStr.find(from);
    int toLen = to.length();
 
    if (from.empty()) {
        return replacedStr;
    }
 
    while (pos != std::string::npos) {
        replacedStr.replace(pos, from.length(), to);
        pos += toLen;
        pos = replacedStr.find(from, pos);
    }
    return replacedStr;
}

class BIT {
    public:
        int length;
        vector<int> bit;

        BIT(int n){
            length = n;
            bit = vector<int>(length+1,0);
        }

        void add(int a, int w) {
            for (int x = a; x <= length; x += x & -x) bit[x] += w;
        }

        int sum(int a) {
            int ret = 0;
            for (int x = a; x > 0; x -= x & -x){
                ret += bit[x];
            }
            return ret;
        }

        void show(){
            cout << "show:" << length << endl;
            for(int i = 0; i < length; i++) {
                cout << bit[i] << endl;
            }
        }
};


int main(){
    string s;
    cin >> s;
    
    replaceAll(s, "BC", "D");
    cout << s << endl;

    size_t c;
    while((c = s.find_first_of("B")) != string::npos){
        s.erase(c,1);
    }
    while((c = s.find_first_of("C")) != string::npos){
        s.erase(c,1);
    }
    cout << s << endl;

    BIT bit = BIT(3);
    int ans = 0;
    for(int i=0; i<s.size(); i++){
        int j;
        if(s[i] == 'A'){
            j = 1;
        }else{
            j = 2;
        }
        bit.add(j, 1);
        ans += bit.sum(3) - bit.sum(j);
    }
    cout << ans << endl;
    return 0;
}
