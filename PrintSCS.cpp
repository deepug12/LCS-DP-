//  Minimum number of deletions to make string Palindrome
#include<bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string str1, string str2, int n, int m) {
        // int n = str1.size();
        // int m = str2.size();
        
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
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        int i = n, j = m;
        string ans;
        
         while (i > 0 && j > 0)
        {
            
            if (str1[i-1] == str2[j-1])
            {
                ans.push_back(str1[i-1]);
                i--; 
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    ans.push_back(str1[i-1]);
                    i--; 
                }
                
                else{
                    ans.push_back(str2[j-1]);
                    j--; 
                }
            }
        }
        while(i > 0){
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j > 0){
            ans.push_back(str2[j-1]);
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
int main(){
    int n, m;
    cin >> n >> m;
    string x, y;
    cin >> x >> y;

    cout<<shortestCommonSupersequence(x, y, n, m)<<'\n';

}