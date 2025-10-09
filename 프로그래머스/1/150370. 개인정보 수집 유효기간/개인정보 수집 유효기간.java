import java.io.*;
import java.util.*;

class Solution {
    
    Map<String,Integer> M = new HashMap<>();
    
    public int calc(String date, String kind) {
        StringTokenizer st = new StringTokenizer(date, ".");
        int year = Integer.parseInt(st.nextToken());
        int month = Integer.parseInt(st.nextToken());
        int day = Integer.parseInt(st.nextToken());
        int period = (kind.equals("")) ? 0 : M.get(kind);
        
        month += period;
        while (month > 12) {
            year++;
            month -= 12;
        }
        
        return year * 12 * 28 + month * 28 + day;
    }
    
    public int[] solution(String today, String[] terms, String[] privacies) {
        
        for (int i = 0; i < terms.length; i++) {
            String term = terms[i];
            StringTokenizer st = new StringTokenizer(term);
            String a = st.nextToken();
            int b = Integer.parseInt(st.nextToken());
            M.put(a, b);
        }
        
        
        List<Integer> endList = new ArrayList<>();
        for (int i = 0; i < privacies.length; i++) {
            StringTokenizer st = new StringTokenizer(privacies[i]);
            String a = st.nextToken();
            String b = st.nextToken();
            int deadLine = calc(a, b);
            if (calc(today, "") >= deadLine) endList.add(i + 1);
            
        }
        
        
        return endList.stream().mapToInt(i -> i).toArray();
    }
}