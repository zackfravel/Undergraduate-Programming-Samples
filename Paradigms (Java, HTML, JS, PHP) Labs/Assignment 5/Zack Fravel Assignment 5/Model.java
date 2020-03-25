// Zack Fravel
// Programming Paradigms
// Model.java

import java.awt.Graphics;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;


class Model
{
	// ArrayList of Sprites
    private ArrayList<Sprite> sprite;
    
    // Allows to alternate between Cop and Robber Car
	boolean alternate = false;

    Model() throws IOException 
    {
    	sprite = new ArrayList<Sprite>();
    	// Create initial sprite (for when ArrayList is empty)
    	while(sprite.isEmpty() == true)
    	{
    		sprite.add(new Bank());
    	}
    }
    
    public void update(Graphics g) 
    {
    	// Add synchronization to all methods which iterate over sprite
    	synchronized(sprite)
    	{
        	for(int i = 0; i < sprite.size(); i++)
        	{
        		sprite.get(i).updateImage(g);
        	}
    	}
    }
    
    public void updateScene(int width, int height)
    {
    	// Synchronize
    	synchronized(sprite)
    	{
    		// Check for overlapping
        	for(int i = 0; i < sprite.size(); i++)
        	{
        		sprite.get(i).updateState(width, height);
        		for(int j = 0; j < sprite.size(); j++)
        		{
        			if(sprite.get(i) instanceof CopCar && sprite.get(j) instanceof RobberCar)
        				if(sprite.get(i).overlaps(sprite.get(j)))
        				{
        					((RobberCar)sprite.get(j)).captured();
        				}
        		}
        	}
    	}
        	// Check for Escaped Robbers and Remove them from the list
    	synchronized(sprite)
    	{
        	Iterator<Sprite> iter =  sprite.iterator();
        	while(iter.hasNext())
        	{
        		Sprite removeCheck = iter.next();
        		if(removeCheck instanceof RobberCar)
        		{
        			if(((RobberCar)removeCheck).hasEscaped())
        			{
        				System.out.println("I'm Free!");
        				iter.remove();
        			}
        		}
        	}
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
    		// Start at the same position as the Bank
        	s.setX(300);
        	s.setY(300);
        	sprite.add(s);
        	alternate = false;
    	}
    }
    
    // Initialize
    
    public void initialize()
    {
    	// Synchronize
    	synchronized(sprite)
    	{
        	// Clear Sprites and Reset RobberCar statistics
        	sprite.clear();
        	RobberCar.reset();
        	
        	// Add initial bank sprite
        	Sprite initilizeBank = new Bank();
        	sprite.add(initilizeBank);
    	}

    }
    
}