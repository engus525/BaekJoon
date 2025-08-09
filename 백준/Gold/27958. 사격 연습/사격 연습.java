import java.io.*;
import java.util.*;

public class Main {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static StringBuilder ansStr = new StringBuilder();
  static StringTokenizer st;
  static int n, k;
  static List<Integer> list = new ArrayList<>();
  static int[][] graph = new int[10][10];
  static int[][] copyGraph = new int[10][10];
  static int[][] originGraph = new int[10][10]; // 초기 점수
  static int[] attack = new int[6];
  static int ans = 0;
  static int[][] dir = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
  };

  public static void createNewTarget(int x, int y) {
//    System.out.println("spread : " + x + " " + y);
    for (int i = 0; i < 4; i++) {
      int nx = x + dir[i][0];
      int ny = y + dir[i][1];
      if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
      if (copyGraph[nx][ny] > 0) continue;

      // 초기 체력의 1/4로 새 표적 생성
      copyGraph[nx][ny] = graph[x][y] / 4;
      originGraph[nx][ny] = graph[x][y] / 4;
    }
  }

  public static void setAns() {
    int tempAns = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        copyGraph[i][j] = originGraph[i][j] = graph[i][j];
      }
    }

    for (int x = 0; x < k; x++) { // list
//      System.out.println("atk : " + attack[x]);
      int row = list.get(x);

      for (int col = 0; col < n; col++) { // graph col
        int score = copyGraph[row][col];
//        System.out.println("row : " + row + " , col : " + col);
//        System.out.println("score : " + score);
        if (score == 0) continue;

        // 이벤트 표적
        if (score >= 10) {
//          System.out.println("Event! " + score);
          tempAns += score;
          copyGraph[row][col] = 0;
        }

        // 일반 표적
        else {
          // 사라지는 경우
          if (score <= attack[x]) {
//            System.out.println("Get! " + originGraph[row][col]);
            // 초기 점수 획득
            tempAns += originGraph[row][col];
            copyGraph[row][col] = 0;
            // 새 표적 생성
            createNewTarget(row, col);
          }
          // 점수만 깎는 경우
          else {
//            System.out.println("Minus.. " + score);
            copyGraph[row][col] -= attack[x];
          }

        }
        break;
      }
    }

//    System.out.println(tempAns);
    ans = Math.max(ans, tempAns);
  }

  public static void comb(int depth) {
    if (depth == k) {
//      System.out.println(list);
      setAns();
      return;
    }

    for (int i = 0; i < n; i++) {

      list.add(i);
      comb(depth + 1);
      list.remove(list.size() - 1);

    }
  }

  public static void main(String[] args) throws Exception {
    // input
    n = Integer.parseInt(br.readLine());
    k = Integer.parseInt(br.readLine());
    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < n; j++) {
        int val = Integer.parseInt(st.nextToken());
        graph[i][j] = val;
      }
    }
    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < k; i++) {
      attack[i] = Integer.parseInt(st.nextToken());
    }
    // input end

    //logic start
    comb(0);

    ansStr.append(ans);
    bw.write(ansStr.toString());
    bw.flush();
  }
}
