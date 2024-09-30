import java.awt.image.BufferedImage;

public class Model {
	static int picNum = 0;
	static BufferedImage[] picsSE;
	static BufferedImage[] picsSW;
	static BufferedImage[] picsNE;
	static BufferedImage[] picsNW;
	static BufferedImage[] picsS;
	static BufferedImage[] picsN;
	static BufferedImage[] picsE;
	static BufferedImage[] picsW;
	static int xloc = 0;
	static int yloc = 0;
	static final int xIncr = 8;
	static final int yIncr = 2;
	public final static int frameWidth = 500;
	public final static int frameHeight = 300;
	public final static int imgWidth = 165;
	public final static int imgHeight = 165;
	public static boolean east = true;
	public static boolean north = false;


	public void update(){
		if(xloc >= frameWidth-140){
			east = false;}
		if(xloc <= -35){
			east = true;}
		if(yloc >= frameHeight-165){
			north = true;}
		if(yloc <= -30){
			north = false;}
	}

}
