import java.math.BigInteger;
import java.util.HashSet;
import java.util.Set;

public class Main {

  public static void main(String[] args) {
    
    long startTime = System.currentTimeMillis();
    
    Set<BigInteger> powers = new HashSet<BigInteger>();
    BigInteger a = new BigInteger("2");
    for (int a0 = 2; a0 <= 100; a0++) {
      for (int b0 = 2; b0 <= 100; b0++) {
        powers.add(a.pow(b0));
      }
      a = a.add(new BigInteger("1"));
    }
    
    System.out.println(powers.size()); 
    System.out.println("Elapsed: " + ((double)(System.currentTimeMillis() - startTime)) / 1000 + "s.");
  }

}
