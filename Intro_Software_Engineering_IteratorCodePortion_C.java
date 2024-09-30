package iteratorCodePortion;
import java.util.*;

class C {
	
	
	
	public static void main(String[] args) {
	Set<String> s = new HashSet<String>(); //creating a hashset
	for (String a : args) //looping through any args entered at commaandline
	if (!s.add(a)) //if there aren't any or they are duplicate then:
	System.out.println("here: " + a);
	System.out.println(s.size() + " there: " + s); //since no args are used 
	}
	

}
