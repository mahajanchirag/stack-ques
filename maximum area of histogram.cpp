int MaxHistogram(vector<int> &arr){
        stack<pair<int,int> > st;
        int ans = 0;
        int n = arr.size();
        for(int i = 0 ; i < n ; i ++){
            int bk = i;
            while(!st.empty() && (st.top().first >= arr[i])){
                bk = st.top().second;
                ans = max(ans, st.top().first * (i - st.top().second));
                st.pop();
            }
            st.emplace(arr[i], bk);
        }
        while(!st.empty()){
            ans = max(ans, st.top().first * (n - st.top().second));
            st.pop();
        }
        return ans;
    }
