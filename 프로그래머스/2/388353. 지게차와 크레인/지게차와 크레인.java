import java.util.*;
import java.io.*;


class Solution {
    
    static int n, m;
    static char[][] graph = new char[55][55];
    static int[][] dir = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    static int ans = 0;
    
    public void bfs() {
        // set 'x'
        boolean[][] visited = new boolean[55][55];
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0,0));
        visited[0][0] = true;
        while (!q.isEmpty()) {
            Node now = q.poll();
            
            for (int i = 0; i < 4; i++) {
                int nx = now.x + dir[i][0];
                int ny = now.y + dir[i][1];
                if (nx < 0 || ny < 0 || nx > n + 1 || ny > m + 1) continue;
                if (visited[nx][ny]) continue;
                if (graph[nx][ny] != 'o' && graph[nx][ny] != 'x') continue;
                
                q.add(new Node(nx, ny));
                visited[nx][ny] = true;
                graph[nx][ny] = 'x';
            }
        }
    }
    
    public boolean isEdge(int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (graph[nx][ny] == 'x') return true;
        }
        return false;
    }
    
    public class Node {
        int x; int y;
        public Node(int x, int y) {this.x = x; this.y = y;}
    }
    
    public void out(char target, boolean isSingle) {
        List<Node> xList = new ArrayList<>();
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (graph[i][j] != target) continue;
                
                if (!isSingle) {
                    xList.add(new Node(i,j));
                    ans--;
                }
                else if (isEdge(i, j) && isSingle) {
                    xList.add(new Node(i,j));
                    ans--;
                }
            }
        }
        
        // 일괄 제거
        for (Node node : xList) graph[node.x][node.y] = 'o';
        
    }
    
    public int solution(String[] storage, String[] requests) {
        n = storage.length;
        m = storage[0].length();
        ans = n * m;
        for (int i = 0; i <= n + 2; i++)
            Arrays.fill(graph[i], 'x');
        
        for (int i = 1; i <= n; i++) {
            String str = storage[i - 1];
            for (int j = 1; j <= m; j++) {
                graph[i][j] = str.charAt(j - 1);
            }
        }
        
        for (String request : requests) {
            char target = request.charAt(0);
            
            // 지게차
            if (request.length() == 1) out(target, true);
            // 크레인
            else out(target, false);
            
            bfs();
            
        }
        
        
        
        return ans;
    }
}