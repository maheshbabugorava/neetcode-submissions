class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int, int> hasmap;
        int diff;

        for(int i = 0; i < nums.size(); i++){
            diff = target - nums[i];

            if(hasmap[diff] == 0){
                
                hasmap[nums[i]] =  i+1;
            }
            else{
               
                vector<int> retVect;

                if(i < hasmap[nums[i]]){

                    retVect.push_back(i);
                    retVect.push_back(hasmap[diff]-1);
                    return retVect;
                }
                else{
                    retVect.push_back(hasmap[diff]-1);
                    retVect.push_back(i);

                    return retVect;
                }

            }
        }
    }
};
