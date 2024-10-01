package pokerBase;

import java.util.ArrayList;
import java.util.Collections;

import pokerEnums.eRank;
import pokerEnums.eSuit;

public class Deck {

	private ArrayList<Card> deckCards = new ArrayList<Card>();

	public Deck() {
		int iCardNbr = 1;
		for (eSuit eSuit : eSuit.values()) {
			for (eRank eRank : eRank.values()) {
				
				if ( (eSuit != pokerEnums.eSuit.JOKER) && (eRank != pokerEnums.eRank.JOKER) )
				{
					deckCards.add(new Card(eSuit, eRank, iCardNbr++));
				}
			}
			 
		}
		Collections.shuffle(deckCards);
	}
	
	public Deck(int NbrOfJokers) {
		this();
		for(int i = 0; i< NbrOfJokers; i++){
			deckCards.add( new Card(eSuit.JOKER, eRank.JOKER,99) );
			
		}Collections.shuffle(deckCards);
	}
	
	
	public Deck(int NbrOfJokers, ArrayList<Card> Wilds) {

		this(NbrOfJokers);
		for(Card c : deckCards){
			for(Card w : Wilds){
				if( (c.geteRank() == w.geteRank()) && (c.geteSuit() == w.geteSuit()) ){
					c.setbWild(true);
				}
					
			}
		} Collections.shuffle(deckCards);
	}
	 
		
	
	public Card Draw(){
		//TODO Lab 3 - Implement exception handling for overdraw
		return deckCards.remove(0);
	}
	
	public ArrayList<Card> getDeck(){
		return deckCards;
	
	}
}
