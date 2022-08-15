#include <iostream>
#include <vector>
#include <string>
using namespace std;



int getBoxNum(int x, int y){
    //交换xy使得 x<y
    if(x > y){
        swap(x, y);
    }
    if(2*x > y){
        //需要分配
        int t = x - y/2;
        if(t >= 2 && y%2 == 1){
            return y/2 + 1;
        }else{
            return y/2;
        }
    }else{
        //box数量由x决定
        return x;
    }
}


int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int x, y;
        cin >> x >> y;
        if(x > y){
            swap(x, y);
        }
        if(2*x > y){
            //需要分配
            int t = x - y/2;
            if(t >= 2 && y%2 == 1){
                cout << y/2 + 1 << endl;
            }else{
                cout << y/2 << endl;
            }
        }else{
            //box数量由x决定
            cout << x << endl;
        }
    }
    return 0;
}