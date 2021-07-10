class Solution {
public:
    
    int MAH(int arr[],int n)
    {
        stack<int>s;
         int max_area=0,area=0;
        int i=0;
        while(i<n){
        if(s.empty() or arr[s.top()]<=arr[i]){
            s.push(i);
            i++;
        }
        else{
            int top=s.top();
            s.pop();
            if(s.empty()){
                area=arr[top]*i;
            }
            else{
                area=arr[top]*(i-s.top()-1);
            }
            max_area=max(area,max_area);
        }
    }
    
    while(!s.empty()){
        int top=s.top();
        s.pop();
        area=arr[top]*(s.empty()?i:(i-s.top()-1));
        max_area=max(area,max_area);
    }
    return max_area; 
        
    }
    
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        
        
        int n=matrix.size();
        if(n==0)
        {
            return 0;
        }
        
        int m=matrix[0].size();
        
        if(n==0 || m==0)
        {
            return 0;
        }
        
        
        int arr[m];
        for(int i=0;i<m;i++)
        {
            arr[i]=0;
        }
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]!='0')
                {
                    arr[j]=arr[j]+(matrix[i][j]-'0');
                }
                else
                {
                    arr[j]=0;
                }
                    
            }
            
            ans=max(ans,MAH(arr,m));
            
        }
        
        return ans;
        
    }
};
