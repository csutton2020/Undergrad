package pokerBase;

import java.util.UUID;

import java.util.ArrayList;

public class Table {
	
	
	private UUID TableID;
	private ArrayList<Player> players = new ArrayList<Player>();
	
	public Table()
	{
		TableID = UUID.randomUUID();
	}
	
	
	
	public UUID getTableID() {
		return TableID;
	}



	public void setTableID(UUID tableID) {
		TableID = tableID;
	}



	public Table AddPlayerToTable(Player p)
	{
		players.add(p);
		return this;
	}



	public ArrayList<Player> getPlayers() {
		return players;
	}



	public void setPlayers(ArrayList<Player> players) {
		this.players = players;
	}	

}
