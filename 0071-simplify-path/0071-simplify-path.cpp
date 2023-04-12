class Solution {
public:
    string simplifyPath(string path) {
        vector<string>stack;
        for(int i=0;i<path.size();i++){
            if(path[i]=='/')continue;
            string temp;
            while(i<path.size()&&path[i]!='/'){temp+=path[i];i++;}
            if(temp==".")continue;
            else if (temp==".."){
                if(!stack.empty()){stack.pop_back();}
            }
            else stack.push_back(temp);
        }
        if(stack.size()==0)return "/";
        string res="";
        while(!stack.empty()){
            res="/"+stack.back()+res;
            stack.pop_back();
        }
        return res;
    }
};