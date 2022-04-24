#include <iostream>
#include <vector>

using namespace std;

// 递推

class Section{

};

int main(){
    int n;
    cin >> n;
    vector<int> t(n);

    vector<int> res(n);
    int m;
    for(int i = 0; i < n; i++){
        cin >> t[i] >> m;
        if(m == 0){
            res[i] = t[i];
        }
    }
}