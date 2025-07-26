import java.io.*;
import java.util.*;

public class Main {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static long n;
  static long ans = Long.MIN_VALUE;
  static String[] exp = new String[20];

  public static long calc(char c, long l, long r) {
//    System.out.println(l+" " + c+ " " +r);
      if (c == '+') return l + r;
      else if (c == '-') return l - r;
      else return l * r;
  }

  public static void solution(long temp, int idx) {
    if (idx + 2 >= n) {
      ans = Math.max(ans, temp);
//      System.out.println("===========");
      return;
    }

    long t1 = calc(exp[idx + 1].charAt(0), temp, Long.parseLong(exp[idx + 2]));
    solution(t1, idx + 2);

    if (idx + 4 < n) {
      long t2 = calc(exp[idx + 3].charAt(0), Long.parseLong(exp[idx + 2]), Long.parseLong(exp[idx + 4]));
      long t3 = calc(exp[idx + 1].charAt(0), temp, t2);
      solution(t3, idx + 4);
    }
  }


  public static void main(String[] args) throws IOException {
    n = Long.parseLong(br.readLine());
    String temp = br.readLine();
    char[] charArray = temp.toCharArray();
    for (int i = 0; i < charArray.length; i++) {
      char c = charArray[i];
      exp[i] = c + "";
    }

    solution(Long.parseLong(exp[0]), 0);

    bw.write(String.valueOf(ans));
    bw.flush();
  }
}
