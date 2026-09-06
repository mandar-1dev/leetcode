class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>setA(nums1.begin(),nums1.end());
        unordered_set<int>setB(nums2.begin(),nums2.end());
        vector<int>arr;
        for(const int & ans:setA){
            if(setB.find(ans)!=setB.end()){
                arr.push_back(ans);
            }
        }
        return arr;
    }
};