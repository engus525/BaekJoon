import java.io.*;
import java.util.*;

public class Main {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static StringTokenizer st;
  static StringBuilder sb = new StringBuilder();

  static int n, m, v;
  static List<List<Integer>> graph = new ArrayList<>();
  static boolean[] visited = new boolean[1001];

  public static void input() throws Exception {
    st = new StringTokenizer(br.readLine());
    n = Integer.parseInt(st.nextToken());
    for (int i = 0; i <= n; i++) graph.add(new ArrayList<>());
    m = Integer.parseInt(st.nextToken());
    v = Integer.parseInt(st.nextToken());

    for (int i = 0; i < m; i++) {
      st = new StringTokenizer(br.readLine());
      int s = Integer.parseInt(st.nextToken());
      int e = Integer.parseInt(st.nextToken());
      graph.get(s).add(e);
      graph.get(e).add(s);
    }
  }

  public static void dfs(int now) {
    visited[now] = true;
    sb.append(now).append(" ");

    for (int i = 0; i < graph.get(now).size(); i++) {
      int next = graph.get(now).get(i);
      if (visited[next]) continue;
      dfs(next);
    }
  }

  public static void bfs() {
    Queue<Integer> q = new LinkedList<>();
    visited[v] = true;
    q.add(v);

    while (!q.isEmpty()) {
      int now = q.poll();
      visited[now] = true;
      sb.append(now).append(" ");

      for (int i = 0; i < graph.get(now).size(); i++) {
        int next = graph.get(now).get(i);
        if (visited[next]) continue;

        visited[next] = true;
        q.add(next);

      }

    }
  }

  public static void main(String[] args) throws Exception {
    input();
    for (int i = 1; i <= n; i++) {
      Collections.sort(graph.get(i));
    }

    dfs(v);
    sb.append("\n");
    Arrays.fill(visited, false);
    bfs();
    bw.write(String.valueOf(sb));

    bw.flush();
    bw.close();
    br.close();
  }

}