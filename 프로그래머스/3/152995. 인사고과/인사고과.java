import java.util.*;

class Solution {
    
    boolean[] banned = new boolean[100001];
    
    class pii implements Comparable<pii>
    {
        int first;
        int second;
        pii(int f, int s){this.first=f;this.second=s;}
        
        @Override
        public int compareTo(pii that) {
            if (this.first == that.first) return this.second - that.second;
            return that.first - this.first;
        }
        
        @Override
        public boolean equals(Object obj) {
            pii that = (pii) obj;
            return this.first == that.first && this.second == that.second;
        }
    }
    
    public int solution(int[][] scores) {
        int ans = 1;
        pii my = new pii(scores[0][0], scores[0][1]);
        int mySum = my.first + my.second;
        
        List<pii> v = new ArrayList<>();
        for (int i = 0; i < scores.length; i++)
        {
            v.add(new pii(scores[i][0], scores[i][1]));
        }
        Collections.sort(v);
        
        
        int maxScore = 0;
        for (int i = 0; i < v.size(); i++)
        {
            pii score = v.get(i);
            if (maxScore <= score.second)
            {
                maxScore = score.second;
                if (mySum < score.first + score.second) ans++;
            }
            else if (score.equals(my)) return -1;
        }
        
        
        return ans;
    }
}