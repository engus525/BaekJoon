class Solution {
    
    String word;
    int ans = 0;
    int order = 0;
    String[] aeiou = {"A","E","I","O","U"};
    
    public void dfs(StringBuilder now)
    {
        if (now.toString().equals(word))
        {
            ans = order;
            return;
        }
        if (now.length() == 5) return;
        
        for (int i = 0; i < 5; i++)
        {
            now.append(aeiou[i]);
            order++;
            dfs(now);
            now.deleteCharAt(now.length() - 1);
        }
    }
    
    public int solution(String w) {
        word = w;
        int answer = 0;
        
        dfs(new StringBuilder(""));
        
        
        return ans;
    }
}