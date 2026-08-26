class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor0=0;
        for(auto x : nums){
            xor0^=x;
        }
        int xor1=0;
        int right1=xor0^(-xor0);
        for(auto x : nums){
            if((x & right1) == 0){
                xor1^=x;
            }
        }
        return vector<int>{xor1,xor1 ^ xor0};
    }
};