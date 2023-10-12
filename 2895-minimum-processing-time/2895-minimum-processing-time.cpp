class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        
        vector<int>fake=tasks;
        sort(processorTime.begin(),processorTime.end());
        sort(fake.begin(),fake.end(),greater<int>());
        int maxi=INT_MIN;
        for(int i=0;i<processorTime.size();i++)
        {
            int fmax=INT_MIN;
            for(int j=i*4;j<(i+1)*4;j++)
            {
                fmax=max(fmax,processorTime[i]+fake[j]);
            }
            maxi=max(maxi,fmax);
        }
        return maxi;
    }
};