import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class Program {

	
	public static float cross(Vector v1,Vector v2) {
		return (v1.vx() * v2.vy()) - (v1.vy() * v2.vx());
	}
	
	//The vector v1 to v2
	public static Vector to(Vector v1,Vector v2) {
		return new Vector(v2.vx() - v1.vx(),v2.vy() - v1.vy());
	}
	
	//Defined sign function
	public static boolean sign(float f) {
		return f > 0;
	}
	
	//p,p1-p3 are all points 
	public static boolean pointInTriangle(Vector p,Vector p1,Vector p2,Vector p3) {
		
		//Won't work if the points are not in "order"
		//Now here's the problem :/
		
		//Need to order them first
		
		Vector v1tov3 = to(p1,p3);
		Vector v1tov = to(p1,p);
		Vector v2tov = to(p2,p);
		Vector v3tov = to(p3,p);
		Vector v1tov2 = to(p1,p2);
		Vector v2tov3 = to(p2,p3);
	
		return 
				(sign(cross(v1tov3,v1tov)) == sign(cross(v1tov,v1tov2)))
			 && (sign(cross(v1tov2.neg(),v2tov)) == sign(cross(v2tov,v2tov3)))
			 && (sign(cross(v2tov3.neg(),v3tov)) == sign(cross(v3tov,v1tov3.neg())));
		
	}
	
	
	public static void main(String[] args) {
	    //Read the contents of the file into a String array
		//Separate each line into 3 vectors at the 2nd comma
		
		//Origin
		Vector o = new Vector(0,0);
		int inTriangle = 0;
		
		try {
			File file = new File("/homes/am5514/Programming/Java/PE102/src/p102_triangles.txt");
			FileReader fileReader = new FileReader(file);
			BufferedReader bufferedReader = new BufferedReader(fileReader);

			String line;
			while ((line = bufferedReader.readLine()) != null) {
				
				
				String[] p = line.split(",",6);
				
				//Get our points
				Vector p1 = new Vector(Integer.parseInt(p[0]),Integer.parseInt(p[1]));
				Vector p2 = new Vector(Integer.parseInt(p[2]),Integer.parseInt(p[3]));
				Vector p3 = new Vector(Integer.parseInt(p[4]),Integer.parseInt(p[5]));
				
				if (pointInTriangle(o,p1,p2,p3)) {
					inTriangle++;
				}
			}
			fileReader.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println("Number of triangles containing origin is " + inTriangle);
		
	}
	
	
}
