#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Sunday(string s, string t){
    int start = 0;
    int s_len = s.length();
    int t_len = t.length();
    int ASCII_SIZE = 123;
    // 初始化数组为字串+1
    vector<int> move(ASCII_SIZE, t_len + 1);
    // 更新字串中的字符为位置到末端的距离+1
    for(int i = 0; i < t_len; i++){
        move[t[i]] = t_len - i; 
    }
    // 开始匹配
    while(start <= s_len - t_len){
        int j = 0;//已经匹配的位置
        while(s[start + j] == t[j]){
            j++;
            if(j > t_len){
                // 匹配成功
                return start;
            }
        }
        // if(start + t_len >= s_len){
        //     return -1;
        // }
        char next = s[start + t_len];
        start += move[next];
    }
    return -1;



}
int main(){
    string s = "abcccccccabe";
    string t = "abe";
    int res = Sunday(s,t);
    cout << res << endl;
    cin.get();
}