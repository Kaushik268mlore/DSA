class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string>m;
        m[1]="I";
        m[5]="V";
        m[10]="X";
        m[50]="L";
        m[40]="XL";
        m[100]="C";
        m[500]="D";
        m[1000]="M";
        m[900]="CM";
        m[400]="CD";
        m[90]="XC";
        m[9]="IX";
        m[4]="IV";
        string res="";
        int nums[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        for(int i=0;i<13;i++){
            while(num>=nums[i]){
                res+=m[nums[i]];
                num-=nums[i];
            }
        }
    return res;}
};