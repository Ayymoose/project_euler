public class Prime {
  
  private int[] sieve;
  
  //Static implementation of sieve() O(n^2)
  public int[] sieveStatic(int n) {
    //Returns a sieve of n returning all elements less than n
    
    //1. Populate array with up to and including n
    int[] sieveInt = new int[n+1];
    
    for (int i=0; i<=n; i++) {
      sieveInt[i] = ((i % 2 == 0 && i != 2) || i == 1 ? 0 : i);
    }
    
    boolean end = false;
    
    //2. Mark each odd multiple of the array
    for (int j=3; j<sieveInt.length && !end; j+=2) {
      for (int i=3; i*j <sieveInt.length && !end; i+=2) {
        if (i*j < sieveInt.length) {
          sieveInt[i*j] = 0;    
        } else {
          end = true;
        }
      }
    }
    
    sieve = sieveInt;
    return sieveInt;
  }
  
  //Dynamic implementation of sieve() O(n^2)
  public int[] sieveDynamic(int n) {
    //TODO: Implement
    return null;
  }
  
  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("[");
    for (int i=0; i<sieve.length; i++) {
     sb.append(sieve[i] + (i == sieve.length-1 ? "" : ","));
    }
    sb.append("]");
    return sb.toString();
  }

}
