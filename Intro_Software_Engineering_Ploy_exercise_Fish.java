
public class Fish extends Animal {
	String Sound = "SQUEAK! SQUEAK!";
	String movement = "Swim";
	
	public String getNoise(){
		return Sound;
		
	}


	@Override
	public String move() {
		
		return movement;
	}


}
