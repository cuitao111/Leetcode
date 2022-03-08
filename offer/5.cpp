#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    string replaceSpace(string s){
        int sizeOfS = s.length();
        int numOfBlack = 0;
        for(int i = 0; i < sizeOfS; i++){
            if(s[i] == ' '){
                numOfBlack++;
            }
        }
        int newLength = sizeOfS + 2 * numOfBlack;
        // 定义两个指针
        int pointOfOld = sizeOfS - 1;
        int pointOfNew = newLength - 1;
        char newS[newLength + 1];
        while(pointOfOld >= 0 && pointOfNew >= pointOfOld){
            // 若Oldpoint遇到空格则将其复制为%20
            // 同时下一个newpoint需要复制的位置为 -=2
            // oldpoint 为  -= 1
            //  --在后用后减
            if(s[pointOfOld] == ' '){
                newS[pointOfNew--] = '0';
                newS[pointOfNew--] = '2';
                newS[pointOfNew--] = '%';
                pointOfOld--;
            }else{
                // 遇到非空格直接赋值
                newS[pointOfNew--] = s[pointOfOld--];
            }
        }
        newS[newLength] = '\0';
        return newS;
    }
};


int main(){
    Solution * solu = new Solution();
    string s = "We are happy.";
    string res = solu ->replaceSpace(s);
    cout << res << endl;
}