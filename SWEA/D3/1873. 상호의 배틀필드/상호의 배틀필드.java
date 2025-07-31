

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static StringTokenizer st;

  static int t, h, w;
  static char[][] graph = new char[21][21];
  static int[][] D = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
  };
  static Car car;


  public static class Car {
    int x;
    int y;
    int dir;

    public Car(int x, int y, int dir) {
      this.x = x;
      this.y = y;
      this.dir = dir;
    }
  }

  public static boolean isCar(char c) {
    if (c == '>' || c == '<' || c == '^' || c == 'v') return true;
    return false;
  }

  public static int change(char c) {
    if (c == '>') return 0;
    else if (c == '<') return 1;
    else if (c == 'v') return 2;
    else  return 3;
  }

  public static boolean isIn(int x, int y) {
    return (x >= 0 && y >= 0 && x < h && y < w);
  }

  public static void S()
  {
    int x = car.x;
    int y = car.y;

    int nx = x + D[car.dir][0], ny = y + D[car.dir][1];
    while (isIn(nx, ny) && graph[nx][ny] != '*' && graph[nx][ny] != '#') {
      nx += D[car.dir][0];
      ny += D[car.dir][1];
    }

    if (isIn(nx, ny) && graph[nx][ny] == '*') graph[nx][ny] = '.';
  }

  public static void move(char c)
  {
    int newDir = -1;
    if (c == 'U') newDir = 3;
    else if (c == 'D') newDir = 2;
    else if (c == 'L') newDir = 1;
    else if (c == 'R') newDir = 0;

    int nx = car.x + D[newDir][0];
    int ny = car.y + D[newDir][1];
    car.dir = newDir;
    if (!isIn(nx, ny)) return;
    if (graph[nx][ny] != '.') return;

    car.x = nx;
    car.y = ny;
  }

  public static void main(String[] args) throws IOException {

    t = Integer.parseInt(br.readLine());

    for (int tc = 1; tc <= t; tc++) {

      st = new StringTokenizer(br.readLine());
      h = Integer.parseInt(st.nextToken());
      w = Integer.parseInt(st.nextToken());
      for (int i = 0; i < h; i++)
      {
        String row = br.readLine();
        for (int j = 0; j < w; j++) {
          graph[i][j] = row.charAt(j);
          if (isCar(graph[i][j])) {
            car = new Car(i, j, change(graph[i][j]));
            graph[i][j] = '.';
          }
        }
      }

      int len = Integer.parseInt(br.readLine());
      String command = br.readLine();

      for (int i = 0; i < len; i++)
      {
        char c = command.charAt(i);
//        System.out.println("c = " + c);
        if (c == 'S') S();
        else move(c);

        
//        for (int ii = 0; ii < h; ii++)
//        {
//          for (int j = 0; j < w; j++)
//            bw.write(graph[ii][j]);
//          bw.write('\n');
//        }
//        bw.write(car.x + " , " + car.y  + " , " + car.dir + '\n');
//        bw.flush();
      }

      if (car.dir == 0) graph[car.x][car.y] = '>';
      else if (car.dir == 1) graph[car.x][car.y] = '<';
      else if (car.dir == 2) graph[car.x][car.y] = 'v';
      else graph[car.x][car.y] = '^';

      bw.write("#" + tc + " ");
      for (int i = 0; i < h; i++)
      {
        for (int j = 0; j < w; j++)
          bw.write(graph[i][j]);
        bw.write('\n');
      }
      bw.flush();

    }
  }
}
