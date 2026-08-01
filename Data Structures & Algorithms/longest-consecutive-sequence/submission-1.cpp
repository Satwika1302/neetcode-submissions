class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(int i : nums){
            s.insert(i);
        }
        int res=0;
        for(int i=0;i<nums.size();i++){    
            if(!s.count(nums[i]-1)){
                int length = 1;
                while(s.find(nums[i]+length)!=s.end()){
                    length++;
                }
                res= max(res,length);

            }
        }
        return res;
    }
};
