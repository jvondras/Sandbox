import java.sql.*;
/**
 * @author Jacob Vondrasek
 * @version 0.0.0.1
 * @since 0.0.0.1
 */
public class Database_Manager {
    

   public void connect_database()
 {   
    Connection main = null;
    
    try
    {
        Class.forName("org.sqlite.JDBC");
         main = DriverManager.getConnection("jdbc:sqlite:homework.db");
    }
    catch(Exception fault)
    {
        System.err.println( fault.getClass().getName() + ": " + fault.getMessage() );
        System.exit(1);
    }
}

    
}
