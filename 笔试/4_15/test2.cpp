#include <iostream>

using namespace std;

string solu(int K, int L, int R, int T, int X, int Y){
    if(K < L || K > R){
        return "No";
    }
    for(int i=0; i < T; i++){
        if(K + Y > R){
            K -= X;
            if(K < L||K > R){
                return "No";
            }
        }else{
            K = K + Y - X;
            if(K < L || K > R){
                return "No";
            }
        }

    }
    return "Yes";
}

int main(){
    int n, K, L ,R, T, X, Y;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> K >> L >> R  >> T >> X >> Y;
        cout << solu(K, L, R, T, X, Y) << endl;
    }
    // cout << solu(8,1,10,2,6,4) << endl;
    cin.get();

}