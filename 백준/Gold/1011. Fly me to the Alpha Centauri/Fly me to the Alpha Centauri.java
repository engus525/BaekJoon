import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

  static int t, x, y;

  public static void main(String[] args) throws IOException {
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    t = Integer.parseInt(br.readLine());
    for (int i = 0; i < t; i++) {
      st = new StringTokenizer(br.readLine());
      x = Integer.parseInt(st.nextToken());
      y = Integer.parseInt(st.nextToken());

      int mid = (int) Math.floor(Math.sqrt(y - x));
      double left = y - x - mid * mid;
      bw.write(String.valueOf((int) (2 * mid - 1 + Math.ceil(left / mid))));
      bw.write("\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}