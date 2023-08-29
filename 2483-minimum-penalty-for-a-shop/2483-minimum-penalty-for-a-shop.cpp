class Solution {
public:
    int bestClosingTime(string customers) {
         int size=customers.size();
    int nos[size+1];
    int yes[size+1];
    nos[0]=0;
	
	//calculating no of No for ith hr
    for(int i=0;i<size;i++){
        if(customers[i]=='N'){
            nos[i+1]=nos[i]+1;
        }else{
            nos[i+1]=nos[i];
        }
       
    }
     
    nos[size]=nos[size-1];
	
	//claculating no of Yes for ith hr
    yes[size]=0;
    for(int j=size-1;j>=0;j--){
        if(customers[j]=='Y'){
            yes[j]=yes[j+1]+1;
        }else{
            yes[j]=yes[j+1];
        }
       
    }
        /*for(int i=0;i<size;i++)
        {
            cout<<nos[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<yes[i]<<" ";
        }*/
        int mp=INT_MAX;int hr=0;
        for(int i=0;i<=size;i++)
        {
            int p=nos[i]+yes[i];
            if(p<mp)
            {
                mp=p;
                hr=i;
            }
        }
      
        return hr;
    }
};