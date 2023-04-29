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

    }

    public static void SOLVE()
    {
        sb.append("#  # #### #### #  #")
                .append('\n')
                .append("#### #  # #  # # #")
                .append('\n')
                .append("#### #  # #  # # #")
                .append('\n')
                .append("#  # #### #### #  #");
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException
    {
        INPUT();
        SOLVE();
    }
}