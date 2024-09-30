// James Galante, Chris Sutton, Scott Miller

import static org.junit.Assert.*;


import java.util.ArrayList;

import org.junit.Test;

public class BoardTest {
	Board b1 = new Board(1);
	int x;
	String s2 = b1.player.toString();


	@Test
	public void SpawnTest(){
		b1.spawnRock();
		String s3 = b1.Rocks.get(0).toString();
		assertTrue(s3.equals( Board.screen[0].substring( b1.Rocks.get(0).getX(), b1.Rocks.get(0).getX() + 1 ) ) );
	}

	@Test
	public void testTimer(){
		b1.setTimer(2);
		assertEquals(2,b1.timer);
	}

	@Test
	public void moveRocksTest1() {
		b1.spawnRock();
		b1.spawnRock();
		b1.moveRocks();
		assertEquals(b1.Rocks.get(0).getY(),1);
	}

	@Test
	public void moveRocksTest2() {
		b1.spawnRock();
		b1.spawnRock();
		b1.Rocks.get(1).setxCoord(11);
		b1.Rocks.get(0).setyCoord(b1.height-1);
		b1.Rocks.get(1).setyCoord(b1.height-1);
		b1.player.setXcoord(11);
		b1.moveRocks();
		assertEquals(b1.Rocks.size(),1);
	}

	@Test
	public void removeRocksTest(){
		b1.spawnRock();
		b1.spawnRock();
		b1.removeRock(1);
		assertEquals(1, b1.Rocks.size());
	}

	@Test
	public void moveLeftTest1() {	
		x = b1.player.getX();		
		b1.moveLeft();
		assertEquals(x -1, b1.player.getX());
		assertTrue(s2.equals( Board.screen[b1.height - 1].substring( b1.player.getX(), b1.player.getX()+1 ) ) );
	}
	@Test
	public void moveLeftTest2() {
		b1.player.setXcoord( b1.width );
		x = b1.width ;
		b1.moveLeft();
		assertEquals(x -1, b1.player.getX());
		assertTrue(s2.equals( Board.screen[b1.height - 1].substring( b1.width -2, b1.width -1 ) ) );
	}
	@Test
	public void moveRightTest1() {	
		x = b1.player.getX();		
		b1.moveRight();
		assertEquals(x +1, b1.player.getX());
		assertTrue(s2.equals( Board.screen[b1.height - 1].substring( b1.player.getX(), b1.player.getX()+1 ) ) );
	}
	@Test
	public void moveRightTest2() {	
		b1.player.setXcoord( -1 );
		x = b1.player.getX();		
		b1.moveRight();
		assertEquals(x +1, b1.player.getX());
		assertTrue(s2.equals( Board.screen[b1.height - 1].substring(1,2 ) ) );
	}

	@Test
	public void processCharTest1(){
		Player p = new Player(10,10);
		p.score = 2;
		b1.player = p;

		b1.processChar(107);  //ascii value for 'k'; upScore
		assertEquals(p.score,3);
	}

	@Test
	public void processCharTest2(){
		Player p = new Player(10,10);
		b1.player = p;

		b1.processChar(111);  //ascii value for 'o'; moveLeft
		b1.player.setXcoord(b1.width-2);
		assertTrue(true);
	}


	@Test	
	public void playerGetYTest1() {
		Player test = new Player(10, 10);
		test.setYcoord(23);
		assertEquals(test.getY(),23);
	}
	
	@Test
	public void playerGetScoreTest1(){
		Player test = new Player(10, 10);
		test.score = 2;
		assertEquals(test.getScore(),2);
	}


	

}


