//T Harvey
//based loosely on http://www.java2s.com/Code/JavaAPI/java.awt/GraphicsdrawImageImageimgintxintyImageObserverob.htm
 
//Sam Hughes and Chris Sutton

import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JPanel;

//Sam Hughes and Chris Sutton


public class Animation extends JPanel {

    final int frameCount = 10;
    int picNum = 0;
    BufferedImage[] picsSE;
    BufferedImage[] picsSW;
    BufferedImage[] picsNE;
    BufferedImage[] picsNW;
    BufferedImage[] picsS;
    BufferedImage[] picsN;
    BufferedImage[] picsE;
    BufferedImage[] picsW;
    static int xloc = 0;
    static int yloc = 0;
    final int xIncr = 8;
    final int yIncr = 2;
    final static int frameWidth = 500;
    final static int frameHeight = 300;
    final static int imgWidth = 165;
    final static int imgHeight = 165;
    boolean east = true;
    boolean north = false;

    //Override this JPanel's paint method to cycle through picture array and draw images
    public void paint(Graphics g) {
    	picNum = (picNum + 1) % frameCount;
    	
		if(xloc >= frameWidth-imgWidth){
			east = false;}
		if(xloc <= 0){
			east = true;}
		if(yloc >= frameHeight-imgHeight){
			north = true;}
		if(yloc <= 0){
			north = false;}
		
		if(east){
			if(north){
				g.drawImage(picsNE[picNum], xloc+=xIncr , yloc-=yIncr, Color.gray, this);}
			else{
				g.drawImage(picsSE[picNum], xloc+=xIncr , yloc+=yIncr, Color.gray, this);}}
		
		else{
			if(north){
				g.drawImage(picsNW[picNum], xloc-=xIncr , yloc-=yIncr, Color.gray, this);}
			else{
				g.drawImage(picsSW[picNum], xloc-=xIncr , yloc+=yIncr, Color.gray, this);}
		}
    	// TODO: Keep the orc from walking off-screen, turn around when bouncing off walls. //Done
	//Be sure that animation picture direction matches what is happening on screen.  //Done
    }

    //Make frame, loop on repaint and wait
    public static void main(String[] args) {
    	JFrame frame = new JFrame();
    	System.out.println("getcontent");
    	frame.getContentPane().add(new Animation());
    	frame.setBackground(Color.gray);
    	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    	frame.setSize(frameWidth, frameHeight);
    	frame.setVisible(true);
    	System.out.println("startForLoop");
    	for(int i = 0; i < 1000; i++){
    		System.out.println("loop");
    		frame.repaint();
    		try {
    			Thread.sleep(100);
    		} catch (InterruptedException e) {
    			e.printStackTrace();
    		}
    	}
    }

    //Constructor: get image, segment and store in array
    public Animation(){
    	System.out.println("animation");
    	BufferedImage img = createImage("src/orc_animation/orc_forward_southeast.png");
    	picsSE = new BufferedImage[10];
    	for(int i = 0; i < frameCount; i++)
    		picsSE[i] = img.getSubimage(imgWidth*i, 0, imgWidth, imgHeight);
    	BufferedImage img2 = createImage("src/orc_animation/orc_forward_southwest.png");
    	picsSW = new BufferedImage[10];
    	for(int i = 0; i < frameCount; i++)
    		picsSW[i] = img2.getSubimage(imgWidth*i, 0, imgWidth, imgHeight);
    	BufferedImage img3 = createImage("src/orc_animation/orc_forward_northeast.png");
    	picsNE = new BufferedImage[10];
    	for(int i = 0; i < frameCount; i++)
    		picsNE[i] = img3.getSubimage(imgWidth*i, 0, imgWidth, imgHeight);
    	BufferedImage img4 = createImage("src/orc_animation/orc_forward_northwest.png");
    	picsNW = new BufferedImage[10];
    	for(int i = 0; i < frameCount; i++)
    		picsNW[i] = img4.getSubimage(imgWidth*i, 0, imgWidth, imgHeight);
    	BufferedImage img5 = createImage("src/orc_animation/orc_forward_south.png");
    	picsS = new BufferedImage[10];
    	for(int i = 0; i < frameCount; i++)
    		picsS[i] = img5.getSubimage(imgWidth*i, 0, imgWidth, imgHeight);
    	BufferedImage img6 = createImage("src/orc_animation/orc_forward_north.png");
    	picsN = new BufferedImage[10];
    	for(int i = 0; i < frameCount; i++)
    		picsN[i] = img6.getSubimage(imgWidth*i, 0, imgWidth, imgHeight);
    	BufferedImage img7 = createImage("src/orc_animation/orc_forward_east.png");
    	picsE = new BufferedImage[10];
    	for(int i = 0; i < frameCount; i++)
    		picsE[i] = img7.getSubimage(imgWidth*i, 0, imgWidth, imgHeight);
    	BufferedImage img8 = createImage("src/orc_animation/orc_forward_west.png");
    	picsW = new BufferedImage[10];
    	for(int i = 0; i < frameCount; i++)
    		picsW[i] = img8.getSubimage(imgWidth*i, 0, imgWidth, imgHeight);
    	// TODO: Change this constructor so that at least eight orc animation pngs are loaded //Done
    }

    //Read image from file and return
    private BufferedImage createImage(String s){
    	System.out.println("creatimage");
    	BufferedImage bufferedImage;
    	try {
    		bufferedImage = ImageIO.read(new File(s));
    		return bufferedImage;
    	} catch (IOException e) {
    		e.printStackTrace();
    	}
    	return null;
    	// TODO: Change this method so you can load other orc animation bitmaps //Done
    }
}
