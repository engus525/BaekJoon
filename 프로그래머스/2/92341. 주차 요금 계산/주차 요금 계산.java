import java.io.*;
import java.util.*;

class Solution {
    
    Map<String, Integer> timeMap = new HashMap<>();
    Map<String, Integer> inoutMap = new HashMap<>();
    
    public int calc(String time) {
        StringTokenizer st = new StringTokenizer(time, ":");
        int h = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        return h * 60 + m;
    }
    
    public int[] solution(int[] fees, String[] records) {
        
        for (String record : records) {
            StringTokenizer st = new StringTokenizer(record);
            st.nextToken();
            String car = st.nextToken();
            timeMap.put(car, 0);
        }
        
        for (String record : records) {
            StringTokenizer st = new StringTokenizer(record);
            int time = calc(st.nextToken());
            String car = st.nextToken();
            String inout = st.nextToken();
            
            if (inout.equals("IN")) {
                inoutMap.put(car, time);
            }
            else {
                int plus = time - inoutMap.get(car);
                inoutMap.remove(car);
                timeMap.put(car, timeMap.get(car) + plus);
            }
        }
        
        for (Map.Entry<String, Integer> entry : inoutMap.entrySet()) {
            int plus = calc("23:59") - inoutMap.get(entry.getKey());
            timeMap.put(entry.getKey(), timeMap.get(entry.getKey()) + plus);
        }
        
        List<String> carList = new ArrayList<>(timeMap.keySet());
        Collections.sort(carList);
        
        int baseTime = fees[0];
        int baseMoney = fees[1];
        int perTime = fees[2];
        int perMoney = fees[3];
        
        List<Integer> ans = new ArrayList<>();
        for (String car : carList) {
            int time = timeMap.get(car);
            int money = baseMoney;
            if (time > baseTime) {
                time -= baseTime;
                int more = (time % perTime > 0) ? time / perTime + 1 : time / perTime;
                money += more * perMoney;
            }
            
            ans.add(money);
        }
        
        
        return ans.stream().mapToInt(i -> i).toArray();
    }
}