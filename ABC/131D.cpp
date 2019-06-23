#include <bits/stdc++.h>
using namespace std;

struct Work{
    long long A;
    long long B;
};

bool cmp(const Work &a, const Work &another) {
    return a.B < another.B;
};


int main(){
    int N;

    cin >> N;
    vector<long long> A(N), B(N);
    vector<Work> works(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];

        Work w = {A[i], B[i]};
        works[i] = w;
    }

    sort(works.begin(), works.end(), cmp);

    long long t = 0;

    for(int i = 0; i < N; i++){
        t += works[i].A;

        if(t > works[i].B){
            cout << "No" << endl;
            return 0;
        }
        // cout << works[i].B << endl;
    }

    cout << "Yes" << endl;

    return 0;
}