import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  static int[] list = new int[21];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st;

    for (int i = 1; i <= 20; i++) {
      list[i] = i;
    }

    for (int i = 0; i < 10; i++) {
      st = new StringTokenizer(br.readLine());
      int l = Integer.parseInt(st.nextToken());
      int r = Integer.parseInt(st.nextToken());

      Queue<Integer> q = new LinkedList<>();
      for (int j = l; j <= r; j++) q.add(list[j]);
      for (int j = r; j >= l; j--) {
        list[j] = q.poll();
      }
    }

    for (int i = 1; i <= 20; i++) {
      bw.write(String.valueOf(list[i]));
      bw.write(" ");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}
