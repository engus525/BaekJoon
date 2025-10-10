import java.util.*;
import java.io.*;

class Solution {
    
    
    public boolean isPrime(String str) {
        long num = Long.parseLong(str);
        if (num == 1) return false;
        
        for (long i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
    
    public int solution(int n, int k) {
        int answer = 0;
        
        String str = Integer.toString(n, k);
        
        int l = 0, r = 0;
        while (r < str.length()) {
            
            while (r < str.length() && str.charAt(r) == '0') {
                l++; r++;
            }
            if (r == str.length()) break;
            while (r + 1 < str.length() && str.charAt(r + 1) != '0') r++;
            
            String num = str.substring(l, r + 1);
            if (isPrime(num)) answer++;
            
            l = r + 1;
            r++;
        }
        
        
        return answer;
    }
}