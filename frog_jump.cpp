class Solution {
public:
    bool canCross(vector<int> &stones){
        map<int,set<int> > mp; 
        for (int i = 0; i < stones.size(); i++){
            mp[stones[i]] = set<int>();  
        }
        mp[stones[0]].insert(0); 
        for (int i = 0; i < stones.size()-1; i++){
            for (auto jump : mp[stones[i]]){ 
                for (int k = jump-1; k <= jump+1; k++){
                    if (k <= 0) continue; 
                    if (mp.count(stones[i]+k)){
                        mp[stones[i]+k].insert(k);  
                    }
                }
            }
        }
        return !mp[stones[stones.size()-1]].empty(); 
    }
};
