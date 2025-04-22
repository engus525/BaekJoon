class Solution {
    public int solution(int[] a) {
        int ans = 0;
        
        boolean[] l = new boolean[a.length + 1];
        boolean[] r = new boolean[a.length + 1];
        int minL = a[0];
        int minR = a[a.length - 1];
        for (int i = 1; i < a.length; i++)
        {
            if (a[i] > minL)
            {
                l[i] = true;
            }
            else
            {
                minL = a[i];
            }
            
            if (a[a.length - 1 - i] > minR)
            {
                r[a.length - 1 - i] = true;
            }
            else
            {
                minR = a[a.length - 1 - i];
            }
        }
        
        for (int i = 0; i < a.length; i++)
        {
            if (!l[i] || !r[i])
            {
                // System.out.print(a[i] + " ");
                ans++;
            }
        }
        // System.out.println();
        // for (int i = 0; i < a.length; i++)
        // {
        //     System.out.print(l[i] + " ");
        // }
        // System.out.println();
        // for (int i = 0; i < a.length; i++)
        // {
        //     System.out.print(r[i] + " ");
        // }
        
        return ans;
    }
}