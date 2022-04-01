#include <iostream>
#include <vector>

using namespace std;

/*
假设数组已经存在一个树中，需要调整父节点小于子节点
最后一个有子节点的位置开始调整 len/2
*/

void Heap_build(vector<int> & nums, int i, int n){
    int leftChild = 2 * i + 1;
    int flag = leftChild;
    if(leftChild < n){
        int rightChild = leftChild + 1;
        if(rightChild < n){
            if(nums[rightChild] < nums[leftChild]){
                flag = rightChild;
            }
        }
        if(nums[flag] < nums[i]){
            int temp = nums[flag];
            nums[flag] = nums[i];
            nums[i] = temp;
            // 重建flag以下的子树
            Heap_build(nums,flag, n);
        }
    }
}


void Heap_sort(vector<int> & nums){
    int n =  nums.size();
    for(int i = n / 2; i >= 0; i--){
        Heap_build(nums, i, n);
    }
    for(int i = n - 1; i >=0; i--){
        int temp = nums[0];
        nums[0] = nums[i];
        nums[i] = temp;
        Heap_build(nums, 0, i);
    }
}

int main(){
    vector<int> nums{1,5,6,8,7,9};
    Heap_sort(nums);

    for(int i =0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cin.get();

}