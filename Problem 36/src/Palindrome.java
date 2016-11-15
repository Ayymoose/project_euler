public class Palindrome {

  private long number;
  
  public Palindrome(long number) {
    this.number = number;
  }
  
  public void setSeed(long number) {
    this.number = number;
  }
  
  private long numberOfDigits(long n) {
    while (n != 0) {
      return 1 + numberOfDigits(n / 10);
    }
    return 0;
  }
  
  private long reverse(long n) {
    long reverse = 0;
    long i = 0;
    long digits = (long)Math.log10(n)+1;
    
    while (n != 0) {
      reverse += (n % 10) * (long)Math.pow(10, digits - i - 1);
      n /= 10;
      i++;
    }
    return reverse;
  }
  
  public boolean isDecimalPalindrome() {
    return number == reverse(number);
  }
  
  public boolean isBinaryPalindrome() {
    String src = Long.toBinaryString(number);
    StringBuilder sb = new StringBuilder(src);
    return sb.reverse().toString().equals(src);
  }

  
}
