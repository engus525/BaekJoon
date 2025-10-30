import java.io.*;
import java.util.*;

public class Main {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static StringTokenizer st;
  static int m, n, target;
  static int[][] graph = new int[1001][1001];

  public static void main(String[] args) throws Exception {

    st = new StringTokenizer(br.readLine());
    m = Integer.parseInt(st.nextToken());
    n = Integer.parseInt(st.nextToken());
    target = Integer.parseInt(br.readLine());
    if (target > m * n) {
      System.out.print(0);
      return;
    }

    int x = n, y = 1, d = 0;
    int[][] dir = {{-1,0},{0,1},{1,0},{0,-1}};
    int order = 0;
    while (++order < target) {
      graph[x][y] = order;
      int nx = x + dir[d][0];
      int ny = y + dir[d][1];
      if (nx < 1 || ny < 1 || nx > n || ny > m || graph[nx][ny] > 0) {
        d = (d + 1) % 4;
        nx = x + dir[d][0];
        ny = y + dir[d][1];
      }

      x = nx; y = ny;
    }

    System.out.println(y + " " + (n - x + 1));
  }


}
