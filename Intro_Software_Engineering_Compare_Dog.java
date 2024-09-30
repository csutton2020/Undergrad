package compare;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class Dog extends Animal  {
	
	public Dog(String n, int legs){
		this.name = n;
		this.NumOfLegs = legs;
	}

	public String toString(){
		return "name :" + name+ " Number of Legs :" +NumOfLegs;
	}
	
	public static void main(String[] args){
		ArrayList<Animal> zoo = new ArrayList<Animal>();
		zoo.add(new Dog("Chris", 4) );
		zoo.add(new Dog("Chris", 3) );
		zoo.add(new Dog("Marybeth",2));
		System.out.println(zoo);
		Collections.sort(zoo, new AnimalCompare());
		System.out.println(zoo);
		Collections.sort(zoo);
		System.out.println(zoo);
	}

	@Override
	public int compareTo(Animal o) {
		// TODO Auto-generated method stub
		if(this.NumOfLegs == o.NumOfLegs){
			if(this.name.compareTo(o.name)  > 0){	
			
				return 1;
			}else if(this.name.compareTo(o.name) == 0){
				
				return 0;
			}else{
				return -1;
			}
		
		}else if(this.NumOfLegs > o.NumOfLegs){
			return 1;
		}else{
			return -1;
		}
		
	}

		
}
