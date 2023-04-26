class Solution {
public:
    int addDigits(int num) {//amazing concept of digital root used
       if(num){
           return (1+((num-1)%9));
       }
        else return 0;
    }
};