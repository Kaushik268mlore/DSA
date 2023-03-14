class Solution {
public:
    // a very easy problem
    double largestTriangleArea(vector<vector<int>>& arr) {
        double area = numeric_limits<double>::min();
        int n=arr.size();
        for(int x=0;x<=n-3;x++){
            for(int y=x+1;y<=n-2;y++){
                for(int z=y+1;z<=n-1;z++){
                   int x1=arr[x][0],y1=arr[x][1],x2=arr[y][0],y2=arr[y][1],x3=arr[z][0],y3=arr[z][1];
                    double temp=0.5*abs((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
                    area=max(area,temp); 
                }
            }
        }
    return area;}
};