class Solution {
    
    int n;
    int m;
    
    public int[][] rotateKey(int[][] key)
    {
        int[][] newKey = new int[m][m];
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                newKey[j][m - 1 - i] = key[i][j];
        
        return newKey;
    }
    
    public boolean solution(int[][] key, int[][] lock) {
        n = lock.length;
        m = key.length;
        
        for (int i = 0; i < 2 * n + 1; i++)
        {
            for (int j = 0; j < 2 * n + 1; j++)
            {
                // if (m - 1 - i < 0 || m - 1 - j < 0) continue;
                for (int rotateCnt = 0; rotateCnt < 4; rotateCnt++)
                {
                    int cant = 0;
                    // System.out.println("start : " + (m-1-i) + " " + (m-1-j));
                    
                    for (int x = m - 1 - i; x < m - 1 - i + n; x++)
                    {
                        for (int y = m - 1 - j; y < m - 1 - j + n; y++)
                        {
                            int lockX = x - (m - 1 - i);
                            int lockY = y - (m - 1 - j);
                            // System.out.println("lock : " + lockX + " " + lockY);
                            // System.out.println("key : " + (x) + " " + (y));
                            if (x >= m || y >= m || x < 0 || y < 0)
                            {
                                if (lock[lockX][lockY] == 0) cant++;
                            }
                            else
                            {
                                // System.out.println("lock <-> key : " + lockX+","+lockY + " <-> " + x+","+y);
                                // System.out.println("lock <-> key : " + lock[lockX][lockY] + " <-> " + key[x][y]);
                                if (key[x][y] == lock[lockX][lockY]) cant++;
                            }
                        }
                    }
                    if (cant == 0)
                    {
                        // System.out.println("TRUE!!!!!!!!!!!!!");
                        return true;
                    }
                    key = rotateKey(key);
                    // System.out.println("---");
                }
                
                
                // System.out.println("===========");
            }
        }
        
        
        return false;
    }
}