#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return match(&s[0], &p[0]);
    }

    bool match(char * s, char *p){
        if((*s=='\0') && (*p=='\0')){
            // 匹配成功
            return true;
        }
        if((*s != '\0')&&(*p=='\0')){
            // 模式串不能先结束
            return false;
        }
        if(*(p+1) == '*'){
            if(*s == *p|| (*p=='.'&&*s!='\0')){
                return match(s+1, p+2) || match(s, p+2) || match(s+1, p);
            }else{
                return match(s, p+2);
            }
        }else{
            if(*p == *s|| (*p=='.' && *s!='\0')){
                return match(s+1, p+1);
            }
        }
        return false;
    }
};


int main(){

    Solution * solu= new Solution();
    string s = "aab";
    string p = "c*a*b";
    bool res = solu->isMatch(s, p);
    cout << res << endl;
    cin.get();
    

}