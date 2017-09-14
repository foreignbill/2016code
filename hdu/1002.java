import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String [] arguments){
        Scanner in=new Scanner(System.in);
        int T;
        T=in.nextInt();
        for(int i=1;i<=T;++i){
            if(i>1) System.out.println();
            System.out.println("Case "+i+":");
            BigInteger a,b;
            a=in.nextBigInteger();
            b=in.nextBigInteger();
            System.out.println(a + " + " + b + " = " + a.add(b));
        }
    }
}