 bool issafe(int r,int c,int rs,int ld,int rd,int n)
  {
      return !((rs>>r) &1) && !((ld>>(r+c))&1) && !((rd>>(r-c+n))&1);
  }
  void nqueenutil(int c,int n,vector<int>& board,
  vector<vector<int>>& res,int rs,int ld,int rd)
  {
      if(c>n)
      {
          res.push_back(board);
          return ;
      }
      for(int r=1;r<=n;++r)
      {
          if(issafe(r,c,rs,ld,rd,n))
          {
              board.push_back(r);
              nqueenutil(c+1,n,board,res,rs | (1<<r),(ld | (1<<(r+c))),(rd | (1<<(r-c+n))));
              board.pop_back();
          }
      }
  }
  
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>res;
        vector<int>board;
        nqueenutil(1,n,board,res,0,0,0);
        return res;
        
    }
