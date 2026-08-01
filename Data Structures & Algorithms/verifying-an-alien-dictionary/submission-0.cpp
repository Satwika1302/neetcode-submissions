class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mp;
            int k=0;
            for(char ch: order){
                mp[ch]=k;
                k++;
            }
        for(int i=0;i<words.size()-1;i++){
            string w1=words[i];
            string w2=words[i+1];
            int p = 0;int n = w1.size();int m = w2.size();

            while(p<n && p<m && mp[w1[p]]==mp[w2[p]])p++;
            if(p==m && p<n) return false;
            if(p<n && p<m && mp[w1[p]]>mp[w2[p]]) return false;
        }
        return true;
    }
};