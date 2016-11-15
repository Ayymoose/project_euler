public class Chain {
  
  //Square digit chain
  private int seed;
  private int count89;
  private int count1;
  
  public Chain(int seed) {
    this.seed = seed;
  }
  
  public void setSeed(int seed) {
    this.seed = seed;
  }
  
  public void run() {
    //1 or 89 
    while (seed != 1 && seed != 89) {
      seed = squareDigit(seed);
    }
    count89 += (seed == 89 ? 1 : 0);
  }
  
  public int getCount89() {
    return count89;
  }
  
  private int squareDigit(int n) {
    return (n !=0 ? (n % 10) * (n % 10) + squareDigit(n / 10) : 0);
  }
  
}
