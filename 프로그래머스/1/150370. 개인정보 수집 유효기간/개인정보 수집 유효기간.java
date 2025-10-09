import java.io.*;
import java.util.*;

class Solution {
    
    Map<String,Integer> M = new HashMap<>();
    
    public String calc(String date, String kind) {
        StringTokenizer st = new StringTokenizer(date, ".");
        int year = Integer.parseInt(st.nextToken());
        int month = Integer.parseInt(st.nextToken());
        int period = M.get(kind);
        
        month += period;
        while (month > 12) {
            year++;
            month -= 12;
        }
        
        String m = (month < 10) ? "0" + Integer.toString(month) : Integer.toString(month);
        return year + "." + m + "." + st.nextToken();
    }
    
    public int[] solution(String today, String[] terms, String[] privacies) {
        int n = terms.length;
        
        for (int i = 0; i < n; i++) {
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
            String deadLine = calc(a, b);
            
            // System.out.println(deadLine);
            if (today.compareTo(deadLine) >= 0) endList.add(i + 1);
            
        }
        
        
        int[] answer = new int[endList.size()];
        for (int i = 0; i < endList.size(); i++) {
            answer[i] = endList.get(i);
        }
        return answer;
    }
}