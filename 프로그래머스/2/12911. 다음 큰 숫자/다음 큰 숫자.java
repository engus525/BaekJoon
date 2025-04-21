class Solution {
    public int solution(int n) {
        int ans = n + 1;
        
        int oneCnt = 0;
        String nString = Integer.toString(n, 2);
        for (int i = 0; i < nString.length(); i++)
            if (nString.charAt(i) == '1')
                oneCnt++;
        
        while (true)
        {
            int cnt = 0;
            String str = Integer.toString(ans, 2);
            for (int i = 0; i < str.length(); i++)
                if (str.charAt(i) == '1')
                    cnt++;
            if (oneCnt == cnt) break;
            ans++;
        }
        
        return ans;
    }
}