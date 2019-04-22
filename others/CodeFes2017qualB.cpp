#include <bits/stdc++.h>
using namespace std;

int main(){
    
    
    long N,M;
    cin >> N >> M;

    int A[M], B[M];
    
    for(long i=0; i<M; i++){
        cin >> A[i] >> B[i];
    }

    int edge[N][N];
    for(long i = 0; i < N; i++){
        for(long j = 0; j < N; j++){
            edge[i][j] = 0;
        }
    }

    for(long i=0; i<M; i++){
        edge[A[i]-1][B[i]-1] = 1;
        edge[B[i]-1][A[i]-1] = 1;
    }

    //二部グラフ判定
    bool flag = true;
    vector<long> vertex_group(N,-1);
    stack<long> ver_stack;

    vertex_group[0] = 1;
    ver_stack.push(0);
    
    while(!ver_stack.empty()){
        long v = ver_stack.top();
        ver_stack.pop();

        for (long j = 0; j < N; j++){
            if (edge[v][j] && vertex_group[j] == vertex_group[v])
            {
                flag = false;
                break;
            }
            //枝があってかつその頂点がまだラベルが付いていないなら
            if (edge[v][j] && vertex_group[j] == -1)
            {
                vertex_group[j] = 1 - vertex_group[v];
                ver_stack.push(j);
            }
        }

        if(!flag)
            break;
    }

    // if(!flag){
    //     cout << N * (N - 1)/2 - M << endl;
    // }else{
    //     int count0 = 0;
    //     int count1 = 0;
    //     for (long i = 0; i < N; i++){
    //         if(vertex_group[i] == 0){
    //             count0++;
    //         }else if (vertex_group[i] == 1){
    //             count1++;
    //         }
    //     }

    //     int nC2_0 = count0 * (count0 - 1) / 2;
    //     int nC2_1 = count1 * (count1 - 1) / 2;
    //     cout << N * (N - 1)/2 - nC2_0 - nC2_1 - M;
    // }

    return 0;
}
