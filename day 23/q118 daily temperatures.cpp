Brute Force
Time-O(n^2)
Space- O(1)

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

Optimised
Time-O(N)
    Space-O(N)
    
//     https://leetcode.com/problems/daily-temperatures/discuss/1574806/C%2B%2B-EASY-standard-sol-oror-INTUITIVE-approach-with-DRY-RUN-oror-STACK-appraoch
// link for understanding properly (also in description)

    // in short
    // phle ik stack bnaya aur ik ans array ans ko 0 se initiliase kr dia aur uska size temp ke equal
    // firr peeche se dekhna chalu krenge
  
    
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        vector<int> ans(temp.size(),0);
        
        stack<int> s{};
        
        for(int i=temp.size()-1;i>=0;--i){
            while(!s.empty() && temp[s.top()]<=temp[i])  // ab agr stack khali ni h aur s.top ki valu choti h array ki i se
                s.pop();                                   // to pop
            
            if(!s.empty())                             // ni to  compare krenge unhe aur ans mei ans push krenge
                ans[i]=s.top()-i;
            
            s.push(i);                                 // aur firr stack mei push
            
        }
        return ans;
    }
};

// iska ke aur variant bhi ho skta h ki arrat mei next greater temp daalo to usme index ki jgh value

