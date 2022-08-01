Brute Force

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int count=0;
        vector<int> ans;
        bool check=false;
        for(int i=0;i<temp.size();i++){
            check=false;
            for(int j=i+1;j<temp.size();j++){
                if(temp[i]<temp[j]){
                    ans.push_back(j-i);
                    check=true;
                    break;
                }
            }
            if(check==false){
                ans.push_back(0);
            }
        }
        return ans;
    }
};
