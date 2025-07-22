bool isWord(vector<vector<char>>& board, string& word,int x,int y, int widx) {
        int wlen=word.length();
        int n=board.size();
        int m=board[0].size();
        if(widx==wlen)
        return true;
        
        if(x<0 || y<0 || x>=n || y>=m)
        return false;
        
        if(board[x][y]==word[widx])
    {
    char temp=board[x][y];
    board[x][y]='#';
    
    bool res=isWord(board,word,x-1,y,widx+1)||isWord(board,word,x+1,y,widx+1)||isWord(board,word,x,y-1,widx+1)||
    isWord(board,word,x,y+1,widx+1);
    board[x][y]=temp;
    return res;
        
    }
    return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int wlen=word.length();
        int n=board.size();
        int m=board[0].size();
        if(wlen > n*m)
        return false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
        {
            if(board[i][j]==word[0]){
                if(isWord(board,word,i,j,0))
                return true;
            }
        }
        }
        return false;
        
    }
