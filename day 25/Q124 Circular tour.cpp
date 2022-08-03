class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int sum_p=0,sum_d=0;
       
       for(int i=0;i<n;i++){
           sum_p+= p[i].petrol;
           sum_d+= p[i].distance;
       }
       
       if(sum_p<sum_d){
           return -1;
       }
       
       int store=0,ans=0;
       
       for(int i=0;i<n;i++){
           store=store+p[i].petrol-p[i].distance;
           if(store<0){
               ans=i+1;
               store=0;
           }
           
       }
       return ans;
       
    }
};
