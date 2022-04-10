
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Mark
 */
public class JDBCmain {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try{
            Class.forName("org.apache.derby.jdbc.ClientDriver");
            Connection con = DriverManager.getConnection("jdbc:derby://localhost:1527/myStudents","mark","mark");
            Statement st = con.createStatement();
            st.executeUpdate("INSERT INTO students " + 
                    "VALUES('1','Mark Angelo Basas Capili', 'Computer Science', '09566779335', 20)"
                    );
            st.executeUpdate("INSERT INTO students " + 
                    "VALUES('2','Rhea May Capili Pinas', 'Civil Engineering', '09123412345', 30)"
                    );
            ResultSet rs = st.executeQuery("SELECT * FROM students");
            
            while(rs.next()){
                System.out.println("\nSTUDENT ID: " + rs.getInt(1));
                System.out.println("STUDENT NAME: " + rs.getString(2));
                System.out.println("COURSE: " + rs.getString(3));
                System.out.println("CONTACT NUMBER: " + rs.getString(4));
                System.out.println("AGE: " + rs.getInt(5));
                
            }
            
            
            
        } catch(ClassNotFoundException e){
            System.out.print(e);
        }catch(SQLException e2){
            System.out.print(e2);
        }
        
        
    }
    
}
