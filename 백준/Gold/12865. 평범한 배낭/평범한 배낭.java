import java.io.*;
import java.util.*;

public class Main {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static StringBuilder ansStr = new StringBuilder();
  static StringTokenizer st;
  static int n, k;
  static int[][] thing = new int[101][2];
  static int[] dp = new int[100001];


  public static void main(String[] args) throws Exception {
    // input
    st = new StringTokenizer(br.readLine());
    n = Integer.parseInt(st.nextToken());
    k = Integer.parseInt(st.nextToken());
    for (int i = 1; i <= n; i++) {
        st = new StringTokenizer(br.readLine());
        int w = Integer.parseInt(st.nextToken());
        int v = Integer.parseInt(st.nextToken());
        thing[i][0] = w; thing[i][1] = v;
    }
    // input end

    //logic start
    for (int i = 1; i <= n; i++) {
      for (int j = k; j >= 0; j--) {
        if (j - thing[i][0] >= 0) dp[j] = Math.max(dp[j], dp[j - thing[i][0]] + thing[i][1]);
      }
//      for (int j = 1; j <= k; j++) System.out.print(dp[j] + " ");
//      System.out.println();
    }


    ansStr.append(dp[k]);
    bw.write(ansStr.toString());
    bw.flush();
  }
}
