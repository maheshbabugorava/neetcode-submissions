class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        long produc1t = 1;
        int zeroIdx = -1;

        for(int i  = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                if(zeroIdx == -1){
                    zeroIdx = i;
                }
                else{
                    vector<int> retVect(nums.size(), 0);
                    return retVect;
                }
            }
            else{
                produc1t = produc1t * nums[i];
            }
        }

       
        if(zeroIdx == -1){
            vector<int> retVect;
            for(int i = 0; i < nums.size(); i++){
                retVect.push_back(produc1t/nums[i]);
            }
             return retVect;
        }
        else{
            vector<int> retVect(nums.size(), 0);
            retVect[zeroIdx] = produc1t;

             return retVect;
        }

       

    }
};
