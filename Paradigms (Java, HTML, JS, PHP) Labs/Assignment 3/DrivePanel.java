//Zack Fravel
//Programming Paradigms
//DrivePanel.java

import java.awt.Graphics;
import javax.swing.JPanel;

public class DrivePanel extends JPanel 
{
	int legs; 
	int[] xCoords;
	int[] yCoords;
	
	public DrivePanel(int[] xLocations, int[] yLocations, int size)
	{
		legs = size;
		xCoords = xLocations;
		yCoords = yLocations;
		
	}
	
	public void paintComponent ( Graphics g )
	{
		
		// Ensures panel is properly rendered before drawing
		super.paintComponent( g );
		
		int width = getWidth();
		int height = getHeight();
		
		// Draw Trip
		
		// First Leg
		g.drawLine(0, height, xCoords[0], height - yCoords[0]);
		g.drawString("(" + xCoords[0] + "," + yCoords[0] + ")", xCoords[0] + 10, height - yCoords[0]);
		
		// Multiple legs 
		if(legs > 1)
		{
			int prev = 0;
			for(int i = 1; i < legs; i++)
			{
				g.drawLine(xCoords[prev], height - yCoords[prev], xCoords[i], height - yCoords[i]);
				g.drawString("(" + xCoords[i] + "," + yCoords[i] + ")", xCoords[i] + 10, height - yCoords[i]);
				prev++;
			}
			
		}
		
	}
}
