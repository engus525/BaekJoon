import java.util.*;

class Solution {
    
    StringBuilder ans = new StringBuilder();
    
    public String solution(String s) {
        s = s.toLowerCase();
        
        for (int i = 0; i < s.length(); i++)
        {
            char c = s.charAt(i);
            if (i == 0 && 'a' <= c && c <= 'z')
                ans.append(String.valueOf((char) (c - 'a' + 'A')));
            else if (i > 0 && s.charAt(i - 1) == ' ' && 'a' <= c && c <= 'z')
                ans.append(String.valueOf((char) (c - 'a' + 'A')));
            else ans.append(c);
        }
        
        return ans.toString();
    }
}