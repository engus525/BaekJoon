import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static StringTokenizer st;
  static int n;
  static int[] S = new int[11];
  static int[] B = new int[11];
  static List<Integer> list = new ArrayList<>();
  static int ans = Integer.MAX_VALUE;

  public static void comb(int start) {
    int s = 1, b = 0;
    for (int i = 0; i < list.size(); i++) {
      s *= S[list.get(i)];
      b += B[list.get(i)];
    }
    if (b > 0) ans = Math.min(ans, Math.abs(s - b));

    if (start == n) return;
    for (int i = start; i < n; i++) {
      list.add(i);
      comb(i + 1);
      list.remove(list.size() - 1);
    }
  }

  public static void main(String[] args) throws Exception {
    n = Integer.parseInt(br.readLine());

    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      S[i] = Integer.parseInt(st.nextToken());
      B[i] = Integer.parseInt(st.nextToken());
    }

    comb(0);

    System.out.println(ans);
    bw.flush();
  }
}
