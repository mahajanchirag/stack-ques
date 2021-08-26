class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int> stk;
        stk.push(-1);
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                stk.push(i);
            }
            
            
            else
            {
                if(!stk.empty())
                {
                    stk.pop();
                }
                
                if(!stk.empty())
                {
        
                    ans=max(ans,i-stk.top());
                }
                
                else
                {
                    stk.push(i);
                }
            }
            
            
        }
        
        return ans;
    }
};
