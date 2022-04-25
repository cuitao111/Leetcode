#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;
int main(){
    priority_queue<int,vector<int> > big_heap;
    big_heap.push(2);
    big_heap.push(3);
    big_heap.push(5);
    big_heap.push(0);
    while(!big_heap.empty()){
        cout<<big_heap.top()<<endl;
        big_heap.pop();
        
    }
    cin.get();
}