import static org.junit.Assert.*;
import org.junit.Test;

public class  functionTest {

	public class labTest{
		@Test
		public void testadd(){
			int answer = LabOne.function1(2, 2);
			assertEquals(4, answer);
			
		}
		@Test
		public void testConcat(){
			String answer = LabOne.function2("Cat", "Dog");
			assertEquals("CatDog", answer);
		}
	
}
	
	
}

