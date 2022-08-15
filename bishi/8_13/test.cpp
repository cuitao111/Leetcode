#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void RevertNums(vector<int> & nums){
    int n = nums.size();
    if(n == 1){
        cout << nums[0] <<endl;
    }
    if(n == 2){
        cout << nums[1] <<endl;
    }
    deque<int> ret;
    ret.push_back(nums[n - 2]);
    ret.push_back(nums[n - 1]);
    int tmp;
    for(int i = n -3; i >=0 ; i--){
        //插入到队列头部，再把队尾两个拿到队头
        ret.push_front(nums[i]);
        //把队尾两个数拉到队前
        for(int j = 0; j < 2; j++){
            tmp = ret.back();
            ret.pop_back();
            ret.push_front(tmp);
        }
    }
    for(int i= 0; i <n; i++){
        cout << ret[i] <<endl;
    }
}


int main(){
    vector<int> input{1,2,3,4};
    RevertNums(input);
    cin.get();
    return 0;
}