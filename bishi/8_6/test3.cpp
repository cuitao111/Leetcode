#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int getMinFlip(vector<int> & front, vector<int> & back){
    int n = front.size();
    unordered_map<int, int> mpf;
    unordered_map<int, int> mpb;
    for(int i = 0; i < n; i++){
        mpf[front[i]]++;
        if(back[i] != front[i]){
            mpb[back[i]]++;
        }
    }
    int max = 0;
    int ret = -1;
    for(auto iter = mpf.begin(); iter != mpf.end(); iter++){
        if(n % 2 == 0){
            //偶数情况
            if(iter->second >= n / 2){
                return 0;
            }
            //找出反面还有多少
            
            if(mpb[iter->first] + iter->second >= n/2){
                if(ret == -1){
                    ret = n / 2 - iter->second;
                }else{
                    ret = std::min(ret,  n / 2 - iter->second);
                }
            }
        }else{
            //奇数
            if(iter->second > n / 2){
                return 0;
            }
            //找出反面还有多少
            
            if(mpb[iter->first] + iter->second > n/2){
                if(ret == -1){
                    ret = n / 2 + 1 - iter->second;
                }else{
                    ret = std::min(ret,  n / 2 + 1 - iter->second);
                }
                
            }
        }
        
    }
    return ret;

}

int main(){
    int n;
    cin >> n;
    vector<int> front(n , 0);
    vector<int> back(n , 0);
    for(int i = 0; i < n; i++){
        cin >> front[i];
    }
    for(int i = 0; i < n; i++){
        cin >> back[i];
    }
    cout << getMinFlip(front, back) <<endl;

    return 0;
}




