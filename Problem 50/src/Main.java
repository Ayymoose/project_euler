import java.util.HashMap;
import java.util.Map;


public class Main {

  public static void main(String[] args) {
    
    
    long startTime = System.currentTimeMillis();
    
    
    PrimeSieve p = new PrimeSieve(1_000_000,true);
    p.sieveDynamic();
    
    //Map<Integer,Integer> primeMap = new HashMap<Integer,Integer>();
    System.out.println(p.primesInSieve());
    System.out.println(p.primeSum(543));
    
    int primeSum = 0;
    int index = 1;
    
   while (primeSum < 1_000_000) {
      primeSum += p.getNthPrime(index);
      index++;
    }

   System.out.println("# Primes encountered before exceeding 1,000,000: " + (index-1));

    while (!p.sieveContains(primeSum)) {
      System.out.println(primeSum + " - " + p.getNthPrime(index) + " = " + (primeSum - p.getNthPrime(index)));
      primeSum -= p.getNthPrime(index);
      index--;
    }
    System.out.println("****" + primeSum + "****");
  
  
    System.out.println("Elapsed: " + ((double)(System.currentTimeMillis() - startTime)) / 1000 + "s.");
  }
  
  
}
