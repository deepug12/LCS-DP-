// Longest common subsequence
// Memoization technique
#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int lcs(int x, int y, string s1, string s2){
        
        if((x == 0) or y == 0){
            return 0;
        }
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        
        if(s1[x-1] == s2[y-1]){
            dp[x][y] =  1 + lcs(x-1, y-1, s1, s2);
            return dp[x][y];
        }
        else{
            dp[x][y] =  max(lcs(x-1, y, s1, s2), lcs(x, y-1, s1, s2));
            return dp[x][y];
        }
}
int main(){
	memset(dp, -1, sizeof(dp));
	int n, m;
	cin >> n >> m;
	string s;
	string p;
	cin >> s;
	cin >> p;


	cout<<lcs(n, m, s, p)<<'\n';

}