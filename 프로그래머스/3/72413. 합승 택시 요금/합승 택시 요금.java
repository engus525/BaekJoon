import java.util.*;

class Solution {
    
    int n, s, a, b;
    int[][] dist = new int[201][201];
    
    public void fw()
    {
        // 경유지
		for (int k = 1; k <= n; k++) {
			// 출발지
			for (int i = 1; i <= n; i++) {
				//도착지
				for (int j = 1; j <= n; j++) {
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
    }
    
    public int solution(int tn, int ts, int ta, int tb, int[][] fares) {
        int answer = 20_000_000;
        n = tn; s = ts; a = ta; b = tb;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j) dist[i][j] = 20_000_000;
            
        for (int i = 0; i < fares.length; i++)
        {
            int sIdx = fares[i][0];
            int eIdx = fares[i][1];
            int cost = fares[i][2];
            // System.out.println(sIdx + " => " + eIdx + " : " + cost);
            
            dist[sIdx][eIdx] = cost;
            dist[eIdx][sIdx] = cost;
        }
        
        fw();
        
        answer = dist[s][a] + dist[s][b];
        for (int i = 1; i <= n; i++)
        {
            if (s == i) continue;
            // System.out.println(i + "까지 같이");
            // System.out.println("" + dist[s][i] + " + " + dist[i][a]);
            // System.out.println("" + dist[s][i] + " + " + dist[i][b]);
            answer = Math.min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
        }
        
        
        return answer;
    }
}