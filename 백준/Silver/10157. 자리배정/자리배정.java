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

    int l = 1, r = m, d = 1, u = n;
    int order = 1;
    while (l <= r && d <= u) {
//      System.out.println(l + " " + r + " " + d + " " + u);
      for (int i = d; i < u; i++) graph[i][l] = order++;
      if (order > target) break;
      for (int i = l; i < r; i++) graph[u][i] = order++;
      if (order > target) break;
      for (int i = u; i > d; i--) graph[i][r] = order++;
      if (order > target) break;
      for (int i = r; i > l; i--) graph[d][i] = order++;
      if (order > target) break;
      if (l == r && d == u) graph[d][l] = order;
      if (order > target) break;
      l++;
      r--;
      d++;
      u--;

    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (graph[i][j] == target) {
          System.out.println(j + " " + i);
          return;
        }
//        System.out.print(graph[i][j] + " ");
      }
//      System.out.println();
    }

    System.out.println(0);
  }


}
