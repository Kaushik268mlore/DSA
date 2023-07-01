class Solution {
public:
int n, k;

int func(vector<int>& cookies, vector<int>& child, int i, int max_val){
    if(i == n) return max_val;

    int res = INT_MAX;

    for(int j = 0 ; j < k ; j++){
        child[j] += cookies[i];
        res = min(res, func(cookies, child, i+1, max(max_val, child[j])));
        child[j] -= cookies[i];
    }

    return res;
}

int distributeCookies(vector<int>& cookies, int k) {
    n = cookies.size();
    this->k = k;
    vector<int> child(k,0);

    return func(cookies, child, 0, 0);
}
};