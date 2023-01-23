class Solution {
public:
    vector<vector<int>> adjList;// we are building the list   globally so that it gets updated in real time in dfs.
    int dfs(vector<bool>& hasApple,int node,int d,int prev)
    {
        int result=0,temp;
        for(int &i:adjList[node])
	    if(i!=prev)
	    {
	        temp=dfs(hasApple,i,d+1,node);//go to the next node and
	        if(temp) result+=temp-d; // there exists any node with apples add the distance
	    }
        return result||hasApple[node]?result+d:0; 
        
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        adjList.resize(n);
        for(vector<int> &e:edges)
            adjList[e[0]].push_back(e[1]),adjList[e[1]].push_back(e[0]);
         return dfs(hasApple,0,0,-1)*2;
    }
};