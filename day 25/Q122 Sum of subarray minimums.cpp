Brute 
Time-O(N^3)
  Space- O(n)
  
  
  
  class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int> ans;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i;j<arr.size();j++){
                for(int k=i;k<=j;k++){
                    ans.push_back(arr[k]);
                }
                sum=sum+*min_element(ans.begin(),ans.end());
                
                ans.clear();
            }
        }
        return sum%1000000007;
    }
};
