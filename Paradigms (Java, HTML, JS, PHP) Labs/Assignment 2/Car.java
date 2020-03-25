import java.text.DecimalFormat;

public class Car 
{
	private String description;
	private int x = 0, y = 0;
	private GasTank g;
	private Engine e;
	
	public Car(String d, int c, Engine r)
	{
		//Check Description
		if(d.length() == 0)
		{
			description = "Generic Car";
		}else{
			description = d;
		}
		
		//Check Gas Tank
		g = new GasTank(c);
		
		//Check Engine
		if(r == null)
		{
			e = new Engine("", 0, 0);
		}else{
			e = r;
		}
	}
	
	public String getDescription()
	{
		//Sets the correct amount of decimals for the fuel level
		DecimalFormat df = new DecimalFormat("0.00");
		String carScrip = description + " (engine: "  + e.getDescription() + "), fuel:" + df.format(g.getLevel()) + "/" + g.getCapacity() + ", location: (" + getX() + "," + getY() + ")";
		return carScrip;
	}
	
	public int getX()
	{
		return x;
	}
	p
	public int getY()
	{
		return y;
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
		
		//Correctly checks the level of the gas tank and adds distances accordingly
		previousLevel = g.getLevel();
		newLevel = g.getLevel() - (desiredDistance/e.getMPG());
		if(newLevel < 0)
		{
			//Find the remaining amount of distance car can travel
			miles = previousLevel*e.getMPG();
			System.out.println("Ran out of gas after driving " + miles + " miles.");
			g.setLevel(0.00);
			return miles;
		}else{
			g.setLevel(newLevel);
			return distance;
		}
		//Testing Variables
		//System.out.println(desiredDistance);
		//System.out.println(newLevel);
		//System.out.println(previousLevel);
	}
	
}
