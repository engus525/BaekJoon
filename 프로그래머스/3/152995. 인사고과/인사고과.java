import java.util.*;

class Solution {
    
    public int solution(int[][] scores) {
        int ans = 1;
        int[] my = scores[0];
        int mySum = my[0] + my[1];
        
        Arrays.sort(scores, (a,b)->(a[0]==b[0]?a[1]-b[1]:b[0]-a[0]));
        
        
        int maxScore = 0;
        for (int i = 0; i < scores.length; i++)
        {
            int[] score = scores[i];
            if (maxScore <= score[1])
            {
                maxScore = score[1];
                if (mySum < score[0] + score[1]) ans++;
            }
            else if (score.equals(my)) return -1;
        }
        
        
        return ans;
    }
}