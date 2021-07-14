class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        
        int dx[4] = {-1, 0, 0, 1} ;
        int dy[4] = {0, -1, 1, 0} ;
        
        queue<pair<int,int>> q;
        
        int time=-1;
        
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    
                    q.push({i,j});  
                }
                
                if(grid[i][j]==1)
                {
                    
                    count++;  
                }
            }
        }
        
        
        while(!q.empty())
        {
            int size=q.size();
            for(int i=1;i<=size;i++)
            {
                pair<int,int> temp=q.front();
                q.pop();
                
                for(int j=0;j<4;j++)
                {
                    int x=dx[j]+temp.first;
                    int y=dy[j]+temp.second;
                    
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1)
                    {
                        count--;
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                    
                }
                
            }
            
            
            time++;
        }
        
        if(count!=0)
        {
            return -1;
        }
        
        if(time==-1)
        {
            return 0;
        }
        return time;
        
    }
};
