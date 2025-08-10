#include<bits/stdc++.h>
using namespace std;
    int dfs(int W, int wt[],int val[],int &n, int pos,int dp[][1001]){
        
        if(pos==n) return 0;
        if(dp[W][pos]!=-1) return dp[W][pos];
        
        int ans=dfs(W,wt,val,n,pos+1,dp);
        if(W-wt[pos]>=0) ans=max(ans,val[pos]+dfs(W-wt[pos],wt,val,n,pos+1,dp));
        return dp[W][pos]=ans;
        
        
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int dp[1001][1001];
       memset(dp,-1,sizeof(dp));
      return  dfs(W,wt,val,n,0,dp);
    }

int main()
 {
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        cout<<knapSack(w, wt, val, n)<<endl;
        
    
	return 0;
}
