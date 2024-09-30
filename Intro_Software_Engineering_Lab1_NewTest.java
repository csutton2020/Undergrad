package labO;

import static org.junit.Assert.*;

import org.junit.Test;

public class NewTest {
	@Test
	public void testMultiply() {
		int mult = Math.multiply(6, 2);
		assertEquals(12, mult);
	}
	@Test
	public void testMultiplyFail() {
		int mult = Math.multiply(6, 2);
		assertEquals(12, mult);
	}
	@Test
	public void testConcat() {
		String word = Math.concat("ja", "va");
		assertEquals("java", word);		
	}
	@Test
	public void testConcatFail() {
		String word = Math.concat("ja", "va");
		assertEquals("java", word);		
	}
	


}
