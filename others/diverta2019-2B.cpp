#include <bits/stdc++.h>
using namespace std;

struct Count {
    long long x;
    long long y;
    int count;
};

int main(){
    int N;
    cin >> N;

    long long x[N], y[N];
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    vector<Count> vec;

    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++){
            long long dx = x[i] - x[j];
            long long dy = y[i] - y[j];

            bool find = false;
            for(int k = 0; k < vec.size(); k++){
                Count c = vec[k];
                if(c.x == dx && c.y == dy){
                    vec[k].count++;
                    find = true;
                }
                if(c.x == -dx && c.y == -dy){
                    vec[k].count++;
                    find = true;
                }
            }

            if(find == false){
                Count a = {dx, dy, 1};
                Count b = {-dx, -dy, 1};
                vec.push_back(a);
                vec.push_back(b);
            }
            

        }
    }
    
    int maxv = 0;
    for(int k = 0; k < vec.size(); k++){
        maxv = max(maxv, vec[k].count);
    }


    cout << N - maxv << endl;

    return 0;
}