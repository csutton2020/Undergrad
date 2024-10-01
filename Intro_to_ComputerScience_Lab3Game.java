package pokerBase;

import java.util.UUID;

import java.util.ArrayList;

public class Game {
	
	private UUID GameID;
	private UUID TableID;
	private ArrayList<Player> players = new ArrayList<Player>();
	
	public Game()
	{
		GameID = UUID.randomUUID();
	}
	
	public Game AddPlayerToGame(Player p)
	{
		players.add(p);
		return this;
	}

	public UUID getGameID() {
		return GameID;
	}

	public void setGameID(UUID gameID) {
		GameID = gameID;
	}

	public UUID getTableID() {
		return TableID;
	}

	public void setTableID(UUID tableID) {
		TableID = tableID;
	}

	public ArrayList<Player> getPlayers() {
		return players;
	}

	public void setPlayers(ArrayList<Player> players) {
		this.players = players;
	}	
	
	
	

}
