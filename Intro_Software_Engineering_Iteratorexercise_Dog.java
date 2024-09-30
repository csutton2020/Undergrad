import java.util.*;
public class Dog {
	String name;

	public Dog(String name){
		this.name = name;
	}
	
	public String toString(){
		return this.name;
	}

	public static void main(String[] args){
		Collection<Dog> collectionOfDog = new ArrayList<Dog>();
		Dog[] arrayOfDog = new Dog[3];
		
		collectionOfDog.add( new Dog("Fido") );
		collectionOfDog.add( new Dog("Spot") );
		collectionOfDog.add( new Dog("Lucy") );
		
		arrayOfDog[0] = new Dog("Fido");
		arrayOfDog[1] = new Dog("Spot");
		arrayOfDog[2] = new Dog("Lucy");
		
		
		//printing of dogs in collection
		System.out.println( collectionOfDog);
		System.out.println();
		
		// iterating over a plain array via Arrays
		System.out.println(Arrays.asList(arrayOfDog));
		System.out.println();
		
		
		// for-each printing of dogs w toString called directly
		System.out.println("for-each print if=spot");
		for(Dog a : collectionOfDog){
			if(a.toString() == "Spot"){
			System.out.println(a);
			}
		}
		System.out.println();
		
		
		
		//add to collection
		//concurrentModification
		/*
		for(Iterator<Dog> dogIter = collectionOfDog.iterator(); dogIter.hasNext();){
			if(dogIter.next().toString() == "Spot"){
				arrOfDog.add(new Dog("Khloe"));
			}
		}
		*/
		
		// no method to add to iterator
		/*
		for(Iterator<Dog> dogIter = collectionOfDog.iterator(); dogIter.hasNext();){
			if(dogIter.next().toString() == "Spot"){
				dogIter.
			}
		}
		*/
		
		/*
		//no add to iterator, only via via listIterator
		for(Iterator<Dog> dogIter = collectionOfDog.iterator(); dogIter.hasNext();){
			if(dogIter.next().toString() == "Spot"){
				dogIter.add(new Dog("Khloe"));
			}
		}
		*/
		
		
		//remove from collection
		//concurrentmodexception
		/*
		for(Iterator<Dog> dogIter = arrOfDog.iterator(); dogIter.hasNext();){
			if(dogIter.next().toString() == "Spot"){
				arrOfDog.remove(dogIter.next());
			}
		}
		*/
		
		//remove from iterator
		// works fine
		/*
		for(Iterator<Dog> dogIter = collectionOfDog.iterator(); dogIter.hasNext();){
			if(dogIter.next().toString() == "Spot"){
				dogIter.remove();
			}
		}
		*/		
		System.out.println("test of polymorph");
		for(Dog a : collectionOfDog){
			System.out.println(a);
		}
				
		
		
		
	         
		
		
		
	}
}
