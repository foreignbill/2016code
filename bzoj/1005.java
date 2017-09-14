/**************************************************************
    Problem: 1005
    User: foreignbill
    Language: Java
    Result: Accepted
    Time:1472 ms
    Memory:20452 kb
****************************************************************/
 
import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;
  
public class Main {
    public static BigInteger Cal(int n) {
        BigInteger re = BigInteger.ONE;
        for (int i = 2; i <= n; ++i)
            re = re.multiply(BigInteger.valueOf(i));
        return re;
    }
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int ar[] = new int[1001];
        int c = 0, k, sum = 0;
        int n = cin.nextInt();
        for (int i = 0; i < n; ++i) {
            k = cin.nextInt();
            if (-1 == k) continue;
            else {
                sum += k - 1;
                ar[c++] = k - 1;
            }
        }
        BigInteger ans = Cal(sum);
        for (int i = 0; i < c; ++i)
            ans = ans.divide(Cal(ar[i]));
        ans = ans.multiply(BigInteger.valueOf(n - c).pow(n - 2 - sum));
        ans = ans.multiply(Cal(n - 2)).divide(Cal(sum)).divide(Cal(n - 2 - sum));
        System.out.println(ans);
    }
  
}