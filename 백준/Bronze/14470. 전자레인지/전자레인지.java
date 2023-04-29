import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;



public class Main
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int a,b,c,d,e;

    public static void INPUT() throws IOException
    {
        a = Integer.parseInt(br.readLine());
        b = Integer.parseInt(br.readLine());
        c = Integer.parseInt(br.readLine());
        d = Integer.parseInt(br.readLine());
        e = Integer.parseInt(br.readLine());
    }

    public static void SOLVE()
    {
        int ans = 0;
        if(a < 0)
        {
            ans += c*(-a)+d;
            a = 0;
        }
        ans += e*(b-a);

        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException
    {
        INPUT();
        SOLVE();
    }
}