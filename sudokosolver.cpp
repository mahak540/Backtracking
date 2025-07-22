 bool issafe(vector<vector<int>>& mat,int i,int j,int num , vector<int>& r,vector<int>& c,vector<int>& box)
    {
        if((r[i]&(1<<num))||(c[j]&(1<<num))||(box[i/3 * 3 + j/3]&(1<<num)))
        return false;
        
        return true;
    }
    
    bool solvesudokorec(vector<vector<int>>& mat,int i,int j, vector<int>& r,vector<int>& c,vector<int>& box)
    {
        int n=mat.size();
        if(i==n-1 && j==n)
        return true;
    
    if(j==n)
    {
      i++;
      j=0;
      
    }
    if(i==n)
    return true;
    if(mat[i][j]!=0)
        return solvesudokorec(mat,i,j+1,r,c,box);
        
       for(int num=1;num<=n;num++)
       {
            if(issafe(mat,i,j,num,r,c,box))
            {
                mat[i][j]=num;
                r[i] |= (1<<num);
                 c[j] |=(1<<num);
                 box[i/3 *3 +j/3] |= (1<<num);
                 if (solvesudokorec(mat,i,j+1,r,c,box))
                 return true;
                 
                  mat[i][j]=0;
                r[i] &= ~(1<<num);
                 c[j] &= ~(1<<num);
                 box[i/3 *3 +j/3] &= ~ (1<<num);
                 
            }
       }
       return false;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        vector<int>r(n,0),c(n,0),box(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]!=0)
                {
                r[i] |=(1<< mat[i][j]);
                 c[j] |=(1<< mat[i][j]);
                 box[(i/3) * 3 + j/3] |=(1<< mat[i][j]);
                }
            }
        }
        solvesudokorec(mat,0,0,r,c,box);
    }
