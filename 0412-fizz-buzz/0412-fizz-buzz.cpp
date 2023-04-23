class Solution {
public:
    // vector<string> fizzBuzz(int n) {
    //     vector<string>res(n+1);
    //     for(int i=1;i<=n;i++){
    //         if(i%3==0||i%5==0){
    //         if(i%3==0)res[i]+="Fizz";
    //         if(i%5==0)res[i]+="Buzz";}
    //         else {
    //             res[i]+=char(i);
    //         }
    //     }
    // return res;}
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for(int i = 1;i <= n; i++) {
            res[i - 1] = to_string(i);
        }
        for(int i = 2;i < n; i += 3) {
            res[i] = "Fizz";
        }
        for(int i = 4;i < n; i += 5) {
            res[i] = "Buzz";
        }
        for(int i = 14;i < n; i += 15) {
            res[i] = "FizzBuzz";
        }
        return res;
    }
};