import java.util.*;

public class SortArray {

    static char rndChar () {
        int rnd = (int) (Math.random() * 52); // or use Random or whatever
        char base = (rnd < 26) ? 'A' : 'a';
        return (char) (base + rnd % 26);
    
    }
    public static void main(String[] args){
        String k ="";
        
        for(int i=0;i<5;i++ ){
            k += rndChar();
        }
        System.out.print(k);

    }


}



