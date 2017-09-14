import java.util.*;
import java.util.Scanner;
import java.math.BigInteger;

public class Main{
    
    public static void main(String [] arguments){
        Scanner cin = new Scanner(System.in);
        int T=cin.nextInt();
        for(int i=1;i<=T;i++){
            BigInteger ans = BigInteger.ZERO;
            BigInteger x = cin.nextBigInteger();
            BigInteger Zero = BigInteger.ZERO;
            while(!x.equals(Zero)){
                ans = ans.add(x);
                x = cin.nextBigInteger();
            }
            System.out.println(ans);
            if(i<T) System.out.println();
        }
    }
}