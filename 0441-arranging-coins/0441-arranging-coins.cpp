class Solution 
{

 public: int arrangeCoins(int n)
  {
       long le=0, ri=n;
       while(le<=ri)
    {
        long mid=le+(ri-le)/2;
        if(n>=(mid*(mid+1)/2))
        le=mid+1;
        else
        ri=mid-1;
    }
    return(int)ri;
       
         
    }
};