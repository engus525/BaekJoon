import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int n;

    public static void INPUT() throws IOException
    {
        n = Integer.parseInt(br.readLine());
    }

    public static void SOLVE() throws IOException
    {
        sb.append(n - (n*22/100)).append(" ")
                .append((int)(n*0.8+(n*0.2-(n*0.2)*22/100)));
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException
    {
        INPUT();
        SOLVE();
    }
}