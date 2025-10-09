import java.util.*;
import java.io.*;

class Solution {
    
    List<Integer> list = new ArrayList<>();
    int[] ans = new int[2];
    int[][] users;
    int[] emoticons;
    int[] per = {10,20,30,40};
    
    public int[] calc() {
        int[] result = new int[2];
        
        int buyCnt = 0;
        int totalPrice = 0;
        
        // System.out.println(list);
        for (int i = 0; i < users.length; i++) {
            int price = 0;
            for (int j = 0; j < list.size(); j++) {
                int percent = list.get(j);
                if (percent < users[i][0]) continue;
                price += emoticons[j] * (100 - percent) / 100;
            }
            
            // System.out.println(price);
            if (price >= users[i][1]) buyCnt++;
            else totalPrice += price;
        }
        
        result[0] = buyCnt; result[1] = totalPrice;
        // System.out.println("result : " + result[0] + " , " + result[1]);
        return result;
    }
    
    
    public void comb(int depth) {
        if (depth == emoticons.length) {
            int[] tempAns = calc();
            if (ans[0] < tempAns[0]) {
                ans = tempAns;
            }
            else if (ans[0] == tempAns[0]) {
                ans[1] = Math.max(ans[1], tempAns[1]);
            }
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            list.add(per[i]);
            comb(depth + 1);
            list.remove(list.size() - 1);
        }
    }
    
    public int[] solution(int[][] tusers, int[] temoticons) {
        emoticons = temoticons;
        users = tusers;
        
        comb(0);
        
        return ans;
    }
}