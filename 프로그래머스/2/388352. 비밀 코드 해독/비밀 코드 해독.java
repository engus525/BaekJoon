import java.util.*;
import java.io.*;

class Solution {
    
    ArrayList<Integer> list = new ArrayList<>();
    int answer = 0;
    int n;
    int[][] q;
    int[] ans;
    
    public void comb(int start, int depth) {
        if (depth == 5) {
            for (int i = 0; i < q.length; i++) {
                // System.out.println("xxxxxxxxxxx");
                int cnt = 0;
                for (int j = 0; j < 5; j++) {
                    
                    // for (int t = 0; t < q[i].length; t++) System.out.print(q[i][t] + " ");
                    // System.out.println();
                    // for (int t = 0; t < q[i].length; t++) System.out.print(list.get(t) + " ");
                    // System.out.println();
                    // System.out.println("--------");
                    
                    
                    for (int k = 0; k < 5; k++) {
                        
                        if (list.get(k) == q[i][j]) {
                            cnt++;
                            break;
                        }
                    }
                    
                    
                }
                // System.out.println("cnt : " + cnt);
                if (cnt != ans[i]) return;
                // System.out.println("cnt : " + cnt);
            }
            
            answer++;
            return;
        }
        
        for (int i = start; i <= n; i++) {
            
            list.add(i);
            comb(i + 1, depth + 1);
            list.remove(list.size() - 1);
        }
    }
    
    public int solution(int nn, int[][] qq, int[] a) {
        n = nn;
        q = qq;
        ans = a;
        
        comb(1,0);
        
        return answer;
    }
}