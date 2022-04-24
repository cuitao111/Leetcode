
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*最终高度
*/
bool compare(const pair<char,int>& a, const pair<char, int>& b){
    return a.second < b.second;
}

class Solution{
public:
    int getMaxEnergy(string s){
        int n = s.length();
        if(n == 0){
            return 0;
        }
        int sum = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }
        // 按从小到大排序
        sort(mp.begin(), mp.end(), compare);
        int minv = mp.begin()->second;
        int maxv = mp.end()->second;
        vector<int> left(maxv - minv + 1, 0);
        vector<int> right(maxv - minv + 1, 1);
        int pos = 1;
        // left[i]保存左侧小于 minv的个数
        left[0] = 0;
        for(int i = 0; i < n; i++){
            while (mp[s[i]] >= (minv + pos) && pos <= maxv -minv)
            {
                left[pos] = i;
                pos++;
            }
        }
        // cout << maxv << minv <<endl;
        // pos = maxv - minv - 1;
        pos = 2;
        right[pos + 1] = 0;
        // left[i]保存you侧dayu于 min的个数
        for(int i = n - 1; i >= 0; i--){
            while (mp[s[i]] <= (minv + pos) && pos >= 0)
            {
                right[pos] = n - 1 - i;
                pos--;
            }
        }

        for(int i = 0; i < left.size(); i++){
            sum  = max(sum, left[i] + right[i]);
        }
        return sum;

        
    }
};


int main(){
    Solution * solu = new Solution();
    string s = "abbccc";
    int res = solu->getMaxEnergy(s);
    cout  << res << endl;
    cin.get();
}
