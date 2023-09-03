class Solution {
public:
    
    int countdigit(int n)
    {
        int c=0;
        while(n>0)
        {
            int r=n%10;
            c++;
            n/=10;
        }
        return c;
    }
    int rightsum(int n)
    {
        int c=countdigit(n)/2;
        int count=0,sum=0;
        while(n>0&&c>0)
        {
            if(count==c)
                break;
            int r=n%10;
            sum+=r;
            count++;
            n/=10;
        }
        return sum;
    }
    int leftsum(int n)
    {
        int a=n;
        int sum=0;
        while(n>0)
        {
            int r=n%10;
            sum+=r;
            n/=10;
        }
        //int digit=countdigit(a);
        int s=rightsum(a);
        return sum-s;
    }
        
    
    int countSymmetricIntegers(int low, int high) {
         int c=0;
        for(int i=low;i<=high;i++)
        {
            if(countdigit(i)%2==0)
            {
                if(rightsum(i)==leftsum(i))
                    c++;
            }
        }
        return c;
    }
};