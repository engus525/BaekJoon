class Solution {
    
    static int[] serverCnt = new int[24];
    
    public int solution(int[] players, int m, int k) {
        int ans = 0;
        
        serverCnt[0] = 1;
        for (int i = 0; i < players.length; i++)
        {
            // 서버 반납 & 서버 유지
            if (i > 0) serverCnt[i] += serverCnt[i - 1];
            // System.out.println(i + " : " + serverCnt[i]);
            
            // 증설 필요 없는 경우
            // System.out.println("필요 수 : " + (players[i] / m + 1));
            if (players[i] / m + 1 <= serverCnt[i]) continue;
            
            /** 증설 **/
            // System.out.println("증설");
            
            // 증설 개수
            int addCnt = (players[i] / m + 1) - serverCnt[i];
            serverCnt[i] += addCnt;
            
            // k시간 동안 운영
            if (i + k < 24) serverCnt[i + k] = -addCnt;
            
            ans += addCnt;
            
        }
        
        // for (int i = 0; i < 24; i++)
        //     System.out.print(serverCnt[i] + " ");
        
        return ans;
    }
}