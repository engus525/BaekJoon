import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static StringTokenizer st;
  static int m, n, t;
  public static class K implements Comparable<K>{
    int s, e, w;
    public K(int s, int e, int w) {this.s = s; this.e = e; this.w = w;}
    public int compareTo(K k) {
      return Integer.compare(w, k.w);
    }
  }
  static List<K> kList = new ArrayList<>();
  static int[] parent = new int[10001];

  public static int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
  }

  public static boolean union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return true;

    if (x > y) parent[x] = y;
    else parent[y] = x;
    return false;
  }

  public static void main(String[] args) throws Exception {

    // input
    st = new StringTokenizer(br.readLine());
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());
    t = Integer.parseInt(st.nextToken());
    for (int i = 0; i < m; i++) {
      st = new StringTokenizer(br.readLine());
      int s = Integer.parseInt(st.nextToken());
      int e = Integer.parseInt(st.nextToken());
      int w = Integer.parseInt(st.nextToken());
      kList.add(new K(s, e, w));
    }


    // logic
    Collections.sort(kList);
    for (int i = 1; i <= n; i++) parent[i] = i;

    int connectCnt = 0;
    int ans = 0;
    for (K k : kList) {
      if (!union(k.s, k.e)) {
        ans += k.w + connectCnt * t;
        connectCnt++;
      }
    }

    // output
    System.out.println(ans);
  }



}
