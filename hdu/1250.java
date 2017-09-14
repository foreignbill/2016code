import java.util.Scanner;
import java.math.BigInteger;

public class Main{
    
    public static void main(String [] arguements){
        Scanner cin = new Scanner(System.in);
        BigInteger[]f=new BigInteger[10086];
        f[0]=BigInteger.ONE;
        f[1]=BigInteger.ONE;
        f[2]=BigInteger.ONE;
        f[3]=BigInteger.ONE;
        for(int i=4;i<=10006;i++){
            f[i]=f[i-1].add(f[i-2]).add(f[i-3]).add(f[i-4]);
        }
        while(cin.hasNext()){
            int N = cin.nextInt();
            System.out.println(f[N-1]);
        }
    }
}