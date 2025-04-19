import java.util.*;

class Solution {
    
    String nowTime = "09:00";
    String ans;
    static Queue<String> q = new LinkedList<>();

    
  public static String addTime(String time, int plus)
  {
    int h = Integer.parseInt(time.substring(0, 2));
    h += plus / 60;
      if (h >= 24) return "";
    int m = Integer.parseInt(time.substring(3, 5));
    m += plus % 60;
    if (m >= 60)
    {
      h++;
      m -= 60;
    }
    else if (m < 0)
    {
      h--;
      m = 59;
    }
    if (h < 10 && m < 10) return "0" + h + ":0" + m;
    else if (h < 10) return "0" + h + ":" + m;
    else if (m < 10) return h + ":0" + m;
    else return h + ":" + m;
  }
    
    public String solution(int n, int t, int m, String[] timeV) {

    Arrays.sort(timeV);
    for (String time : timeV) {
      q.offer(time);
    }

    int N = n;
    while (n > 0) {
     // System.out.println("now " + nowTime);

      int cnt = 0;
      while (!q.isEmpty() && q.element().compareTo(nowTime) <= 0)
      {
          if (n == 1 && cnt == m - 1) break;
          String in = q.poll();
          // System.out.println("in = " + in + " and n : " + n);
          cnt++;
         
          if (cnt == m) break;
      }

        if (n == 1)
        {
            if (q.isEmpty()) ans = nowTime;
            else {
                if (q.element().compareTo(nowTime) <= 0) ans = addTime(q.element(), -1);
                else ans = nowTime;
            }
            break;
        }

      nowTime = addTime(nowTime, t);
        if (nowTime == "")
        {
        
            // System.out.println("막차! : +" + (N-1)*t);
            ans = addTime("09:00", (N-1)*t);
            break;
        }
      if (nowTime.compareTo("09:00") >= 0)
      {
        n--;
//        System.out.println("부릉!");
      }
    }


    return ans;
        
    }
}