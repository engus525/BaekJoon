import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.min;


public class Main
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int n;

    public static void INPUT() throws IOException
    {
        n= Integer.parseInt(br.readLine());
    }

    public static void SOLVE() throws IOException
    {
        System.out.println(n*(n-1));
    }

    public static void main(String[] args) throws IOException
    {
        INPUT();
        SOLVE();
    }
}