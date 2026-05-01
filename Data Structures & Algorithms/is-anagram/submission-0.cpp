class Solution {
public:
    bool isAnagram(string s, string t) {
        int sLen = s.length();
        if(sLen != t.length()){
            return false;
        }  

        map<char, int> stringMap;
        for(char c : s){
            stringMap[c]++;
        }

        for(char c: t){
            stringMap[c]--;
        }

        for(auto itr : stringMap){
            if(itr.second != 0){
                return false;
            }
        }

        return true;
    }
};
