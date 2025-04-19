class Solution {
    
    StringBuilder sb = new StringBuilder();
    
    public String solution(int n, int t, int m, int p) {
        StringBuilder ans = new StringBuilder();
        
        for (int i = 0; sb.length() < t * m; i++)
        {
            sb.append(Integer.toString(i, n).toUpperCase());
        }
        int cnt = 0;
        for (int i = p - 1; cnt < t; i += m)
        {
            cnt++;
            ans.append(sb.charAt(i));
        }
        
        
        // System.out.println(sb);
        
        return ans.toString();
    }
}