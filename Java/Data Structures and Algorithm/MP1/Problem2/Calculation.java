import java.util.LinkedList;

/**
 *
 * @author Mark
 */
public class Calculation {
    
    LinkedList<Integer> marked = new LinkedList<Integer>();
    
    //This will marked the multiples
    //by adding the marked number into the linked list
    //we used dynamic data structure
    //because the input of the user is dynamic
    void multiples(int n,int multipleOf){
    
        for(int i = multipleOf + 1; i<n;i++){
            if(i % multipleOf == 0){
               
                if(!marked.contains(i)){
                     marked.add(i);
                }
            }
        }
    }

}
