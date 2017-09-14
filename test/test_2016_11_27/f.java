import java.util.Scanner;
import java.math.BigInteger;

public class Main{
	
	public static void main(String [ ] arguments){
		Scanner cin = new Scanner(System.in);
		int n;
		int f[] = new int[41];
		f[1]=1;
		f[2]=1;
		for(int i=3;i<=40;i++)
			f[i]=f[i-1]+f[i-2];
		int T;
		T = cin.nextInt();
		for(int cnt=1;cnt<=T;cnt++){
			n = cin.nextInt();
			System.out.println(f[ n ]);
		}
		cin.close();
	}
}