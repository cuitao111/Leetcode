#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution{
public:
    int getBoxNum(int x, int y){
        int max_num = (x + y) / 3;
        
        if(max_num  < min(x, y)){
            //如果max_num小，则必然可以填满盒子
            return max_num;
        }else{
            //max_num大，则说明出现了xxx yyy的组合，下限由min(x, y)决定
            return min(x, y);
        }
        
    }

};


int main(){
    int T;
    cin >> T;
    Solution * solu = new Solution();
    for(int i = 0; i < T; i++){
        int x, y;
        cin >> x >> y;
        cout << solu->getBoxNum(x, y) << endl;
    }
    return 0;
}

