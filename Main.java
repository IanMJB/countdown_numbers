import java.util.List;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {

		int target		= Integer.parseInt(args[0]);
		List<Integer> numbers	= new ArrayList<Integer>();
		for(int i = 0; i < 6; i++) {
			numbers.add(Integer.parseInt(args[i+1]));
		}

		CountdownSolver solver	= new CountdownSolver(target, numbers);
		solver.solve();
	}
}
