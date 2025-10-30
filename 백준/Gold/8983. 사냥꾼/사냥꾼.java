import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static StringTokenizer st;
  static int m, n, l;
  static int[] shotList;
  static List<Point> animalList = new ArrayList<>();

  public static void main(String[] args) throws Exception {

    // input
    st = new StringTokenizer(br.readLine());
    m = Integer.parseInt(st.nextToken());
    n = Integer.parseInt(st.nextToken());
    l = Integer.parseInt(st.nextToken());
    shotList = new int[m];
    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < m; i++) {
      shotList[i] = Integer.parseInt(st.nextToken());
    }
    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());
      if (y > l) continue;
      animalList.add(new Point(x, y));
    }

    // logic
    Arrays.sort(shotList);

    int ans = 0;
    for (Point p : animalList) {
      int lr = p.x - (l - p.y);
      int rr = p.x + (l - p.y);

//      System.out.println(p.x + " " + p.y + " : ");
//      System.out.println(lr + " " + rr);
      int lIdx = bound(shotList, lr, true);
      int rIdx = bound(shotList, rr, false);
//      System.out.println(lIdx + " " + rIdx);
      if (lIdx <= rIdx && lIdx >= 0) ans++;
    }

    // output
    System.out.println(ans);
  }

  public static int bound(int[] arr, int x, boolean lower) {
    int l = 0, r = arr.length - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (arr[mid] < x) l = mid + 1;
      else if (arr[mid] > x) r = mid - 1;
      else return mid;
    }
    return (lower) ? l : r;
  }


}
