class Solution {
public:
    // its kind of not clear what the requirements of the problem are... so 
    int distMoney(int money, int children) {
        //we'll initially distribute 1 money to every kid , to meet the constraints
        money-=children;
        if(money<0)return -1;
        if(money%7==0&&(money/7)==children)return children;
        if(money%7==3&&money/7==(children-1))return children -2;//then we analyse the 
        return min(children-1,money/7);
    }
};