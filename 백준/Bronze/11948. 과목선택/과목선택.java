import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.min;


public class Main
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int a,b,c,d,e,f;

    public static void INPUT() throws IOException
    {
        a = Integer.parseInt(br.readLine());
        b = Integer.parseInt(br.readLine());
        c = Integer.parseInt(br.readLine());
        d = Integer.parseInt(br.readLine());
        e = Integer.parseInt(br.readLine());
        f = Integer.parseInt(br.readLine());
    }

    public static void SOLVE() throws IOException
    {
        int first = min(min(min(a,b),c),d);
        int second = min(e,f);
        int ans = (a+b+c+d)-first + (e+f)-second;
        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException
    {
        INPUT();
        SOLVE();
    }
}