class Solution {
public:
    int reverseBits(int n) {
        string binary="";
        for(int i=0;i<32;i++){
            if(n%2==0) binary+="0";
            else binary+="1";
            n/=2;
        }
        long long sum =0;
        int p = binary.size()-1;
        for(int i =0;i<binary.size();i++){
            if(binary[i]=='1'){
            sum+= pow(2,p-i);
            }
        }
        return sum;
    }
};