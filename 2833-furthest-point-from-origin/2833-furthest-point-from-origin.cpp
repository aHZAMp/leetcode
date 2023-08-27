class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int c1=0,c2=0,c3=0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i]=='L')
                c1++;
            else if(moves[i]=='R')
                c2++;
            else
                c3++;
        }
        if(c1>=c2)
        {
            return (c3+c1-c2);
        }
        else if(c2>c1)
        {
            return (c3+c2-c1);
        }
        else
            return c3;
    }
};