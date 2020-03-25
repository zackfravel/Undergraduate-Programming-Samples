//Zack Fravel
//Programming Paradigms
//GasTank.java

public class GasTank 
{
	private int Capacity;
	private double Level;
	
	public GasTank(int CapacityIn)
	{
		if(CapacityIn < 0)
		{
			Capacity = 0;
		}else{
			Capacity = CapacityIn;
		}
		Level = 0;
	}
	
	public int getCapacity()
	{
		return Capacity;
	}
	
	public double getLevel()
	{
		return Level;
	}
	
	public void setLevel(double levelIn)
	{
		if(levelIn < 0){
			Level = 0;
		}else if(levelIn > Capacity){
			Level = Capacity; 
		}else{
			Level = levelIn;
		}
	}
}
