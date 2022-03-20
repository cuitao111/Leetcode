#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/*
remove actId后是否还会再次添加
若添加则 需要顺便移除user中的activity
*/
struct Acticity
{
    int actId;
    int priceLimit;
    int discount;
    int number;
    int userLimit;
    Acticity(int Id, int price, int discount, int number, int user):
    actId(Id), priceLimit(price), discount(discount), number(number), userLimit(user){}
};

struct User{
    int userId;
    unordered_map<int, int> activity;  //参加活动i剩余的次数
    User(int Id):userId(Id){}
};



class DiscountSystem {
    unordered_map<int, Acticity *> actmp;
    unordered_map<int, User *> usermp;
public:
    DiscountSystem() {

    }
    
    void addActivity(int actId, int priceLimit, int discount, int number, int userLimit) {
        // 创建编号 1 的优惠活动，单笔消费原价不小于 15 时，
        // 可享受 5 的减免，优惠活动共有 7 个名额，每个用户最多参与该活动 2 次
        Acticity * act = new Acticity(actId, priceLimit, discount, number, userLimit);
        if(actmp.count(actId)){
            cerr << "create exists activity!" <<endl;
        }
        actmp[actId] = act;
    }
    
    void removeActivity(int actId) {
        actmp.erase(actId);
    }
    
    int consume(int userId, int cost) {
        if(!usermp.count(userId)){
            User * user = new User(userId);
            usermp[userId] = user;
        }else{
            User * user = usermp[userId];
        }
        // 遍历actmp找满足条件的活动
        // 同时满足两个活动？优先参加优惠减免最大
        int discount = 0;
        int activityid = -1;
        for(auto & it : actmp){
            if(it.second->priceLimit <= cost && it.second->number > 0){
                // 看能减免多少
                // 还要看用户次数是否用完
                if(usermp[userId]->activity.count(it.second->actId) && usermp[userId]->activity[it.second->actId] == 0){
                    continue;
                }else{
                    if(it.second->discount > discount){
                        activityid = it.second->actId;
                        discount = it.second->discount;
                    }
                }
            }
        }
        if(activityid != -1){
            //discount
            if( usermp[userId]->activity.count(activityid)){
                actmp[activityid]->number--;
                usermp[userId]->activity[activityid]--;
            }else{
                //create aticityid in userId
                actmp[activityid]->number--;
                usermp[userId]->activity[activityid] = actmp[activityid] ->userLimit - 1;
            }
            return cost - discount;
        }
        return cost;
    }
};

int main(){
    DiscountSystem * ds = new DiscountSystem();
    ds->addActivity(1,10,6,3,2);
    ds->addActivity(2,15,8,8,2);
    cout << ds->consume(101,13) << endl; // 13 - 6 
    ds->removeActivity(2);
    cout << ds->consume(101,17) << endl; // 17 - 6用完优惠
    cout << ds->consume(101,11) << endl; // 11
    cout << ds->consume(102,16) << endl;// 16 - 6
    cout << ds->consume(102,21) << endl;
    cin.get();
}