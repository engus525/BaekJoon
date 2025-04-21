import java.util.*;

class Solution {
    
    StringBuilder ans = new StringBuilder();
    
    public String solution(String s) {
        s = s.toLowerCase();
        
        for (int i = 0; i < s.length(); i++)
        {
            char c = s.charAt(i);
            if (i == 0)
                ans.append(String.valueOf(Character.toUpperCase(c)));
            else if (i > 0 && s.charAt(i - 1) == ' ' && Character.isLowerCase(c))
                ans.append(String.valueOf(Character.toUpperCase(c)));
            else ans.append(c);
        }
        
        return ans.toString();
    }
}