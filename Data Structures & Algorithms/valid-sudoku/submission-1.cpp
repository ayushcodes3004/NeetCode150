class Solution {
private:
    bool checkRow(int r,vector<vector<char>>& board){
        vector<int>freq(10,0);
        for(int i=0;i<9;i++){
            if(board[r][i]=='.') continue;
            int num=board[r][i]-'0';
            freq[num]++;
            if(freq[num]>1) return false;
        }
        return true;
    }
    bool checkCol(int c,vector<vector<char>>& board){
        vector<int>freq(10,0);
        for(int i=0;i<9;i++){
            if(board[i][c]=='.') continue;
            int num=board[i][c]-'0';
            freq[num]++;
            if(freq[num]>1) return false;
        }
        return true;
    }
    bool checkSquare(int sr, int sc,vector<vector<char>>& board){
        vector<int>freq(10,0);
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'0';
                freq[num]++;
                if(freq[num]>1) return false; 
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            if(!checkRow(i,board)) return false;
        }
        for(int i=0;i<9;i++){
            if(!checkCol(i,board)) return false;
        }
        for(int i=0;i<9;i=i+3){
            for(int j=0;j<9;j=j+3){
                if(!checkSquare(i,j,board)) return false;
            }
        }
        return true;
    }
};
