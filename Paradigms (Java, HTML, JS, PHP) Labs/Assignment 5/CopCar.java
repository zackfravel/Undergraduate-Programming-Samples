// Zack Fravel
// Programming Paradigms
// CopCar.java

import java.awt.Graphics;
import java.util.Random;

public class CopCar extends Car
{
	private static int xRatio = 0;
	private static int yRatio = 0;
	// Variable to allow direction to reverse
	private boolean direction = true;
	
	public CopCar()
	{
		super(5000, new Engine("Cop", 30, 100), "cop-car.jpg");
		super.fillUp();
		
		// Set Random Direction (value)
		Random num = new Random();
		xRatio = num.nextInt(6);
		yRatio = num.nextInt(6);
		
		// Set Random Direction (+/-) 
		Random sign = new Random();
		boolean signX = sign.nextBoolean();
		boolean signY = sign.nextBoolean();
		if(signX == false) {
			xRatio *= -1;
		}
		if(signY == false) {
			yRatio *= -1;
		}	
	}
	
	public void updateImage(Graphics g) 
	{
		// Draw the Car
		super.updateImage(g);
	}
	
	public void updateState(int width, int height)
	{
		// Move the Car
		if(direction == true)
		{
			super.drive(2, xRatio, yRatio);
		}else{
			// Reverse direction when CopCar hits an edge
			super.drive(2, -xRatio, -yRatio);
		}
		
		// Edge Detection (checks whether X or Y location is outside the window)
		if(getX() < 0 || getX() > width-70)
		{
			// Change direction to its compliment upon detecting an edge
			direction = !direction;
		}else if(getY() > height-85 || getY() < 0)
		{
			direction = !direction;
		}
	}
	
}
