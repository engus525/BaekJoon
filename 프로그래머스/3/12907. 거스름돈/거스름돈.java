class Solution {
    
    static final int MOD = 1000000007;
    int[] dp = new int[100001];
    
    public int solution(int n, int[] money) {
        dp[0] = 1;
        for (int i = 0; i < money.length; i++)
        {
            for (int j = money[i]; j <= n; j++)
            {
                dp[j] += dp[j - money[i]];
                dp[j] %= MOD;
            }
        }
        // for (int i = 0; i <= n; i++) System.out.print(dp[i] + " ");
        return dp[n];
    }
}