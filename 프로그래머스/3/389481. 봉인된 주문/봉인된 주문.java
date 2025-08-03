import java.util.*;
import java.io.*;

class Solution {
    public String solution(long n, String[] b) {
        List<Long> bans = new ArrayList<>();
        for (String ban : b) bans.add(convert(ban));
        Collections.sort(bans);

        long target = n;
        for (long base : bans) {
            if (target >= base) {
                target++;
            } else {
                break;
            }
        }

        return convert(target);
    }

    private String convert(long num) {
        StringBuilder result = new StringBuilder();
        long number = num;

        while (number > 0) {
            number--;
            char c = (char) ('a' + (int) (number % 26));
            result.append(c);
            number /= 26;
        }

        return result.reverse().toString();
    }

    private long convert(String input) {
        long result = 0L;
        for (char c : input.toCharArray()) {
            int value = c - 'a' + 1;
            result = result * 26 + value;
        }
        return result;
    }
}
