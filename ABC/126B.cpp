#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    int num = atoi(S.c_str());

    int num1 = num / 100;
    int num2 = num % 100;

    int num1check;
    int num2check;

    /*
    1~12ならM    2
    ０以外ならY   1
    その他         ０
    */

    if(num1 > 0 && num1 < 13){
        num1check = 2;
    }else{
        num1check = 0;
    }

    if(num2 > 0 && num2 < 13){
        num2check = 2;
    }else{
        num2check = 0;
    }

    if(num1check == 2 && num2check == 2){
        cout << "AMBIGUOUS" << endl;
    }else if(num1check == 2){
        cout << "MMYY" << endl;
    }else if(num2check == 2){
        cout << "YYMM" << endl;
    }else{
        cout << "NA" << endl;
    }


    return 0;
}