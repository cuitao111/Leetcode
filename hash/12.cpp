#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>
#include <queue>
#include <list>
#include <numeric>

using namespace std;

/*
遇到4和9时需要单独处理

除了to_string 使用除法获取每一位数字

从尾部到头构建罗马数字，最先出现的4或者9一定时IV或者IX
位于位之间无联系

一共四位
使用一个值标记位数
从大到小找最大值 1000 900 500 400 100
*/

const pair<int, string> value[] = 
{
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};

class Solution {
public:
    string intToRoman(int num) {
        string res;
        for(const auto & [nums, roman] : value){
            while(nums <= num)
            {
                num -= nums;
                res += roman;
            }
            if(num == 0){
                break;
            }
        }
        return res;
    }
};