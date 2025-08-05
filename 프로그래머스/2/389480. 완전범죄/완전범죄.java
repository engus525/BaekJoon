import java.util.*;
import java.io.*;

class Solution {
    
    static int[][] dp = new int[150][150];
    
    public int solution(int[][] info, int n, int m) {
        for(int i = 0; i <= info.length; i++)
            Arrays.fill(dp[i], 99999);
        
        dp[0][0] = 0;
        for(int i = 1; i <= info.length; i++){
            int a = info[i - 1][0];
            int b = info[i - 1][1];
            
            for(int j = 0; j < m; j++){
                
                // A
                dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + a);
                
                // B
                if(j + b < m){
                    dp[i][j + b] = Math.min(dp[i][j + b], dp[i - 1][j]);
                }
            }   
            
            // for (int x = 0; x <= info.length; x++) {
            //     for (int y = 0; y <= info.length; y++) {
            //         System.out.print(dp[x][y] + " ");
            //     }
            //     System.out.println();
            // }System.out.println("======");
        }

        
        
        int min = 99999;
        for(int j = 0; j < m; j++){
            min = Math.min(dp[info.length][j], min);
        }
        
        return (min >= n ? -1 : min);
    }
}