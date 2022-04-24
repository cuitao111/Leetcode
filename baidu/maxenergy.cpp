#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
(n, 2)大小数组
数组0位置之和不能大于w，求最大1位置之和
*/
bool compare(const vector<int> a,const vector<int> b){
    if(a[1] > b[1]){
        // 按能量从大到小

    }
}

class Solution{
public:
    int getMaxEnergy(vector<vector<int>> & nums, int w){
        sort(nums.begin(), nums.end(), compare);
    }
};


int main(){
    int n, w;
    cin >> n >> w;
    
}