#include <iostream>
#include <vector>

using namespace std;

void fast_sort(vector<int> & nums, int left, int right){
    int n = nums.size();
    if(left >= right){
        return;
    }
    // 把left放到正确的位置mid，然后递归调用left ~ mid - 1 mid+1 ~ right
    int mid = left + 1;
    int l =  left + 1;
    while (mid <= right)
    {
        if(nums[mid] < nums[left]){
            // 交换mid和l
            int temp = nums[mid];
            nums[mid] = nums[l];
            nums[l] = temp;
            l++;
        }
        mid++;
    }
    l--;
    // 交换l - 1 和 left
    int temp = nums[l];
    nums[l] = nums[left];
    nums[left] = temp;
    // 递归调用
    fast_sort(nums, left , l - 1);
    fast_sort(nums, l + 1, right);
    
}


int main(){
    vector<int> nums{1,5,6,8,7,9};
    fast_sort(nums, 0 , nums.size() - 1);

    for(int i =0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cin.get();

}