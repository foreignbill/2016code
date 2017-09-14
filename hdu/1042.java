import java.math.BigInteger;
import java.util.Scanner;
import java.util.*;
import java.io.*;

public class Main{
    public static void main(String [] arguments){
        Scanner S = new Scanner(System.in);
        while(S.hasNextInt()){
            int N=S.nextInt();
            BigInteger ans=BigInteger.ONE;
            for(int i=1;i<=N;i++){
                ans = ans.multiply(BigInteger.valueOf(i));
            }
            System.out.println(ans);
        }
    }
}