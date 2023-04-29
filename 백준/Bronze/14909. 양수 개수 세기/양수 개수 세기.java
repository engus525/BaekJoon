import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;



public class Main
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static String str;

    public static void INPUT() throws IOException
    {
        st = new StringTokenizer(br.readLine());
    }

    public static void SOLVE()
    {
        int ans = 0;
        while(st.hasMoreTokens())
            if(Integer.parseInt(st.nextToken()) > 0)
                ans++;
        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException
    {
        INPUT();
        SOLVE();
    }
}