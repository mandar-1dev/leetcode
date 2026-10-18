class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int ans=0;
        while(left<right){
            int n=(height[left]<height[right])?height[left]:height[right];
            int area=n*(right-left);
            if(area>ans){
                ans=area;
            }
            else if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};