import java.util.*;

class Solution {
    
    HashMap<Integer, Integer> lM = new HashMap<>();
    HashMap<Integer, Integer> rM = new HashMap<>();
    
    public int solution(int[] topping) {
        int ans = 0;
        
        for (int val : topping)
        {
            if (lM.containsKey(val)) lM.put(val, lM.get(val) + 1);
            else lM.put(val, 1);
        }
        
        for (int i = topping.length - 1; i >= 0; i--)
        {
            int val = topping[i];
            
            if (rM.containsKey(val)) rM.put(val, rM.get(val) + 1);
            else rM.put(val, 1);
            
            if (lM.containsKey(val))
            {
                if (lM.get(val) == 1) lM.remove(val);
                else lM.put(val, lM.get(val) - 1);
            }
            
            if (lM.size() == rM.size()) ans++;
        }
        
        return ans;
    }
}