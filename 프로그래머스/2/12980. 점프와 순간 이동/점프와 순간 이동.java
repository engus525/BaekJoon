import java.util.*;

public class Solution {
    
    public int solution(int n) {
        int ans = 1;
        
        
        while (n != 1)
        {
            if (n % 2 == 0) n /= 2;
            else {
                n--;
                ans++;
            }
            // System.out.println(n);
        }
        

        return ans;
    }
}