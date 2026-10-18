class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int left=0,right=height.size()-1;
        while(left<right){
            int n=(height[left]<height[right])?height[left]:height[right];
            int area=n*(right-left);
             if(ans<area){
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