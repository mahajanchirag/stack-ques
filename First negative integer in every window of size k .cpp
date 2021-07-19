vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
   queue<long long int> q;
    vector<long long int> ans;
    for(int i=0;i<N;i++)
    {
        if(!q.empty() && q.front()==i-K)
        {
            q.pop();
        }
        
        if(A[i]<0)
        {
            q.push(i);
        }
        
        if(i>=K-1)
        {
            if(q.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(A[q.front()]);
            }
        }
        
    }
    
    return ans;
 }
