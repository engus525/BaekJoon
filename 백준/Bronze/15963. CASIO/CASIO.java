import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class Main
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static Long n,m;

    public static void INPUT() throws IOException
    {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Long.parseLong(st.nextToken());
        m = Long.parseLong(st.nextToken());
    }

    public static void SOLVE() throws IOException
    {
        if(n.equals(m)) sb.append(1);
        else sb.append(0);
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException
    {
        INPUT();
        SOLVE();
    }
}