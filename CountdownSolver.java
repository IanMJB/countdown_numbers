import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class CountdownSolver {

	public int target;
	public List<Integer> numbers;
	public List<String> operators;
	public List<String> solution;
	public List<Integer> numbersCopy;

	public CountdownSolver(int target, List<Integer> numbers) {
		this.target	= target;
		this.numbers	= numbers;
		this.numbersCopy = new ArrayList<Integer>(numbers);

		operators = new ArrayList<String>();
		operators.add("+");
		operators.add("-");
		operators.add("*");
		operators.add("/");
	}

	public List<String> solve() {
		while( true ) {
		numbersCopy = new ArrayList<Integer>(numbers);

		int i = 0;	
		while(!Arrays.asList(numbersCopy).contains(target) && i < 1000 && numbersCopy.size() >= 2) {	
			int numIndex1 = rng(0, numbersCopy.size() - 1);
			int num1 = numbersCopy.remove(numIndex1);
			int numIndex2 = rng(0, numbersCopy.size() - 1);
			int num2 = numbersCopy.remove(numIndex2);
			int opIndex = rng(0, 3);
			String op = operators.get(opIndex);

			int resultNum;
			if(op.equals("+")) {
				resultNum = num1 + num2;
				if(resultNum < 1000) {
					numbersCopy.add(resultNum);
				} else {
					numbersCopy.add(num1);
					numbersCopy.add(num2);
				}
			}
			else if(op.equals("-")) {
				resultNum = num1 - num2;
				if(resultNum < 1000) {
					numbersCopy.add(resultNum);
				} else {
					numbersCopy.add(num1);
					numbersCopy.add(num2);
				}
			}
			else if(op.equals("*")) {
				resultNum = num1 * num2;
				if(resultNum < 1000) {
					numbersCopy.add(resultNum);
				} else {
					numbersCopy.add(num1);
					numbersCopy.add(num2);
				}
			}
			else if(op.equals("/")) {
				float resultFloat = (float) num1 / (float) num2;
				resultNum = num1 / num2;
				if((resultNum == resultFloat) && (resultNum < 1000)) {
					numbersCopy.add(resultNum);
				} else {
					numbersCopy.add(num1);
					numbersCopy.add(num2);
				}
			}
			i++;
			if(Arrays.asList(numbersCopy).contains(target)) {
				System.out.println("SOLUTION");
			}
		}

		if(Arrays.asList(numbersCopy).contains(target)) {
			System.out.println("Answer found.");
			return solution;
		}
		}
	}

	public int rng(int min, int max) {
		return (min + (int)(Math.random() * ((max - min))));
	}
}
