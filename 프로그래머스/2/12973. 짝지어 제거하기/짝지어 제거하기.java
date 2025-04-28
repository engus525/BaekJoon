import java.util.*;

class Solution
{
    
    Stack<Character> st = new Stack<>();
    
    public int solution(String s)
    {
        
        for (int i = 0; i < s.length(); i++)
        {
            Character c = s.charAt(i);
            if (st.isEmpty()) st.push(c);
            else if (st.peek() == c) st.pop();
            else st.push(c);
        }

        return (st.isEmpty() ? 1 : 0);
    }
}