class Solution {
    private:
    void permutation(int idx,vector<int>& nums,vector<vector<int>>& result){
        if(idx==nums.size()){
        result.push_back(nums);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
        permutation(idx+1,nums,result);
        swap(nums[idx],nums[i]);
    }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        permutation(0,nums,result);
        return result;
    }
};