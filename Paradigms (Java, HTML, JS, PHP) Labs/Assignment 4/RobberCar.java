// Zack Fravel
// Programming Paradigms
// RobberCar.java

import java.awt.Graphics;
import java.util.Random;

public class RobberCar extends Car
{
	private int xRatio = 0;
	private int yRatio = 0;
	
	public RobberCar()
	{
		// Create Car
		super(20, new Engine("Robber", 20, 200), "red-car.jpg");
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
	
	public void update(Graphics g) 
	{
		// Move the Car
		//super.setX(super.getX() + xRatio);
		//super.setY(super.getY() + yRatio);
		super.drive(40, xRatio, yRatio);
		
		// Draw the Car
		super.update(g);
	}
	
}
