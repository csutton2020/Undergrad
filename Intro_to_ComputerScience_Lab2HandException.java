package pokerBase;
import java.io.*;
import java.util.ArrayList;
public class HandException extends Exception {
	ArrayList<Card> shortHand = new ArrayList<Card>();
	
	public HandException(Hand h ){
			this.shortHand = h.getCardsInHand();
		}

	public ArrayList<Card> getExCards(){
		return shortHand;
	}
}
