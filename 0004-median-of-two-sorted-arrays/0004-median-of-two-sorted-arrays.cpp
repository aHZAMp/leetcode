class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v(nums1.size()+nums2.size());
        
        int i=0,j=0,k=0;
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]<=nums2[j]){
                v[k]=(nums1[i]);
                i++;k++;}
            else if(nums2[j]<nums1[i])
            {
                v[k]=(nums2[j]);
                j++;k++;
            }
        }
        if(i==nums1.size())
        {
            for(int y=j;y<nums2.size();y++)
            {
                v[k]=(nums2[y]);k++;
            }
        }
        if(j==nums2.size())
        {
             for(int y=i;y<nums1.size();y++)
            {
                v[k]=(nums1[y]);k++;
            }
        }
       
         if (v.size() % 2 != 0)
        return (double)v[v.size() / 2];
 
    return (double)(v[(v.size() - 1) / 2] + v[v.size() / 2]) / 2.0;
        
    }
};