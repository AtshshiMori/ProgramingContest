#include <bits/stdc++.h>
using namespace std;


int main(){

    for(int i = 1; i <= 100; i++) {
        if(i%3 == 0 && i%5 == 0){
            cout << "FizzBuzz";
        }else if(i%3 == 0){
            cout << "Fizz";
        }else if(i%5 == 0){
            cout << "Buzz";
        }else{
            cout << i;
        }

        if(i != 100)cout << ",";
    }
    return 0;
}


//整数nを入力とし、2で割り切れる回数だけ「に」を付け、9で割り切れる回数だけ「く」を付けて返し、それぞれ一回の時だけ「肉！！」を返す関数
// 2と9をいくつ因数に持つかが視覚的に分かって便利です。
string check29(int n){
    string str = "";
    while(n % 2 == 0){
        str += "に";
        n /= 2;
    }
    while(n % 9 == 0){
        str += "く";
        n /= 9;
    }

    if(str == "にく")return "肉！！";
    return str;
}

int main(){
    int a = 84600;
    int b = 18;

    cout << check29(a) << endl; //  にににく
    cout << check29(b) << endl; //  肉！！
    return 0;
}




