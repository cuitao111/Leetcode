#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>

using namespace std;

/*
如果不知道每个单词长度，无法判断共有几行
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // 定义一个长度数组
        vector<int> sizeOfWord(words.size());
        vector<string> ans;
        
        for(int i = 0; i < words.size(); i++){
            sizeOfWord[i] = words[i].length();
        }
        // 先判断该行能乘多少单词 begin end begin end
        int beginOfLine = 0, endOfLine = 0;
        int lenOfLine = 0;
        while(beginOfLine < words.size()){
            endOfLine = beginOfLine;
            lenOfLine = sizeOfWord[beginOfLine];
            while(endOfLine < words.size()){
                if(lenOfLine + sizeOfWord[endOfLine + 1] + 1 > maxWidth){
                    break;
                }
                lenOfLine += sizeOfWord[endOfLine + 1] + 1;
                endOfLine++;
            }
            // 添加一行，把多余的空格从左侧开始分配
            // 从begin到end分配多余空格

            string line;
            // 只有一个单词直接复制后面接空格
            if(beginOfLine == endOfLine){
                line = line + words[beginOfLine];
                for(int i = 0; i < (maxWidth - words[i].length());i++){
                    line = line + " ";
                }
            }else if(endOfLine == words.size() - 1){
                // 最后一行
                line = words[beginOfLine];
                for(int i = beginOfLine + 1; i <= endOfLine; i++){
                    line = line + " ";
                    line = line + words[i];
                }

            }else{
                int numOfSpace = (maxWidth - lenOfLine)/(endOfLine - beginOfLine) + 1;
                int resOfSpace = (maxWidth - lenOfLine) % (endOfLine - beginOfLine);
                line = line + words[beginOfLine];
                for(int i = beginOfLine + 1; i <= endOfLine; i++){
                    
                    if(i <= beginOfLine + resOfSpace){
                        
                        for(int j = 0; j < numOfSpace + 1; j++){
                            line = line + " ";
                        }
                    }else{
                        for(int j = 0; j < numOfSpace; j++){
                            line = line + " ";
                        }
                    }
                    line = line + words[i];
                }
            }
            
            ans.push_back(line);
            beginOfLine = endOfLine + 1;
        }
        return ans;
        

    }
    
};


int main(){
    Solution * solu = new Solution();
    vector<string> words{"What","must","be","acknowledgment","shall","be"};
    int  maxWidth = 16;
    vector<string> res = solu->fullJustify(words, maxWidth);
    cout  << 1 << endl;
}