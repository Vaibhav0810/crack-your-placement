Brute
Time-O(n)
Space-O(n)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
         
        for(int i=0;i<tokens.size();i++){ 
            int val1=0;
            int val2=0;
            
            if(tokens[i]=="+"){ 
                val1=st.top();
                st.pop();
                val2=st.top();
                st.pop();
                int ans=val1+val2;
                st.push(ans);
            }
            else if(tokens[i]=="-"){
                val1=st.top();
                st.pop();
                val2=st.top();
                st.pop();
                int ans=val2-val1;
                st.push(ans);
            }
            else if(tokens[i]=="/"){
                val1=st.top();
                st.pop();
                val2=st.top();
                st.pop();
                int ans=val2/val1;
                st.push(ans);
            }
            else if(tokens[i]=="*"){
                val1=st.top();
                st.pop();
                val2=st.top();
                st.pop();
                int ans=val2*val1;
                st.push(ans);
            }
            
//             if(t == "+" || t == "-" || t == "*" || t == "/") {
// 			        int op1 = s.top(); s.pop();
// 			        int op2 = s.top(); s.pop();
// 			        if(t == "+") op1 = op2 + op1;
// 			        if(t == "-") op1 = op2 - op1;       jo inta bda bnaya h maine usse short mei aise bhi likh skte h
// 		         	if(t == "/") op1 = op2 / op1;
// 		        	if(t == "*") op1 = op2 * op1;   
// 		        	s.push(op1);
// 	        	}
            
            else st.push(stoi(tokens[i])); 
        }
        return st.top();
      

}
    
};


