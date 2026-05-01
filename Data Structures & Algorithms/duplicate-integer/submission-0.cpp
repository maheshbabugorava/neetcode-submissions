class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        map<int, int> hasmap;

        for(int i = 0; i < nums.size(); i++){
            if(hasmap[nums[i]] == 0){
                hasmap[nums[i]] = 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};