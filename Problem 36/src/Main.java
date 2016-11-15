
public class Main {

  
  public static void main(String[] args) {
    
    Palindrome palindrome = new Palindrome(1);

    long startTime = System.currentTimeMillis();
    int sum = 0;
    
    for (int i=1; i<1_000_000; i++) {
      palindrome.setSeed(i);
      if (palindrome.isDecimalPalindrome() && palindrome.isBinaryPalindrome()) {
        sum += i;
      }
    }
    
    System.out.println("Sum of all palindromes under 1,000,000: " + sum);
    System.out.println("Elapsed: " + (double)(System.currentTimeMillis() - startTime)/1000 + "s");
    //Runs in ~1.02s
  }
  
}