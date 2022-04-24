#include <iostream>
#include <vector>

using namespace std;


void buble_sort(vector<int> & nums){
    int n = nums.size();
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(nums[j] > nums[j + 1]){
                // 把大的值放到后面
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j+1] = temp;
            }
        }
    }
}

int main(){
    vector<int> nums{1,5,6,8,7,9};
    buble_sort(nums);

    for(int i =0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cin.get();

}