import java.util.ArrayList;
import java.util.Collection;

public class target {
	
	
	
	public static void main(String[] arugula){
		Collection<Animal> animalList = new ArrayList<Animal>();
		animalList.add(new Dog());
		animalList.add(new Cow());
		animalList.add(new Fish());
		for(Animal a : animalList){
			System.out.println(a.getNoise());
		}
		for(Animal a : animalList){
			System.out.println(a.move());
		}
		/*
		Animal a = null;
		switch (1 + (int)(Math.floor(Math.random() * 3))){
		case 1: a = new Cow(); break;
		case 2: a = new Dog(); break;
		case 3: a = new Fish(); break;
		}
		if (a instanceof Dog)
		System.out.println( ((Dog)a).getNoise() );
		else if (a instanceof Cow)
		System.out.println( ((Cow)a).getNoise() );
		else if (a instanceof Fish)
		System.out.println( ((Fish)a).getNoise() );
		return;
		

		*/
	}
}
