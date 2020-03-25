//Zack Fravel
//Programming Paradigms
//Car.java

import java.awt.Graphics;

public class Car extends Sprite
{
	private GasTank g;
	private Engine e;
	
	public Car(int c, Engine r, String jpg)
	{
		// Call Sprite constructor
		super(jpg);
		
		// Check Gas Tank
		g = new GasTank(c);
		
		// Check Engine
		if(r == null)
		{
			e = new Engine("", 0, 0);
		}else{
			e = r;
		}
	}
	
	public double getFuelLevel()
	{
		return g.getLevel();
	}
	
	public int getMPG()
	{
		return e.getMPG();
	}
	
	public void fillUp()
	{
		g.setLevel(g.getCapacity());
	}
	
	public int getMaxSpeed()
	{
		return e.getMaxSpeed();
	}
	
	public double drive(int distance, double xRatio, double yRatio)
	{
		double desiredDistance = distance;
		double newLevel;
		double previousLevel;
		double miles = 0;
		
		double hypRatio = Math.sqrt(Math.pow(xRatio, 2) + Math.pow(yRatio, 2));
		double movements = distance/hypRatio;
		

		//Correctly checks the level of the gas tank and adds distances accordingly
		previousLevel = g.getLevel();
		newLevel = g.getLevel() - (desiredDistance/e.getMPG());
		
		// Get Sprite Location
		int xLoc = super.getX();
		int yLoc = super.getY();
		
		if(newLevel < 0)
		{
			//Find the remaining amount of distance car can travel
			miles = previousLevel*e.getMPG();
			//System.out.println("Ran out of gas after driving " + miles + " miles.");
			g.setLevel(0.00);
			movements = miles/hypRatio;
			
			// Set Sprite Location
			xLoc += movements*xRatio;
			yLoc += movements*yRatio;
			
			// Send the new Location to sprite object (superclass)
			super.setX(xLoc);
			super.setY(yLoc);
			
			return miles;
			
		}else{
			
			// Reduce Tank level appropriately 
			g.setLevel(newLevel);
			
			// Set Sprite Location
			xLoc += movements*xRatio;
			yLoc += movements*yRatio;
			
			// Send the new Location to sprite object (superclass)
			super.setX(xLoc);
			super.setY(yLoc);
			
			return distance;
		}
	}
	
	public void updateImage(Graphics g) 
	{
		// Call Sprite update() to draw on screen
		super.updateImage(g);
	}
	
}
