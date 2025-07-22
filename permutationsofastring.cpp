void permute(string &s,int i, vector<string> &result)
  {
        if(i==s.length()-1)
        {
            result.push_back(s);
            return ;
            
        }
         unordered_set<char>q;
        for(int j=i;j<s.length();j++)
        {
           
            if(q.count(s[j]))
            continue;
            q.insert(s[j]);
            
            swap(s[i],s[j]);
            permute(s,i+1,result);
            swap(s[i],s[j]);
        }
  }
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string>result;
        sort(s.begin(),s.end());
        permute(s,0,result);
        return result;
       
    }
