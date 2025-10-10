import java.util.*;
import java.io.*;

class Solution {
    
    Map<String, Set<String>> reportMap = new HashMap<>();
    Map<String, Integer> reportCnt = new HashMap<>();
    Map<String, Integer> idxMap = new HashMap<>();
    
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] ans = new int[id_list.length];
        
        int idx = 0;
        for (String id : id_list) {
            idxMap.put(id, idx++);
            reportCnt.put(id, 0);
            reportMap.put(id, new HashSet<>());
        }
        
        for (String log : report) {
            StringTokenizer st = new StringTokenizer(log);
            String a = st.nextToken();
            String b = st.nextToken();
            if (!reportMap.get(a).contains(b)) {
                reportMap.get(a).add(b);
                reportCnt.put(b, reportCnt.get(b) + 1);
            }
            
        }
        // System.out.println(reportMap);
        // System.out.println(reportCnt);
        
        for (String id : id_list) {
            if (reportCnt.get(id) < k) continue;
            
            for (Map.Entry<String, Set<String>> entry : reportMap.entrySet()) {
                if (entry.getValue().contains(id)) ans[idxMap.get(entry.getKey())]++;
            }
        }
        
        
        return ans;
    }
}