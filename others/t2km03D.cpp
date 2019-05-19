#include <bits/stdc++.h>
using namespace std;

struct Train{
    int L;
    int R;
};

bool cmp(const Train &a, const Train &b)
{
    return a.L < b.L;
}

int* binarySearch(int x, int* left, int* right, bool isFirst = true){
    int* itr;
    const int* Left = left;
    const int* Right = right;

    while(right - left > 1){
        int *ptr = left + (right - left) / 2; //偶数の時は左側
        if( x < *ptr ){
            right = ptr;
        }else{
            left = ptr;
        }  
    }
    

    if(isFirst){
        if(*left < x){
            itr = right;
        }else{
            itr = left;
        }
        if(itr != Left){
            while(*(itr-1) == *itr)itr--;
        }

    }else{
        if(x < *right){
            itr = left;
        }else{
            itr = right;
        }
        while(*(itr+1) == *itr)itr++;
    }
    return itr;
}

int main(){
    int N,M,Q;
    cin >> N >> M >> Q;

    vector<Train> train(M); //列車
    for(int i = 0; i < M; i++) {
        int l,r;
        cin >> l >> r;

        train[i] = Train{l,r};
    }


    int p[Q], q[Q];
    for(int i = 0; i < Q; i++) {
        cin >> p[i] >> q[i];
    }

    sort(train.begin(), train.end(), cmp);

    int L[M],R[M];
    for(int i = 0; i < M; i++) {
        L[i] = train[i].L;
        R[i] = train[i].R;
    }
    cout << "L:" << endl;
    for(int i = 0; i < M; i++) {
        cout << L[i] << " ";
    }
    cout << endl;
    cout << "R:" << endl;
    for(int i = 0; i < M; i++) {
        cout << R[i] << " ";
    }
    cout << endl;


    for(int i = 0; i < Q; i++) {
        
        int* ite_first = binarySearch(p[i], L, L+M, true);
        int* ite_last = binarySearch(q[i], R, R+M, false);

        int index_first = ite_first - L;
        int index_last = ite_last - R;

        cout << "p:" << p[i] << " q:" << q[i] << endl;

        cout << "index_first:" << index_first << endl;
        cout << "index_last:" << index_last << endl;

        cout << index_last - index_first + 1<< endl;
    }


    return 0;
}