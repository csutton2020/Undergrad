import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JPanel;

public class View extends JPanel{
	
	final int frameCount = 10;
   
	
    @Override
    public void paint(Graphics g) {
    	Model.picNum = (Model.picNum + 1) % frameCount;
    	
    	
		if(Model.east){
			if(Model.north){
				g.drawImage(Model.picsNE[Model.picNum], Model.xloc+=Model.xIncr , Model.yloc-=Model.yIncr, Color.gray, this);}
			else{
				g.drawImage(Model.picsSE[Model.picNum], Model.xloc+=Model.xIncr , Model.yloc+=Model.yIncr, Color.gray, this);}}
		
		else{
			if(Model.north){
				g.drawImage(Model.picsNW[Model.picNum], Model.xloc-=Model.xIncr , Model.yloc-=Model.yIncr, Color.gray, this);}
			else{
				g.drawImage(Model.picsSW[Model.picNum], Model.xloc-=Model.xIncr , Model.yloc+=Model.yIncr, Color.gray, this);}
		}
    	// TODO: Keep the orc from walking off-screen, turn around when bouncing off walls. //Done
	//Be sure that animation picture direction matches what is happening on screen.  //Done
    }
    
    public View(Model m){
    	System.out.println("view");
    	BufferedImage img = createImage("src/orc_animation/orc_forward_southeast.png");
    	Model.picsSE = new BufferedImage[10];
    	for(int i = 0; i < frameCount; i++){
    		Model.picsSE[i] = img.getSubimage(Model.imgWidth*i, 0, Model.imgWidth, Model.imgHeight);
    	System.out.println(Model.picsSE[i]);
    	}
    	BufferedImage img2 = createImage("src/orc_animation/orc_forward_southwest.png");
    	Model.picsSW = new BufferedImage[10];
    	for(int i = 0; i < frameCount; i++)
    		Model.picsSW[i] = img2.getSubimage(Model.imgWidth*i, 0, Model.imgWidth, Model.imgHeight);
    	BufferedImage img3 = createImage("src/orc_animation/orc_forward_northeast.png");
    	Model.picsNE = new BufferedImage[10];
    	for(int i = 0; i < frameCount; i++)
    		Model.picsNE[i] = img3.getSubimage(Model.imgWidth*i, 0, Model.imgWidth, Model.imgHeight);
    	BufferedImage img4 = createImage("src/orc_animation/orc_forward_northwest.png");
    	Model.picsNW = new BufferedImage[10];
    	for(int i = 0; i < frameCount; i++)
    		Model.picsNW[i] = img4.getSubimage(Model.imgWidth*i, 0, Model.imgWidth, Model.imgHeight);
    	BufferedImage img5 = createImage("src/orc_animation/orc_forward_south.png");
    	Model.picsS = new BufferedImage[10];
    	for(int i = 0; i < frameCount; i++)
    		Model.picsS[i] = img5.getSubimage(Model.imgWidth*i, 0, Model.imgWidth, Model.imgHeight);
    	BufferedImage img6 = createImage("src/orc_animation/orc_forward_north.png");
    	Model.picsN = new BufferedImage[10];
    	for(int i = 0; i < frameCount; i++)
    		Model.picsN[i] = img6.getSubimage(Model.imgWidth*i, 0, Model.imgWidth, Model.imgHeight);
    	BufferedImage img7 = createImage("src/orc_animation/orc_forward_east.png");
    	Model.picsE = new BufferedImage[10];
    	for(int i = 0; i < frameCount; i++)
    		Model.picsE[i] = img7.getSubimage(Model.imgWidth*i, 0, Model.imgWidth, Model.imgHeight);
    	BufferedImage img8 = createImage("src/orc_animation/orc_forward_west.png");
    	Model.picsW = new BufferedImage[10];
    	for(int i = 0; i < frameCount; i++)
    		Model.picsW[i] = img8.getSubimage(Model.imgWidth*i, 0, Model.imgWidth, Model.imgHeight);
    }
    
    private BufferedImage createImage(String s){
    	System.out.println("createImage");
    	BufferedImage bufferedImage;
    	try {
    		bufferedImage = ImageIO.read(new File(s));
    		return bufferedImage;
    	} catch (IOException e) {
    		e.printStackTrace();
    	}
    	return null;
    }
    
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
