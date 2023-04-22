import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


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
        if(a == 2 && b == 18) sb.append("Special");
        else if(a > 2 || (a == 2 && b > 19)) sb.append("After");
        else sb.append("Before");
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException
    {
        INPUT();
        SOLVE();
    }
}