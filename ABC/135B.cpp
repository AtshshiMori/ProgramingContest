#include <bits/stdc++.h>
using namespace std;
bool DEBUG = false;


int main(){
    int N;
    cin >> N;
    int p[N];
    for(int i = 0; i < N; i++) {
        cin >> p[i];
    }


    // 最初の判定
    bool success = true;
    for(int k = 0; k < N-1; k++) {
        if(p[k] > p[k+1]){
            success = false;
        }
    }
    if(success){
        cout << "YES" << endl;
        return 0;
    }

    for(int i = 0; i < N-1; i++) {
        for(int j = i+1; j < N; j++) {
            bool success = true;
            int q[N];
            for(int k = 0; k < N; k++) {
                q[k] = p[k];
            }

            int tmp = q[i];
            q[i] = q[j];
            q[j] = tmp;

            for(int k = 0; k < N-1; k++) {
                if(q[k] > q[k+1]){
                    success = false;
                }
            }

            if(success){
                if(DEBUG){
                    for(int k = 0; k < N; k++) {
                        cout << q[k] << endl;
                    }
                }
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    
    cout << "NO" << endl;
    return 0;
}