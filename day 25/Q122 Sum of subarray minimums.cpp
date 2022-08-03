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

TIME-O(N+N+N)=O(3N)~O(N)
  SPACE-o(N)
 
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(st.size() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(st.size()) left[i]= i-st.top();
            else left[i]=i+1;
            
            st.push(i);
        }
        while(st.size()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            
            while(st.size() && arr[i]<=arr[st.top()]) st.pop();
            
            if(st.size()) right[i]= st.top()-i;
            else right[i]=n-i;
            st.push(i);
            
        }
        
        int mod=1e9+7;
        int res=0;
        for(int i=0;i<n;i++){
            long long prod=(left[i]*right[i])%mod;
            prod=(prod*arr[i])%mod;
            res=(res+prod)%mod;
        }
        return res%mod;
    }
};
