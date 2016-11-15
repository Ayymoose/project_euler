public class Main {
  public static void main(String[] args) {
    Prime p = new Prime();
    int[] primes = p.sieveStatic(2_000_000);
    long primeSum = 0;
    for (int i=0; i<primes.length; i++) {
      primeSum += primes[i];
    }
    System.out.println(primeSum);
  }
}
