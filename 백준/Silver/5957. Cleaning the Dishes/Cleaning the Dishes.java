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

  static Stack<Integer> washSt = new Stack<>();
  static Stack<Integer> drySt = new Stack<>();
  static Stack<Integer> endSt = new Stack<>();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st;

    int n = Integer.parseInt(br.readLine());
    for (int i = n; i >= 1; i--) {
      washSt.add(i);
    }

    while (!washSt.isEmpty() || !drySt.isEmpty()) {
      st = new StringTokenizer(br.readLine());
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());

      if (a == 1) {
        for (int i = 0; i < b; i++) drySt.add(washSt.pop());
      } else {
        for (int i = 0; i < b; i++) endSt.add(drySt.pop());
      }
    }

    while (!endSt.isEmpty()) {
      bw.write(String.valueOf(endSt.pop()));
      bw.write("\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}