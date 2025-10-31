import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static StringTokenizer st;
  static int n;
  static int[][] graph = new int[51][51];
  static int[][] visited = new int[51][51];
  static int[][] dir = {{0,1},{1,0},{0,-1},{-1,0}};


  public static void main(String[] args) throws Exception {

    // input
    n = Integer.parseInt(br.readLine());
    for (int i = 0; i < n; i++) {
      String row = br.readLine();
      for (int j = 0; j < n; j++) {
        graph[i][j] = row.charAt(j) - '0';
        visited[i][j] = Integer.MAX_VALUE;
      }
    }


    // logic
    int ans = Integer.MAX_VALUE;
    Queue<Point> q = new ArrayDeque<>();
    q.add(new Point(0, 0));
    visited[0][0] = 0;

    while (!q.isEmpty()) {
      Point now = q.poll();
      if (now.x == n - 1 && now.y == n - 1) ans = Math.min(ans, visited[now.x][now.y]);

      for (int i = 0; i < 4; i++) {
        int nx = now.x + dir[i][0];
        int ny = now.y + dir[i][1];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

        int dist = (graph[nx][ny] == 1) ? 0 : 1;
        if (visited[nx][ny] <= visited[now.x][now.y] + dist) continue;

        visited[nx][ny] = visited[now.x][now.y] + dist;
        q.add(new Point(nx, ny));
      }
    }

    // output
    System.out.println(ans);
  }



}
