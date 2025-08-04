
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int n, m;
	static List<Integer> list = new ArrayList<>();
	static boolean[] visited = new boolean[10];
	
	public static void comb(int depth) {
		if (depth == m) {
			for (int num : list) System.out.print(num + " ");
			System.out.println();
			return;
		}
		
		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;
			
			list.add(i);
			visited[i] = true;
			comb(depth + 1);
			list.remove(list.size() - 1);
			visited[i] = false;
		}
		
	}
	
	public static void main(String[] args) throws Exception {
		String input = br.readLine();
		n = input.charAt(0) - '0';
		m = input.charAt(2) - '0';
		
		comb(0);
		
	}
}
