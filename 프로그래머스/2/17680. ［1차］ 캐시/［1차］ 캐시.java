import java.util.*;

class Solution { 
    
    LinkedHashSet<String> S = new LinkedHashSet<>();
    
    public int solution(int cacheSize, String[] v) {
        if (cacheSize == 0) return 5 * v.length;
        int ans = 0;
        
        for (int i = 0; i < v.length; i++)
        {
            String city = v[i].toLowerCase();
            if (!S.contains(city))
            {
                ans += 5;
                if (S.size() == cacheSize)
                {
                    S.remove(S.iterator().next());
                }
                S.add(city);
            }
            else
            {
                ans++;
                // System.out.println(city + " 뒤로(+1)");
                S.remove(city);
                S.add(city);
            }
        }
        
        return ans;
    }
}