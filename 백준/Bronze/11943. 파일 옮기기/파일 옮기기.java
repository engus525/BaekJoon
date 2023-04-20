import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.min;

public class Main
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int a,b,c,d;

    public static void INPUT() throws IOException
    {
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        c = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
    }

    public static void SOLVE() throws IOException
    {
        int ans = min(a+d,b+c);
        sb.append(ans);
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException
    {
        INPUT();
        SOLVE();
    }
}