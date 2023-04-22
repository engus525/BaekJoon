import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class Main
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int ax,ay,az,cx,cy,cz;

    public static void INPUT() throws IOException
    {
        StringTokenizer st = new StringTokenizer(br.readLine());
        ax = Integer.parseInt(st.nextToken());
        ay = Integer.parseInt(st.nextToken());
        az = Integer.parseInt(st.nextToken());
        st = new StringTokenizer((br.readLine()));
        cx= Integer.parseInt(st.nextToken());
        cy = Integer.parseInt(st.nextToken());
        cz = Integer.parseInt(st.nextToken());
    }

    public static void SOLVE() throws IOException
    {
        sb.append(cx-az).append(" ")
                        .append(cy/ay).append(" ")
                        .append(cz-ax);
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException
    {
        INPUT();
        SOLVE();
    }
}