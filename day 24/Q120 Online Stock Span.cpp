
Time-O(n)
  Space-O(N)

// isme ik stack bnaya h pair ka
// stack<price,count> krke aise
  // to ab isme ik ct variable bnakr usse 1 kr denge bcoz jisme kuch bda ni hoga usme 1 return krna h
  // 
  
  
  
class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ct=1;
        
        while(st.size() && st.top().first<=price){ // jb tk stack empty ni h n top ka first price se chota h 
            ct+=st.top().second;  // second ki count bdhayenge tb tk
            st.pop();
        }
        st.push({price,ct});  // aur uske bdd ye stack mei push kr denge
        return ct;            // then return
        
    }
};
