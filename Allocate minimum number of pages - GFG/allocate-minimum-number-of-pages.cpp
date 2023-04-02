//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++
bool is_possible(int a[],int n,int m,int mid)
{
    int student=1;
    int prsum=0;
    for(int i=0;i<n;i++)
    {
        if(prsum+a[i]<=mid)
        {
            prsum+=a[i];
        }
        else
        {
            student++;
            if(student>m || a[i]>mid)
            {
                return false;
            }
            else {
                prsum=a[i];
            }
        }
    }
    return true;
}

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        //code here
        if(n<m) return -1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        int res=-1;
        int s=0;
        int e=sum;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(is_possible(a,n,m,mid))
            {
                res=mid;
                e=mid-1;
            }
            else {
                s=mid+1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends