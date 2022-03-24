#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>
#include <queue>
#include <list>
#include <numeric>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> map;
        for(int i = 0; i < jewels.size(); i++){
            map[jewels[i]]++;
        }
        int sum = 0;
        for(int i = 0; i < stones.size(); i++){
            if(map.count(stones[i])){
                sum++;
            }
        }
        return sum;
    }
};