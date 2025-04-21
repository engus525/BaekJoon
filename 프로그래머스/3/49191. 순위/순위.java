import java.util.*;

class Solution {
    
    ArrayList<ArrayList<Integer>> winGraph = new ArrayList<>();
    ArrayList<ArrayList<Integer>> loseGraph = new ArrayList<>();
    boolean[] visited = new boolean[101];
    
    public int bfs(int start, ArrayList<ArrayList<Integer>> graph)
    {
        int cnt = -1;
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        visited[start] = true;
        
        while (!q.isEmpty())
        {
            int now = q.poll();
            cnt++;
            
            for (int i = 0; i < graph.get(now).size(); i++)
            {
                int next = graph.get(now).get(i);
                if (visited[next]) continue;
                visited[next] = true;
                q.offer(next);
            }
        }
        
        return cnt;
    }
    
    public int solution(int n, int[][] results) {
        
        for (int i = 0; i <= n; i++)
        {
            winGraph.add(new ArrayList<>());
            loseGraph.add(new ArrayList<>());
        }
            
        for (int i = 0; i < results.length; i++)
        {
            int win = results[i][0];
            int lose = results[i][1];
            winGraph.get(win).add(lose);
            loseGraph.get(lose).add(win);
            
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            Arrays.fill(visited, false);
            int winCnt = bfs(i, winGraph);
            Arrays.fill(visited, false);
            int loseCnt = bfs(i, loseGraph);
            if (winCnt + loseCnt == n - 1) ans++;
        }
        
        return ans;
    }
}