//BaekJoon
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int one = input.nextInt();
		int cnt[] = new int[one + 1];
		cnt[0] = 0; cnt[1] = 0;
		
		for(int i = 2; i <= one; i++) {
			cnt[i] = cnt[i - 1] + 1;
			if(i % 2 == 0)
				cnt[i] = Math.min(cnt[i], cnt[i / 2] + 1);
			if(i % 3 == 0)
				cnt[i] = Math.min(cnt[i], cnt[i / 3] + 1);
		}
		System.out.println(cnt[one]);
		input.close();
		
		
	}
	
}
