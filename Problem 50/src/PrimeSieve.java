import java.util.Iterator;
import java.util.List;
import java.util.Vector;

public class PrimeSieve {  
  
  private int[] staticSieve;;
  private Vector<Integer> dynamicSieve;
  private int n;
  
  public PrimeSieve(int n,boolean dynamic) {
    this.n = n;
    if (!dynamic) {
      staticSieve = new int[n+1];
    }
  }
 
  //Dynamic only
 
  public int primeSum(int k) {
    //Sums the first n primes
    int sum = 0;
    int count = 0;
    Iterator<Integer> it = dynamicSieve.iterator();
    while (count < k && it.hasNext()) {
      sum += it.next();
      count++;
    }
    return sum;
  }

  public int getNthPrime(int n) {
    return dynamicSieve.get(n-1);
  }
  
  //I.e isPrime()
  public boolean sieveContains(int prime) {
    //O(log(n)) Binary Search
    List<Integer> temporarySieve = dynamicSieve;
    int primeInSieve = 0;
    while (temporarySieve.size() != 0) {
      primeInSieve = temporarySieve.get(temporarySieve.size() / 2);
      if (prime < primeInSieve) {
        temporarySieve = temporarySieve.subList(0, temporarySieve.size() / 2);
      } else if (prime > primeInSieve){
        if (prime < temporarySieve.get(temporarySieve.size()-1)) {
        temporarySieve = temporarySieve.subList(temporarySieve.size() / 2,temporarySieve.size());
        } else {
          return false;
        }
      } else {
        return true;
      }
    }
    return false;
  }
  
  
  public int primesInSieve() {
    return dynamicSieve.size();
  }
  //
  
  //Static implementation of staticSieve() O(n^2)
  public void sieveStatic() {
    //Returns a staticSieve of n returning all elements less than n
    
    //1. Populate array with up to and including n
   // int[] staticSieve = ;
    
    for (int i=0; i<=n; i++) {
      staticSieve[i] = (((i & 1) == 0 && i != 2) || i == 1 ? 0 : i);
    }
    
    boolean end = false;
    
    //2. Mark each odd multiple of the array
    for (int j=3; j<staticSieve.length && !end; j+=2) {
      for (int i=3; i*j <staticSieve.length && !end; i+=2) {
        if (i*j < staticSieve.length) {
          staticSieve[i*j] = 0;    
        } else {
          end = true;
        }
      }
    }
    
  
  }
  
  //Dynamic implementation of staticSieve() O(n^2)
  public Vector<Integer> sieveDynamic() {
    
    dynamicSieve = new Vector<Integer>();
    Vector<Integer> dynamicSieveCopy = new Vector<Integer>();
    
    for (int i=0; i<=n; i++) {
      dynamicSieve.add(((i % 2 == 0 && i != 2) || i == 1 ? 0 : i));
    }
    
    boolean end = false;

    //2. Mark each odd multiple of the array
    for (int j=3; !end && j<dynamicSieve.size(); j+=2) {
      for (int i=3; !end && i*j < dynamicSieve.size(); i+=2) {
        if (i*j < dynamicSieve.size()) {
          dynamicSieve.set(i*j, 0);
        } else {
          end = true;
        }
      }
    }
    
    Iterator<Integer> it = dynamicSieve.iterator();
    while (it.hasNext()) {
      Integer item = it.next();
      if (item != 0) {
        dynamicSieveCopy.add(item);
      }
    }

    return dynamicSieve = dynamicSieveCopy;
  }
  
  public String toString() {
    StringBuilder sb = new StringBuilder();
    
    sb.append("[");
    if (staticSieve != null) {
      for (int i=0; i<staticSieve.length; i++) {
        sb.append(staticSieve[i] + (i == staticSieve.length-1 ? "" : ",") + (i % 25 == 0 ? "\n" : ""));
      }
    } else {
      for (int i=0; i<dynamicSieve.size(); i++) {
        sb.append(dynamicSieve.get(i) + (i == dynamicSieve.size()-1 ? "" : ",") + (i % 100 == 0 ? "\n" : ""));
      }
    }
    sb.append("]");
    
    
    return sb.toString();
  }

}
