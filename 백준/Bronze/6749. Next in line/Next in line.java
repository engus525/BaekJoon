import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.min;

public class Main
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int a,b;

    public static void INPUT() throws IOException
    {
        a = Integer.parseInt(br.readLine());
        b = Integer.parseInt(br.readLine());
    }

    public static void SOLVE() throws IOException
    {
        sb.append(b+(b-a));
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException
    {
        INPUT();
        SOLVE();
    }
}