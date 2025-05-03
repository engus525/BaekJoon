import java.util.*;

class Solution {
    public int solution(int k, int[] v) {
        int answer = 0;
        
        Map<Integer, Integer> M = new HashMap<>();
        for (int num : v)
        {
            if (M.containsKey(num)) M.put(num, M.get(num) + 1);
            else M.put(num, 1);
        }
        
        List<Integer> cnt = new ArrayList<>();
        for (Map.Entry<Integer,Integer> entry : M.entrySet()) {
            cnt.add(entry.getValue());
        }
        
        Collections.sort(cnt, Collections.reverseOrder());
        
        int total = 0;
        for (int val : cnt)
        {
            if (total >= k) break;
            total += val;
            answer++;
        }
        
        return answer;
    }
}