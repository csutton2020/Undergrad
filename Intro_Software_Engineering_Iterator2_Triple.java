
import java.util.Iterator;

public class Triple {
	
	public int[] arr = {1, 2, 3};
	
		
	public Triple(){
		
	}
	 
	Iterator iterator(){
		return new Iter();
	}
	
	private class Iter implements Iterator{
		int index = 0;
		
		@Override
		public boolean hasNext() {
			return true;
		}

		@Override
		public Object next() {
			return arr[index++ % 3] ;
		}
	}
	
	public static void main(String[] args){
		
		Triple t = new Triple();
		Iterator ti = t.iterator();
		for(int i = 0; i < 10; i++)
			if (ti.hasNext())
				System.out.print(ti.next() + " ");
		System.out.println();
	}
	
}
