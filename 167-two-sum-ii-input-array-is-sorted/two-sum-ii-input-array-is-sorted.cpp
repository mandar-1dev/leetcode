class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sum=0,left=0,right=numbers.size()-1;
        while(left<right){
            sum=numbers[left]+numbers[right];
            if(sum==target){
                return{left+1,right+1};
                break;
            }
            else if(sum<target){
                left++;
            }
            else{
                right--;
            }
        }
        return {};
    }
};