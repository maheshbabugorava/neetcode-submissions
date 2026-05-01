class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        if(k == nums.size()){
            return nums;
        }       // works because of the condition in question

        map<int, int> hasmap;
        vector<int> retVet;

        for(int i = 0; i < nums.size(); i++){
            if(hasmap[nums[i]] == 0){
                hasmap[nums[i]] = 1;
            }
            else{
                hasmap[nums[i]]++;
            }
        }

        vector<pair<int, int>> countVet;

        for(auto itr : hasmap){
            countVet.push_back(pair<int, int>{itr.first, itr.second});
        }

        sort(countVet.begin(), countVet.end(), [](auto &a, auto &b){return a.second > b.second;});

        for(int i = 0 ; i < k; i++){
            retVet.push_back(countVet[i].first);
        }

        return retVet;
    }
};
