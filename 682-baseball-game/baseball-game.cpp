class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(string o:operations){
            if(o=="C"){
                st.pop();
            }
            else if(o=="D"){
                int x=st.top();
                st.push(x*2);

            }
            else if(o=="+"){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.push(x);
                st.push(x+y);
            }
            else{
                st.push(stoi(o));
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};