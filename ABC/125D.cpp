#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;

    vector<long long> a(N);
    int count = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++){
        cin >> a[i];
        if(a[i] < 0){
            count++;
            a[i] = -a[i];
        }
        sum += a[i];
    }

    if(count % 2 == 0){
        cout << sum << endl;
    }else{
        int min_v = *min_element(a.begin(), a.end());
        cout << sum - min_v*2 << endl;
    }

    return 0;
}