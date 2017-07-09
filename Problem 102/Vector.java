public class Vector {

	private float x;
	private float y;
	
	//Constructor
	Vector(float x,float y) {
		this.x = x;
		this.y = y;
	}
	
	//Getters 
	public float vx() {
		return this.x;
	}
	
	public float vy() {
		return this.y;
	}
	
	//No operator overloading? Damn
	public Vector neg() {
		return new Vector(-this.x,-this.y);
	}
	
	
	//Display
	public void print() {
		System.out.println("(" + this.x + "," + this.y + ")");
	}
	/*
	 * (x1)   (x2)
	 * (y1) x (y2) = 
	 * (z1)   (z2)   (x1*y2 - y1*x2)
	 * 
	 */
	
	
	
}
