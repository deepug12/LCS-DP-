//  Minimum number of deletions to make string Palindrome
#include<bits/stdc++.h>
using namespace std;

int LongestRepeatingSubsequence(string str, int n){
            // int n = str.size();
            string str2 = str;
            int m = str2.size();
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
                if(str[i-1] == str2[j-1] and (i != j)){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
}
int main(){
    int n;
    cin >> n;
    string x;
    cin >> x;

    cout<<LongestRepeatingSubsequence(x, n)<<'\n';

}