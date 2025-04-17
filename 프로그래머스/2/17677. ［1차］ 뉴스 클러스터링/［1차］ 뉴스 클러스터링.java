import java.util.*;

class Solution {
    
    List<String> aList = new ArrayList<>();
    List<String> bList = new ArrayList<>();
    List<String> unionList = new ArrayList<>();
    List<String> interList = new ArrayList<>();
    
    
    public int solution(String str1, String str2) {
        int answer = 0;
        
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();
        if (str1.equals(str2)) return 65536;
        
        for (int i = 0; i < str1.length() - 1; i++)
        {
            String word = ("" + str1.charAt(i) + str1.charAt(i + 1));
            if (!('a' <= str1.charAt(i) && str1.charAt(i) <= 'z')) continue;
            if (!('a' <= str1.charAt(i + 1) && str1.charAt(i + 1) <= 'z')) continue;
            // System.out.print(word + " ");
            aList.add(word);
        }
        System.out.println();
        
        for (int i = 0; i < str2.length() - 1; i++)
        {
            String word = ("" + str2.charAt(i) + str2.charAt(i + 1));
            if (!('a' <= str2.charAt(i) && str2.charAt(i) <= 'z')) continue;
            if (!('a' <= str2.charAt(i + 1) && str2.charAt(i + 1) <= 'z')) continue;
            // System.out.print(word + " ");
            bList.add(word);
        }
        System.out.println();
        
        HashSet<String> visited = new HashSet<>();
        for (int i = 0; i < aList.size(); i++)
        {
            String word = aList.get(i);
            if (visited.contains(word)) continue;
            visited.add(word);
            
            int aCnt = 1;
            for (int j = i + 1; j < aList.size(); j++)
                if (aList.get(j).equals(word))
                    aCnt++;
            
            int bCnt = 0;
            for (int j = 0; j < bList.size(); j++)
            {
                if (bList.get(j).equals(word))
                    bCnt++;
            }
            
            for (int j = 0; j < Math.max(aCnt, bCnt); j++)
                    unionList.add(word);
            
            if (aCnt > 0 && bCnt > 0)
            {
                for (int j = 0; j < Math.min(aCnt, bCnt); j++)
                    interList.add(word);
            }
        }
        
        for (int i = 0; i < bList.size(); i++)
            if (!visited.contains(bList.get(i)))
                unionList.add(bList.get(i));
        
//         System.out.print("inter list : ");
//         for (String inter : interList)
//             System.out.print(inter + " ");
//         System.out.println();
        
//         System.out.print("union list : ");
//         for (String union : unionList)
//             System.out.print(union + " ");
//         System.out.println();
        
//         System.out.println(interList.size());
//         System.out.println(unionList.size());
        if (unionList.size() == 0) return 0;
        return (int) ((interList.size() / (double) unionList.size()) * 65536);
    }
}