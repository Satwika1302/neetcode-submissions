class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            vector<int> v(26,0);
            for(char ch : strs[i]){
                v[ch-'a']++;
            }
            string k = to_string(v[0]);
            for(int i=1;i<26;i++){
                k += ' '+to_string(v[i]); 
            }
            mp[k].push_back(strs[i]);
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
