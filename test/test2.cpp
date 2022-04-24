#include <iostream>
#include <string>
#include <unordered_map>


using namespace std;


int resorts(string s){
    unordered_map<char, int> mp;
    int n = s.length();
    for(int i = 0; i < n;i++){
        mp[s[i]]++;
    }
    int res_1 = mp['a'] - 1;
    int res_2 = mp['c'] / 3;
    int res_3 = mp['b'];
    return min(min(res_1, res_2), res_3);
}

int main(){
    string s;
    cin >> s;
    cout  << resorts(s) <<endl;
}