#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(const pair<string, int>  *a, const pair<string,int> *b){
    return a->second > b->second;
}

vector<string> getMaxS(vector<string> & strs){
    int n = strs.size();
    vector<string> res;
    // res.resize(5);
    if(n == 0){
        return res;
    }
    unordered_map<string, int> map;
    for(int i = 0; i < n; i ++){
        map[strs[i]]++;
    }
    // 排序找出前5
    sort(map.begin(), map.end(), compare);
    for(auto iter = map.begin(); iter != map.end(); iter++){
        res.push_back(iter->first);
    }
    return res;

}

int main(){
    vector<string> strs{"a","a","a","a","a","b"};
    vector<string> res = getMaxS(strs);
    cout << 1 << endl;

}