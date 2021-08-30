class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> v;
        stack<long long> stk;
        
        for(int i=n-1;i>=0;i--)
        {
            if(stk.empty())
            {
                v.push_back(-1);
            }
            
            else if(!stk.empty() &&  arr[i]<stk.top())
            {
                v.push_back(stk.top());
            }
            
            else if(!stk.empty() &&  arr[i]>=stk.top())
            {
                while(!stk.empty() && arr[i]>=stk.top())
                {
                    stk.pop();
                }
                
                if(stk.empty())
                {
                    v.push_back(-1);
                }
                
                else
                {
                    v.push_back(stk.top());
                }
            }
            
            stk.push(arr[i]);
            
        }
        
        reverse(v.begin(),v.end());
        
        return v;
        
    }
};
