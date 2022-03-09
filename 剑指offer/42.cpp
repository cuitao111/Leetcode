#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>
#include <queue>

using namespace std;

/*
使用队列，当队首元素小于t-3000时 pop()
*/

class RecentCounter {
    int numOfRequest;
    queue<int> requests;
public:
    RecentCounter() {
        numOfRequest = 0;
    }
    
    int ping(int t) {
        // t入队
        requests.emplace(t);
        numOfRequest++;
        while (requests.front() < t - 3000)
        {
            requests.pop();
            numOfRequest--;
        }
        return numOfRequest;
    }
};