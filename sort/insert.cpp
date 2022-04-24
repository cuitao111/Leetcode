#include <iostream>
#include <vector>

using namespace std;

/*
假设前面有序
*/

void insert_sort(vector<int> & nums){
    int n = nums.size();
    int left = 0;
    //假设left之前已经是有序的
    int cur = left + 1;
    while (cur < n)
    {
        // 向前找到小于cur的值
        int p = cur - 1;
        while (p >= 0)
        {
            if(nums[p] < nums[cur]){
                break;
            }
            p--;
        }
        // cur与p+1位置交换
        int temp = nums[cur];
        nums[cur] = nums[p + 1];
        nums[p + 1] = temp;
        cur++;
    }
}

int main(){
    vector<int> nums{1,5,6,8,7,9};
    insert_sort(nums);

    for(int i =0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cin.get();

}