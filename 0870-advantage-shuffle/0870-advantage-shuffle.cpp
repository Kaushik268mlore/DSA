class Solution {
public:
    // to get the next index that is not occupied
int nextAvailable(vector<bool>& indices, int j, const int& n){
	while(j < n && indices[j]) j++;
	return j;
}
vector<int> advantageCount(vector<int>& A, vector<int>& B) {
	int n = A.size(), idx;
	vector<bool> indices(n);
	vector<int> res(n, -1);
	sort(A.begin(), A.end());
	for(int i=0;i<n;i++){
		// get the index of the next greater element
		idx = upper_bound(A.begin(), A.end(), B[i]) - A.begin();
		while(idx < n && indices[idx]) idx++;
		if(idx != n){
			indices[idx] = true;
			res[i] = A[idx];
		}
	}
	// updating res with rest of the elements
	int j = 0;
	j = nextAvailable(indices, j, n);
	for(int i=0;i<n;i++){
		if(res[i] == -1){
			res[i] = A[j];
			j = nextAvailable(indices, j+1, n);
		}
	}
	return res;
}
};