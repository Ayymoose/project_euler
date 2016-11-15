public class Main {
  
  
  
  
  public static void main(String[] args) {
    
    Chain c = new Chain(1);
    
    long startTime = System.currentTimeMillis();
    
    for (int i=1; i<10_000_000; i++) {
      c.setSeed(i);
      c.run();
    }
    
    System.out.println("# Chains ending in 89: " + c.getCount89());
    System.out.println("Elapsed: " + ((double)(System.currentTimeMillis() - startTime)) / 1000 + "s.");
  }
  
  
  

}
