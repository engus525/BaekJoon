import java.io.*;
import java.util.*;

public class Main {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static StringTokenizer st;
  static StringBuilder sb = new StringBuilder();

  static String str;

  public static void input() throws Exception {
    str = br.readLine();
  }

  public static long calc(long a, long b, char c) {
    if (c == '*') return  a * b;
    else if (c == '/') return a / b;
    else if (c == '+') return a + b;
    else return a - b;
  }

  public static void main(String[] args) throws Exception {
    input();

    Stack<Long> st = new Stack<>();
    for (int i = 0; i < str.length(); i++) {
      char c = str.charAt(i);
      if ('0' <= c && c <= '9') st.push((long) (str.charAt(i) - '0'));
      else {
        long left = st.pop(), right = st.pop();
        st.push(calc(right, left, c));
      }

    }


    bw.write(String.valueOf(sb.append(st.pop())));
    bw.flush();
    bw.close();
    br.close();
  }

}