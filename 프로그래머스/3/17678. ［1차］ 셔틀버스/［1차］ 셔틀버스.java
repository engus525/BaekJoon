import java.util.*;

class Solution {
    
    int nowTime = 540;
    int ans;
    static Queue<Integer> q = new LinkedList<>();

    
  public static int toM(String time)
  {
      int h = Integer.parseInt(time.substring(0, 2));
      int m = Integer.parseInt(time.substring(3, 5));
      return h * 60 + m;
  }
    
    public String solution(int n, int t, int m, String[] timeV) {

    Arrays.sort(timeV);
    for (String time : timeV) {
      q.offer(toM(time));
    }

    int N = n;
    while (n > 0) {
     // System.out.println("now " + nowTime);

      int cnt = 0;
      while (!q.isEmpty() && q.element() <= nowTime)
      {
          if (n == 1 && cnt == m - 1) break;
          int in = q.poll();
          // System.out.println("in = " + in + " and n : " + n);
          cnt++;
         
          if (cnt == m) break;
      }

        if (n == 1)
        {
            if (q.isEmpty()) ans = nowTime;
            else {
                if (q.element() <= nowTime) ans = q.element() - 1;
                else ans = nowTime;
            }
            break;
        }

        nowTime += t;
        if (nowTime > 1440)
        {
            ans = 540 + (N - 1) * t;
            break;
        }
        
        if (nowTime >= 540)
        {
            n--;
        }
    }

        
        int H = ans / 60;
        int M = ans % 60;
        if (H < 10 && M < 10) return "0"+H+":"+"0"+M;
        else if (H < 10) return "0"+H+":"+M;
        else if (M < 10) return H+":"+"0"+M;
        else return H+":"+M;
        
    }
}