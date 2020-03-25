public class Engine 
{
	private String description;
	private int mpg;
	private int maxSpeed;
	
	public Engine(String t, int m, int s)
	{
		if (t.length() == 0)
		{
			description = "Generic Engine";
			if(m < 0){
				mpg = 0;
			}else{
				mpg = m;
			}if(s < 0){
				maxSpeed = 0;
			}else{
				maxSpeed = m;
			}
		}else{
			description = t;
			if(m < 0){
				mpg = 0;
			}else{
				mpg = m;
			}if(s < 0){
				maxSpeed = 0;
			}else{
				maxSpeed = s;
			}
		}
	}
	
	public String getDescription()
	{
		String engineScrip = description + " (MPG: " + getMPG() + ", Max Speed: " + getMaxSpeed() + ")";
		return engineScrip;
	}
	
	public int getMPG()
	{
		return mpg;
	}
	
	public int getMaxSpeed()
	{
		return maxSpeed;
	}
	
}
