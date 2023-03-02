class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int i = 0;
        int ans_index = 0;
        int n = chars.size();
        
        while(i < n)
        {
            int j = i +1;
            
            while(j < n && chars[i] == chars[j])//this loop goes on till the very there is no different letter
            {
                j++;//increment the second pointer
            }
            // if sbove condition is false then
            // loop will end
            // means the repeating character will end
            
            chars[ans_index++] = chars[i];
            
            
            int count = j-i;//the window size 
            
            if(count > 1)
            {
                string cnt = to_string(count);//method to convert the int to string 
                for(char ch : cnt)
                {
                    chars[ans_index] = ch;
                    ans_index++;
                }
            }
            
            i = j;// updating i to start from the next letter point 
        }
        
        return ans_index;
        
    }
};