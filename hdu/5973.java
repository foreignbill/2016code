import java.math.BigDecimal;
import java.util.Scanner;

public class Main{

    public static void main(String[] args) {
        BigDecimal TWO = BigDecimal.valueOf(2);
        BigDecimal FIVE = BigDecimal.valueOf(5);

        BigDecimal EPS = new BigDecimal("0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
        BigDecimal l = new BigDecimal("2"), r = new BigDecimal("3");
        BigDecimal m = null;

        while(r.subtract(l).compareTo(EPS)>=0){
            m = l.add(r).divide(TWO);
            if(m.multiply(m).subtract(FIVE).abs().compareTo(EPS.abs())<0) break;
            if(m.multiply(m).subtract(FIVE).compareTo(EPS)<0) l = m;
            else r = m;
        }
        BigDecimal GOLD = m.add(BigDecimal.ONE).divide(TWO);
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            BigDecimal a = sc.nextBigDecimal(), b = sc.nextBigDecimal();
            if(a.compareTo(b)>0){
                BigDecimal t = a;
                a = b;
                b = t;
            }
            BigDecimal c = b.subtract(a).setScale(0,BigDecimal.ROUND_FLOOR).multiply(GOLD);
            c = c.setScale(0, BigDecimal.ROUND_FLOOR);
            if(a.equals(c)) System.out.println("0");
            else System.out.println("1");
        }
    }
}