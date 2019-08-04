#include <bits/stdc++.h>
using namespace std;
bool DEBUG = false;


int main(){
    int N;
    cin >> N;
    long long H[N];
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    H[0]--;

    for(int i = 0; i < N-1; i++) {
        if(H[i+1] - H[i] < 0){
            cout << "No" << endl;
            return 0;
        }else if(H[i+1] - H[i] > 0){
            H[i+1]--;
        }
    }
    
    cout << "Yes" << endl;

    return 0;
}