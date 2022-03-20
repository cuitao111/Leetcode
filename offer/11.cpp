#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            if(numbers[r] > numbers[l]){
                break;
            }
            int mid = l + (r - l) / 2;
            if(numbers[mid] < numbers[l]){
                // 左侧 需要将mid包含在内
                r = mid;
            }else{
                l = mid + 1;
            }
            
        }
        return numbers[l];
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> nums{1,3,5};
    cout << solu->minArray(nums) << endl;
    cin.get();
}