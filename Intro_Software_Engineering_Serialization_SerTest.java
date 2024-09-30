package serial;

import static org.junit.Assert.*;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.LinkedList;

import org.junit.Test;

public class SerTest {
	 @Test public void serializeToDisk()
	    {
	        try
	        {
	            Person ted = new Person("Ted", "Neward", 39);
	            Person Jeff = new Person("Jeff", "whatever", 38);
	            Person charl = new Person("Charlotte",
	                "Neward", 38);
	 
	            ted.setSpouse(charl); charl.setSpouse(ted);
	            Jeff.setSpouse(charl);  
	            LinkedList<Person> LL = new LinkedList<Person>();
	            LL.add(ted);
	            LL.add(Jeff);
	 
	            FileOutputStream fos = new FileOutputStream("tempdata.ser");
	            ObjectOutputStream oos = new ObjectOutputStream(fos);
	            oos.writeObject(LL);
	            oos.close();
	        }
	        catch (Exception ex)
	        {
	            fail("Exception thrown during test: " + ex.toString());
	        }
	         
	        try
	        {
	            FileInputStream fis = new FileInputStream("tempdata.ser");
	            ObjectInputStream ois = new ObjectInputStream(fis);
	            LinkedList<Person> Li = (LinkedList<Person>) ois.readObject();
	            ois.close();
	             
	            assertEquals(Li.getFirst().getFirstName(), "Ted");
	            assertEquals(Li.getFirst().getSpouse().getFirstName(), "Charlotte");
	            assertEquals(Li.getLast().getFirstName(), "Jeff");
	            assertEquals(Li.getLast().getSpouse().getFirstName(),"Charlotte" );
	 
	            // Clean up the file
	            new File("tempdata.ser").delete();
	        }
	        catch (Exception ex)
	        {
	            fail("Exception thrown during test: " + ex.toString());
	        }
	    }

}
