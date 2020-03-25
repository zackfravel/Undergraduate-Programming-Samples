// Zack Fravel
// Programming Paradigms
// Controller.java

import java.awt.Graphics;
import java.io.IOException;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import javax.swing.SwingUtilities;
import java.awt.event.KeyListener;
import java.awt.event.KeyEvent;


class Controller implements MouseListener, KeyListener
{
    Model model;
    View view;

    Controller() throws IOException, Exception 
    {
        model = new Model();
        view = new View(this);
    }

    public void update(Graphics g) 
    {
        model.update(g);
    }
    
    // Mouse Methods

    public void mousePressed(MouseEvent e) 
    {
		if (SwingUtilities.isLeftMouseButton(e)) {
			// Gets here is left mouse button was clicked
			model.addSprite(e.getX(), e.getY());
			view.repaint();
		} else if (SwingUtilities.isRightMouseButton(e))  {
			// Gets here if right mouse button was clicked
			// Calls fill method defined in model class
			model.updateScene(view.getWidth(), view.getHeight());
			view.repaint();
		}
    }

    public void mouseReleased(MouseEvent e) {    
    	
    }
    
    public void mouseEntered(MouseEvent e) {    
    	
    }
    
    public void mouseExited(MouseEvent e) {    
    	
    }
    
    public void mouseClicked(MouseEvent e) {    
    	
    }
    
    // Key Methods
    
	public void keyPressed(KeyEvent e) 
	{
		
	}
    
    public void keyReleased(KeyEvent e)
    {
    	
    }
    
    public void keyTyped(KeyEvent e)
    {
    	// Hello World
    	if(e.getKeyChar() == 'h')
    	{
    		System.out.println("hello world" + "\n");
    	}
    	// Robber Status
    	if(e.getKeyChar() == 'n')
    	{
    		System.out.println("Robbers Escaped: " + RobberCar.getEscaped());
    		System.out.println("Robbers Captured: " + RobberCar.getCaptured() + "\n");

    	}
    	// Reset
    	if(e.getKeyChar() == 'r')
    	{
    		model.initialize();
    		view.repaint();
    	}
    	if(e.getKeyChar() == 's')
    	{
    		SpriteMover automate = new SpriteMover(model, view);
    		Thread a = new Thread(automate);
    		a.start();
    	}
    }

    public static void main(String[] args) throws Exception 
    {
        //  Use the following line to determine which directory your program
        //  is being executed from, since that is where the image files will
        //  need to be.
        //  System.out.println("cwd=" + System.getProperty("user.dir"));
        new Controller();
    }

}

