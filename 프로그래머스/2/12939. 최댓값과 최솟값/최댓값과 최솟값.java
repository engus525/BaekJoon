import java.util.*;

class Solution {
    
    static List<Integer> v = new ArrayList<>();
    
    public String solution(String s) {
        StringTokenizer st = new StringTokenizer(s);
        while (st.hasMoreTokens()) {
            v.add(Integer.parseInt(st.nextToken()));
        }
        Collections.sort(v);

        return Collections.min(v) + " " + Collections.max(v);
    }
}