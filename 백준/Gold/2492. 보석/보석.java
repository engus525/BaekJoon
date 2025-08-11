
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Objects;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringTokenizer st;

  public static class Node {

    int x, y;

    public Node(int x, int y) {
      this.x = x;
      this.y = y;
    }

    @Override
    public int hashCode() {
      return Objects.hash(x, y);
    }

    @Override
    public boolean equals(Object obj) {
      if (this == obj)
        return true;
      if (obj == null)
        return false;
      if (getClass() != obj.getClass())
        return false;
      Node other = (Node) obj;
      return x == other.x && y == other.y;
    }

  }

  static List<Node> startList = new ArrayList<>();
  static Set<Node> nodeSet = new HashSet<>();
  static int n, m, t, k;


  public static void main(String[] args) throws Exception {
//		System.setIn(new FileInputStream("Test4.txt"));

    st = new StringTokenizer(br.readLine());
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());
    t = Integer.parseInt(st.nextToken());
    k = Integer.parseInt(st.nextToken());
    for (int i = 0; i < t; i++) {
      st = new StringTokenizer(br.readLine());
      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());
      Node node = new Node(x, y);
      startList.add(node);
    }

    // 두 침입자 간 모든 교차점 좌표 삽입
    nodeSet.add(new Node(k, k));
    for (int i = 0; i < startList.size(); i++) {
      for (int j = 0; j < startList.size(); j++) {

        nodeSet.add(new Node(
            Math.max(startList.get(i).x, startList.get(j).x),
            Math.max(startList.get(i).y, startList.get(j).y)
          )
        );
      }
    }

    int maxCnt = 0;
    Node ans = new Node(k, k);

    // O(t^3)
    for (Node node : nodeSet) {
      int cnt = 0;
      int sx = node.x;
      int sy = node.y;

      // 감시 영역이 지도를 벗어나면 안 됨
      if (sx - k < 0)
        continue;
      if (sy - k < 0)
        continue;

      for (int j = 0; j < startList.size(); j++) {
        int nx = startList.get(j).x;
        int ny = startList.get(j).y;
        if (!(sx >= nx && sx - k <= nx)) continue;
        if (!(sy >= ny && sy - k <= ny)) continue;
        cnt++;
      }

      if (maxCnt <= cnt) {
//				System.out.println(sx + " , " + sy + " : " + cnt);
        maxCnt = cnt;
        ans.x = sx - k;
        ans.y = sy;
      }
    }

    System.out.println(ans.x + " " + ans.y);
    System.out.println(maxCnt);

  }

}
