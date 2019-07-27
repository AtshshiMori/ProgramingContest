#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    long long a[N];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // 何種類の数字が出てくるか調べる
    int count = 0;
    long long memo[3], memo_count[3];
    memo[0] = -1;
    memo[1] = -1;
    memo[2] = -1;
    memo_count[0] = 0;
    memo_count[1] = 0;
    memo_count[2] = 0;

    for(int i = 0; i < N; i++) {
        if(a[i] != memo[0] && a[i] != memo[1] && a[i] != memo[2]){
            memo[count] = a[i];
            memo_count[count]++;
            count++;
        }else if(a[i] == memo[0]){
            memo_count[0]++;
        }else if(a[i] == memo[1]){
            memo_count[1]++;
        }else if(a[i] == memo[2]){
            memo_count[2]++;
        }
    }

    // ３種類以上使ったら無理
    if(count > 3){
        cout << "No" << endl;
        return 0;
    }

    if(count == 3){
        if((memo[0] ^ memo[1]) == memo[2]){
            if(abs(memo_count[0] - memo_count[1]) > 1
            || abs(memo_count[1] - memo_count[2]) > 1
            || abs(memo_count[0] - memo_count[2]) > 1){
                cout << "No" << endl;
            }else{
                cout << "Yes" << endl;
            }
        }else{
            cout << "No" << endl;
        }
    }else if(count == 2 || count == 1){
        if(memo[0] == 0 || memo[1] == 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        cout << "No" << endl;
    }
    return 0;
}