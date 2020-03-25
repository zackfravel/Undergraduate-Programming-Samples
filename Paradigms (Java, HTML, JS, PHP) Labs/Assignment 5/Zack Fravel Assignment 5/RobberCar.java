// Zack Fravel
// Programming Paradigms
// RobberCar.java

import java.awt.Graphics;
import java.util.Random;

public class RobberCar extends Car
{
	private int xRatio = 0;
	private int yRatio = 0;
	private boolean caught = false;
	private boolean gone = false; 
	private static int captured = 0;
	private static int escaped = 0;
	
	public RobberCar()
	{
		// Create Car
		super(5000, new Engine("Robber", 20, 200), "red-car.jpg");
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
		if ( caught != true )
			super.drive(4, xRatio, yRatio);
		if(gone == false)
		{
			if((getX() < 0 || getX() > 1000) || (getY() < 0 || getY() > 700))
			{
				gone = true;
				escaped++;
				//System.out.println("Escaped: " + escaped); Check
			}
		}
	}
	
	public void captured()
	{
		if(caught != true)
		{
			caught = true;
			captured++;
			setImage("jail.jpg");
			//System.out.println("Captured: " + captured); Check 
		}
	}
	
	public boolean isCaptured()
	{
		if(caught == true)
			return true;
		else
			return false;
	}
	
	public boolean hasEscaped()
	{
		if(gone == true)
		{
			return true;
		}else
			return false;
	}
	
	// Add return methods to allow access to the number of Escaped/Captured
	
	public static int getCaptured()
	{
		return captured;
	}
	
	public static int getEscaped()
	{
		return escaped;
	}
	
	public static void reset()
	{
		captured = 0;
		escaped = 0;
	}
	
}
