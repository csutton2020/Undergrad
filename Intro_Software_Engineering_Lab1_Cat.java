package labO;

import java.util.ArrayList;
import java.util.Random;

public class Cat {
	int numOfLegs;
	int weight;
	String name;
	
	Cat(int nL, int w, String n){
		numOfLegs = nL;
		weight = w;
		name = n;
	}
	
	Cat(int w, String n){
		weight = w;
		name = n;
	}
	
	Cat(String n, int l){
		name = n;
		numOfLegs = l;
	}
	@Override
	public String toString(){
		return name + " "+  String.valueOf(weight) + " "
	+ String.valueOf(numOfLegs);
	}
	
	//problem 6
	static int w = 12;
	static int[] urray = new int[w];
	//problem six end	

	public static void main(String[] args) {
		//problem 4
		ArrayList<Cat> arr = new ArrayList<Cat>(3);
		arr.add(new Cat(1, 1, "Rex"));
		arr.add(new Cat(2,2, "Gus"));
		arr.add(new Cat(3,3,"paws"));
		
		System.out.println(arr.toString());
		System.out.println(arr); 
		//end of problem 4
		
		//problem 5
		Random r = new Random();
		int[] array = new int[3];
		int m=0, j=0, k=0;
		for(int i=0;i<1000000;i++){
			
			if(r.nextInt() % 3 == 1){
				array[0] =m++;
			}else if(r.nextInt() % 3 == 2){
				array[1] = j++;
			}else{
				array[2]= k++;
			}
		}
		System.out.println(array[0] +" "+ array[1]+ " " +array[2]);
		// end of problem 5
		
		//problem 6
		
		for(int i=0;i<w;i++){
			urray[i] = 0;
		}
		for(int i =0; i<w; i++){
			if(i % 4 == 0){
				System.out.print('\n');
			
		}else{
			System.out.print(urray[i]);
		}

		
		
		
	}//problem 6 end
		
	}
}
