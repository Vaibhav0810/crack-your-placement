Time-O(n)
Space-O(n)

  // isme phle check krenge agr A[i] == h * + - / inke to top 2 value ko store krenge
  // then unka minus + kr denge jaise condition hogi 
  // nhi h to stack mei push kr denge values ko
  // but this is only applicable for single digit 
  // multiple ke lie neeche vala code
  
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string A)
    {
        // Your code here
        stack<int> s;
       for(int i=0;i<A.size();i++)
       {
           if(A[i]=='+' || A[i]=='-' || A[i]=='*' || A[i]=='/' )
           {
               int v1=s.top();
               s.pop();
               int v2=s.top();
               s.pop();
               if(A[i]=='+') s.push(v2+v1);
               else if(A[i]=='-') s.push(v2-v1);
               else if(A[i]=='*') s.push(v2*v1);
               else if(A[i]=='/') s.push(v2/v1);
           }
           else s.push(A[i]-'0');  // ye kyu kra ?
       }
       return s.top();
    }
};


// for multiple digits like 97* 2 etc
// algo jo mujhe lgta h (not similiar to code)
// isme phle i ka loop firr jb tk i==" " ni hota tb tk vo num*10+num vala kaam 
// jb space ke equal ho jaaye to continue 
// aur operator ke equal h to upr vala kaam

// Scan all characters one by one 
    for (i = 0; exp[i]; ++i) 
    { 
        //if the character is blank space then continue 
        if(exp[i] == ' ')continue; 
        
        // If the scanned character is an 
        // operand (number here),extract the full number 
        // Push it to the stack. 
        else if (isdigit(exp[i])) 
        { 
            int num=0; 
            
            //extract full number 
            while(isdigit(exp[i])) 
            { 
            num = num * 10 + (int)(exp[i] - '0'); // ye isme eg 0=0*10 +1=1 firr 1*10 +0=10 then 10*10+0= 100 finish then 
                i++;                              // aise hoga multiple digits ka
            } 
            i--; 
            
            //push the element in the stack 
            push(stack,num); 
        } 
        
        // If the scanned character is an operator, pop two 
        // elements from stack apply the operator 
        else
        { 
            int val1 = pop(stack); 
            int val2 = pop(stack); 
            
            switch (exp[i]) 
            { 
            case '+': push(stack, val2 + val1); break; 
            case '-': push(stack, val2 - val1); break; 
            case '*': push(stack, val2 * val1); break; 
            case '/': push(stack, val2/val1); break; 
            
            } 
        } 
    } 
    return pop(stack); 
} 

// Driver code
int main() 
{ 
    char exp[] = "100 200 + 2 / 5 * 7 +"; 
    cout << evaluatePostfix(exp); 
    return 0; 
} 
