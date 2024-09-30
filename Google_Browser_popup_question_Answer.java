package google;
import java.util.HashMap;

public class Answer {
	
	public static int[] answer(int[] data, int n) { 
		int[] a1;
		int[] a3;
		if(n == 0 ){
			a1 = new int[0];
			return a1;
		}else{
			HashMap<Integer,Integer> hm=new HashMap<Integer,Integer>(50);  
			for(int element: data){
				if( hm.containsKey(element) ){
					hm.put(element, hm.get(element).intValue() +1) ;
					//System.out.println(hm);
				}else{
					hm.put(element, 1);
				}
			}
			int j = 0;
			for(Integer i : hm.values() ){
				if( i <= n){
					j = j + i;
				}
			}
			a3 = new int[j];
			int i = 0;
			for(int returnedElements: data){
				if( hm.get(returnedElements).intValue() <= n ){
					a3[i] = returnedElements;
					++i;
				}else{
				}
			}
			return a3;
		}
	}
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[] testInt = new int[6];
		testInt[0] = 1;
		testInt[1] = 1;
		testInt[2] = 2;
		testInt[3] = 3;
		testInt[4] = 3;
		testInt[5]=7;
		int[] ans = answer(testInt, 1);
		for(int i : ans){
			System.out.println(i);
		}
	}

}
