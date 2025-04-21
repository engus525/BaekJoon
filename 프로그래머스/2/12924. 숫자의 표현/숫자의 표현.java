class Solution {
    public int solution(int n) {
        int ans = 0;
        
        int[] list = new int[n + 1];
        for (int i = 1; i <= n; i++) list[i] = i;
        
        int l = 1;
        int r = 1;
        int sum = 1;
        while (l <= n)
        {
            if (sum == n) ans++;
            
            if (sum <= n)
            {
                r++;
                if (r > n) break;
                sum += list[r];
            }
            else
            {
                sum -= list[l];
                l++;
            }
        }
        
        
        return ans;
    }
}