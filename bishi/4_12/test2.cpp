#include <iostream>
#include <vector>

using namespace std;

void run(string s){
    int i = 0, j = 0;
    for(auto &ch :s){
        if(ch == 'R'){
            i += 1;
        }else if(ch == 'L'){
            i -= 1;
        }else if(ch == 'U'){
            j += 1;
        }else if(ch == 'D'){
            j -= 1;
        }
    }
    cout << "(" << i << "," << j << ")" <<endl;
}


int main(){
    string s;
    cin >> s;

    run(s);

    return 0;
}