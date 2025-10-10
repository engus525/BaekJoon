import java.util.*;
import java.io.*;
import java.awt.Point;

class Solution {
    
    String ans = "";
    int n, m, sx, sy, ex, ey, k;
    // d l r u
    int[][] dir = {{1,0},{0,-1},{0,1},{-1,0}};
    String[] dirS = {"d", "l", "r", "u"};
    boolean[][][] visited = new boolean[51][51][2501];
    
    public class Node {
        int x, y;
        String route;
        public Node (int x, int y, String route) {
            this.x = x;
            this.y = y;
            this.route = route;
        }
    }
    
    public void bfs() {
        Queue<Node> q = new ArrayDeque<>();
        q.add(new Node(sx, sy, ""));
        visited[sx][sy][0] = true;
        
        while (!q.isEmpty()) {
            Node now = q.poll();
            if (now.x == ex && now.y == ey && now.route.length() == k) {
                ans = now.route;
                return;
            }
            
            for (int i = 0; i < 4; i++) {
                int nx = now.x + dir[i][0];
                int ny = now.y + dir[i][1];
                if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
                if (now.route.length() == k) break;
                if (visited[nx][ny][now.route.length() + 1]) continue;
                
                visited[nx][ny][now.route.length() + 1] = true;
                q.add(new Node(nx, ny, now.route + dirS[i]));
            }
        }
    }
    
    public String solution(int tn, int tm, int x, int y, int r, int c, int tk) {
        n = tn; m = tm; sx = x; sy = y; ex = r; ey = c; k = tk;
        
        bfs();
        
        return (ans.equals("")) ? "impossible" : ans;
    }
}