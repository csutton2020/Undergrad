package compare;

import java.util.Comparator;

public class AnimalCompare implements Comparator<Animal>{

	@Override
	public int compare(Animal a1, Animal a2) {
		if(a1.name.compareTo(a2.name) == 0){
			if(a1.NumOfLegs > a2.NumOfLegs)
				return 1;
			else if(a1.NumOfLegs == a2.NumOfLegs)
				return 0;
			else{
				return -1;
			}
		}
		else{
			return a1.name.compareTo(a2.name);
		}
	}
}
