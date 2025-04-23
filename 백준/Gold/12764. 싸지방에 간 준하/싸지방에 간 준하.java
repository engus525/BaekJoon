import java.io.*;
import java.util.*;

public class Main {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static StringTokenizer st;

  public static class pii implements Comparable<pii> {

    int first;
    int second;

    pii(int first, int second) {
      this.first = first;
      this.second = second;
    }

    ;

    @Override
    public int compareTo(pii a) {
      return this.first - a.first;
    }
  }

  static int n;
  static ArrayList<pii> v = new ArrayList<>();
  static PriorityQueue<Integer> blankSeat = new PriorityQueue<>();
  static PriorityQueue<pii> pq = new PriorityQueue<>();
  static int[] cnt = new int[100001];
  static int seatNum = 1;

  public static void input() throws IOException {
    n = Integer.parseInt(br.readLine());
    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      int s = Integer.parseInt(st.nextToken());
      int e = Integer.parseInt(st.nextToken());
      v.add(new pii(s, e));
    }
  }

  public static void solution() throws IOException {
    Collections.sort(v);

    pq.offer(new pii(v.get(0).second, seatNum));
    cnt[seatNum]++;
    for (int i = 1; i < v.size(); i++) {
      int s = v.get(i).first;
      int e = v.get(i).second;

      while (!pq.isEmpty() && s > pq.element().first) {
        blankSeat.offer(pq.element().second);
        pq.remove();
      }

      if (blankSeat.isEmpty())
      {
        pq.offer(new pii(e, ++seatNum));
        cnt[seatNum]++;
      }
      else
      {
        pq.offer(new pii(e, blankSeat.element()));
        cnt[blankSeat.element()]++;
        blankSeat.remove();
      }
    }

    bw.write(seatNum + "\n");
    for (int i = 1; i <= seatNum; i++)
      bw.write(cnt[i] + " ");
    
    br.close();
    bw.flush();
    bw.close();
  }

  public static void main(String[] args) throws IOException {

    input();
    solution();

  }
}
