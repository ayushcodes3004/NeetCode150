class Solution {
private:
    void bfs(int i, int j,vector<vector<char>>& board, vector<vector<bool>>& vis){
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=true;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int delr[]={-1,0,1,0};
            int delc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc]=='O'){
                    // board[nr][nc]='X';
                    vis[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }
        
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            if(board[0][i]=='O') bfs(0,i,board,vis);
            if(board[m-1][i]=='O') bfs(m-1,i,board,vis);
        }
        for(int i=1;i<m-1;i++){
            if(board[i][0]=='O') bfs(i,0,board,vis);
            if(board[i][n-1]=='O') bfs(i,n-1,board,vis);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};
