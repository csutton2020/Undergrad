package midterm;

import java.util.Iterator;

public class MyStepper implements Iterator<Integer>{
	
	int state = 0;
	int step;
	
	MyStepper(int a1){
		step = a1;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
			for (Iterator<Integer> sIter = new MyStepper(5); sIter.hasNext();){
			System.out.print(" " + sIter.next());
			}
			System.out.println();
			for (Iterator<Integer> sIter = new MyStepper(3); sIter.hasNext();){
			System.out.print(" " + sIter.next());
			}
			System.out.println();
	}

	@Override
	public boolean hasNext() {
		
		if(step == 5 ){
				if(step * state <50){
					return true;
				}else{
					return false;
				}
		}else {
				if(step * state <51){
					return true;
				}else{
					return false;
				}
		}
	
}

	@Override
	public Integer next() {
		state++	;	
		return step * state;
	}

}
