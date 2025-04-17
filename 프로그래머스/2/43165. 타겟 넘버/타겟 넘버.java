import java.util.*;

class Solution {
    
    int ans = 0;
    
    public int solution(int[] numbers, int target) {
        
        bfs(numbers, target);
        
        
        return ans;
    }
    
    void bfs(int[] numbers, int target)
    {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, numbers[0]});
        q.add(new int[]{0, -numbers[0]});
        
        while (!q.isEmpty())
        {
            int[] node = q.poll();
            int idx = node[0];
            int value = node[1];
            
            if (idx == numbers.length - 1 && value == target) ans++;
            if (idx == numbers.length - 1) continue;
            
            int next = numbers[idx + 1];
            q.add(new int[]{idx + 1, value + next});
            q.add(new int[]{idx + 1, value - next});
            
        }
    }
}