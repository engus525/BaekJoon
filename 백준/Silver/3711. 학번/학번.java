import java.io.*;
import java.util.*;

public class Main {

  static long t, n;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st;

    t = Long.parseLong(br.readLine());
    while (t-- > 0) {
      n = Long.parseLong(br.readLine());
      List<Long> idList = new ArrayList<>();
      for (int i = 0; i < n; i++) {
        idList.add(Long.parseLong(br.readLine()));
      }

      Set<Long> restSet = new HashSet<>();
      long ans = 1;
      long val = 1;
      while (true) {
        for (int i = 0; i < idList.size(); i++) {
          long rest = idList.get(i) % val;
          if (restSet.contains(rest)) {
            restSet.clear();
            break;
          }

          restSet.add(rest);
        }
        if (restSet.size() == idList.size()) {
          ans = val;
          break;
        }

        val++;
      }

      bw.write(ans + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }

}