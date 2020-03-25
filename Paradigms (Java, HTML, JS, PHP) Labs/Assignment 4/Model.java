// Zack Fravel
// Programming Paradigms
// Model.java

import java.awt.Graphics;
import java.io.IOException;
import java.util.ArrayList;


class Model
{
	// ArrayList of Sprites
    private ArrayList<Sprite> sprite;
    
    // Allows to alternate between Cop and Robber Car
	boolean alternate = true;

    Model() throws IOException 
    {
    	sprite = new ArrayList<Sprite>();
    	// Create initial sprite (for when ArrayList is empty)
    	while(sprite.isEmpty() == true)
    	{
    		sprite.add(new CopCar());
    	}
    	
    }
    
    public void update(Graphics g) 
    {
    	for(int i = 0; i < sprite.size(); i++)
    	{
    		sprite.get(i).update(g);
    	}
    }
    
    // Right Click Fill Up Method
    public void fill()
    {
    	// Create sprite object to be casted onto
    	Sprite s;
    	// Goes through all car objects
    	for(int i = 0; i < sprite.size(); i++)
    	{
    		// Cast s as the current Car object in the loop so you can call fillUp()
    		s = sprite.get(i);
    		((Car)s).fillUp();
    	}
    }
    
    // Left Click Add Car Method
    public void addSprite(int x, int y)
    {
    	// Cop Car
    	if(alternate == false)
    	{
    		Car s = new CopCar();
        	s.setX(x);
        	s.setY(y);
        	sprite.add(s);
        	alternate = true;
        	s.fillUp();
        	
    	// Robber Car
    	}else{
    		Car s = new RobberCar();
        	s.setX(x);
        	s.setY(y);
        	sprite.add(s);
        	alternate = false;
    	}
    }
    
}