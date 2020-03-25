import java.awt.Graphics;

//Zack Fravel
//Programming Paradigms
//Car.java

public class Bank extends Sprite 
{
	public Bank()
	{
		super("bank.png");
		setX(300);
		setY(300);
	}

	public void updateImage(Graphics g) 
	{
		// Call Sprite update()
		super.updateImage(g);
	}

}