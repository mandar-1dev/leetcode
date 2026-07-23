class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int lower=0,middle=0,higher=n-1;
        while(middle<=higher){
            if(nums[middle]==0){
                nums[middle]=nums[lower];
                nums[lower]=0;
                middle++;
                lower++;
            }
            else if(nums[middle]==1){
                middle++;
            }
            else{
                nums[middle]=nums[higher];
                nums[higher]=2;
                higher--;
            }
        }
    }
};