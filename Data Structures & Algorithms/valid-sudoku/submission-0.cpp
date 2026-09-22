class Solution {
private:
    bool checkRow(vector<vector<char>>& board, int r){
        vector<int>freq(10,0);
        for(int i=0;i<9;i++){
            if(board[r][i]=='.') continue;
            int num = board[r][i] - '0';
            freq[num]++;
        }
        for(auto f: freq){
            if(f>=2)    return false;
        }
        return true;
    }
    bool checkCol(vector<vector<char>>& board, int c){
        vector<int>freq(10,0);
        for(int i=0;i<9;i++){
            if(board[i][c]=='.') continue;
            int num = board[i][c] - '0';
            freq[num]++;
        }
        for(auto f: freq){
            if(f>=2)    return false;
        }
        return true;
    }
    bool checkSq(vector<vector<char>>& board, int r,int c){
        int sr=(r/3)*3;
        int sc=(c/3)*3;
        vector<int>freq(10,0);
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j]=='.') continue;
                int num = board[i][j] - '0';
                freq[num]++;
            }
        }
        for(auto f: freq){
            if(f>=2)    return false;
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool check=true;
        for(int i=0;i<9;i=i+3){
            for(int j=0;j<9;j=j+4){
                if(!checkSq(board,i,j)) return false;
            }
        }
        for(int i=0;i<9;i++){
            if(!checkRow(board,i)) return false;
        }
        for(int i=0;i<9;i++){
            if(!checkCol(board,i)) return false;
        }
        return true;
    }
};
