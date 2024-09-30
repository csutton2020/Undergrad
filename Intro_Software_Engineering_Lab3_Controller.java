import java.awt.Color;

import javax.swing.JFrame;

public class Controller {

	public static void main(String[] args) {
		Model test = new Model();
		JFrame frame = new JFrame();
    	frame.getContentPane().add(new View(test));
     	frame.setBackground(Color.gray);
    	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    	frame.setSize(Model.frameWidth, Model.frameHeight);
    	frame.setVisible(true);
    	for(int i = 0; i < 1000; i++){
    		System.out.println("loopcontroller"+i);
    		test.update();
    		frame.repaint();
    		try {
    			Thread.sleep(100);
    		} catch (InterruptedException e) {
    			e.printStackTrace();
    		}
    	}

	}

}
