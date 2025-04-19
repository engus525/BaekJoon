import java.util.*;

class Solution {
    
    int ans = 0;
    
    public int solution(int[] v, int limit) {
        
        Arrays.sort(v);
        int l = 0, r = v.length - 1;
        
        while (l <= r)
        {
            if (l == r)
            {
                ans++;
                break;
            }
            
            if (v[l] + v[r] <= limit)
            {
                l++;
                r--;
                ans++;
            }
            else
            {
                r--;
                ans++;
            }
        }
        
        return ans;
    }
}