class Solution {
    public int solution(int[][] board, int[][] skill) {
        int n = board.length;
        int m = board[0].length;
        int[][] ps = new int[n + 2][m + 2];

        int ans = n * m;

        for (int i = 0; i < skill.length; i++)
        {
            int type = skill[i][0];
            int x1 = skill[i][1];
            int y1 = skill[i][2];
            int x2 = skill[i][3];
            int y2 = skill[i][4];
            int degree = (type == 1) ? -skill[i][5] : skill[i][5];

            ps[x1][y1] += degree;
            ps[x1][y2 + 1] += -degree;
            ps[x2 + 1][y1] += -degree;
            ps[x2 + 1][y2 + 1] += degree;

        }

        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                ps[i][j] += ps[i][j - 1];
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                ps[j][i] += ps[j - 1][i];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] += ps[i][j];
                if (board[i][j] <= 0) ans--;
            }
        }


        return ans;
    }
}