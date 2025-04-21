class Solution {
    public int solution(int n) {
        int ans = n + 1;
        
        int oneCnt = Integer.bitCount(n);
        
        while (true)
        {
            if (oneCnt == Integer.bitCount(ans)) break;
            ans++;
        }
        
        return ans;
    }
}