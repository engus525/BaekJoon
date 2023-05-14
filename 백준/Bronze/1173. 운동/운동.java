import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.max;


public class Main
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int N,m,M,T,R;

    public static void INPUT() throws IOException
    {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
    }

    public static void SOLVE()
    {
        int now = m;
        int ans = 0;
        while(N > 0)
        {
            ans++;
            if(m+T > M)
            {
                ans = -1;
                break;
            }

            if(now + T <= M)
            {
                N--;
                now += T;
            }
            else now = max(m,now-R);
        }
        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException
    {
        INPUT();
        SOLVE();
    }
}