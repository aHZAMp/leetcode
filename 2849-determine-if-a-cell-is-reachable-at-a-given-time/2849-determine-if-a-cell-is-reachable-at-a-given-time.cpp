class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        if(sx==fx&&sy==fy&&t==1)
            return false;
        int dis=max(abs(fy-sy),abs(fx-sx));
        if(dis<=t)
            return true;
        else
            return false;
    }
};