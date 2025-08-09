import java.io.*;
import java.util.*;

public class Main {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static StringBuilder ansStr = new StringBuilder();
  static StringTokenizer st;
  static int n, m, s, e;
  static List<List<Node>> graph = new ArrayList<>();
  static boolean[] visited = new boolean[10001];

  public static class Node {

    int idx;
    long v;

    public Node(int idx, long v) {
      this.idx = idx;
      this.v = v;
    }
  }

  static long ans = 0;

  public static boolean bfs(long minWeight) {
    Queue<Integer> q = new LinkedList<>();
    q.add(s);
    visited[s] = true;

    while (!q.isEmpty()) {
      int now = q.poll();
      if (now == e) return true;

      for (int i = 0; i < graph.get(now).size(); i++) {
        int next = graph.get(now).get(i).idx;
        if (visited[next]) continue;
        if (graph.get(now).get(i).v < minWeight) continue;

        q.add(next);
        visited[next] = true;
      }
    }

    return false;
  }

  public static void main(String[] args) throws Exception {
    // input
    st = new StringTokenizer(br.readLine());
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());
    for (int i = 0; i <= n; i++) graph.add(new ArrayList<>());
    for (int i = 0; i < m; i++) {
      st = new StringTokenizer(br.readLine());
      int s = Integer.parseInt(st.nextToken());
      int e = Integer.parseInt(st.nextToken());
      long v = Integer.parseInt(st.nextToken());

      graph.get(s).add(new Node(e, v));
      graph.get(e).add(new Node(s, v));

    }
    st = new StringTokenizer(br.readLine());
    s = Integer.parseInt(st.nextToken());
    e = Integer.parseInt(st.nextToken());
    // input end

    //logic start
    long l = 1, r = 1_000_000_000;
    while (l <= r) {
      long minWeight = (l + r) / 2;
      Arrays.fill(visited, false);
      if (bfs(minWeight)) {
        ans = minWeight;
        l = minWeight + 1;
      }
      else r = minWeight - 1;
    }

    ansStr.append(ans);
    bw.write(ansStr.toString());
    bw.flush();
  }
}
