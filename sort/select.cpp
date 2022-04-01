#include <iostream>
#include <vector>

using namespace std;

void select_sort(vector<int> & nums){
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(nums[i] > nums[j]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}


int main(){
    vector<int> nums{1,5,6,8,7,9};
    select_sort(nums);

    for(int i =0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cin.get();

}