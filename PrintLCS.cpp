// Longest common substring
// top - down technique
#include<bits/stdc++.h>
using namespace std;

void longestCommonSubsequence(vector<int> a, vector<int> b, int n, int m) {
        // int n = a.size();
        // int m = b.size();
        int dp[n+1][m+1];
        for(int i = 0; i< n+1; i++){
            for(int j = 0; j< m+1; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1; i< n+1; i++){
            for(int j = 1; j< m+1; j++){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        int i = n, j = m;
        vector<int> ans;
         while (i > 0 && j > 0)
        {
            
            if (a[i-1] == b[j-1])
            {
                ans.push_back(a[i-1]);
                i--; j--;
            }
            else if (dp[i-1][j] > dp[i][j-1]){
               i--; 
            }
                
            else{
               j--; 
            }
                
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }


	longestCommonSubsequence(a, b, n, m);

}