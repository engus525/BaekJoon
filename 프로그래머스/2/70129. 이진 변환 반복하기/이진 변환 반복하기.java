class Solution {
    public int[] solution(String s) {
        
        int cnt = 0;
        int zero = 0;
        int len = s.length();
        while (!s.equals("1")) {
            // System.out.println(s);
            
            cnt++;
            s = s.replace("0", "");
            // System.out.println(len + " : len");
            // System.out.println(s.length() + " : s.length()");
            // System.out.println(len - s.length() + "개의 0 제거");
            
            zero += len - s.length();
            
            s = Integer.toString(s.length(), 2);
            len = s.length();
        }
        
        int[] answer = {cnt, zero};
        return answer;
    }
}