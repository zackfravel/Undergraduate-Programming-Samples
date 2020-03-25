//Zack Fravel
//Programming Paradigms
//Assignment3.java

import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class Assignment3 
{
	
	public static void main ( String[] args )
	{
		
		// Variable Declaration and Dialogue Box Display
		// Assign integers and doubles with parsing methods
		
// 1. Input Car Description
		String carDescription = JOptionPane.showInputDialog("Enter car description:");
		
// 2. Input Fuel Tank Capacity
		String Capacity = JOptionPane.showInputDialog("Enter fuel tank capacity:");
		int capacity = 0;
		
		// Throw exception in the case input isn't an integer
		try{
			capacity = Integer.parseInt(Capacity);
		}
		catch (Exception e){
			// Quits Program
			JOptionPane.showMessageDialog(null ,"Invalid Data, Exiting");
			System.exit(0);
		}
		
		// Check for negatives and 0
		while(capacity <= 0)
		{
			Capacity = JOptionPane.showInputDialog("Please enter a positive fuel tank capacity:");
			// Throw exception for invalid entries
			try{
				capacity = Integer.parseInt(Capacity);
			}
			catch (Exception e){
				// Quit Program
				JOptionPane.showMessageDialog(null ,"Invalid Data, Exiting");
				System.exit(0);
			}
		}
		
// 3. Input Engine Description
		String engineDescription = JOptionPane.showInputDialog("Enter engine description:");
		
// 4. Input Miles Per Gallon
		String MPG = JOptionPane.showInputDialog("Enter fuel efficiency (Miles Per Gallon):");
		int mpg = 0;
		
		// Throw exception for invalid entries
		try{
			mpg = Integer.parseInt(MPG);
		}
		catch (Exception e){
			// Quits Program
			JOptionPane.showMessageDialog(null ,"Invalid Data, Exiting");
			System.exit(0);
		}
		
		// Check for negatives and 0
		while(mpg <= 0)
		{
			MPG = JOptionPane.showInputDialog("Please enter a positive fuel efficiency (Miles Per Gallon):");
			// Throw exception for invalid entries
			try{
				mpg = Integer.parseInt(MPG);
			}
			catch (Exception e){
				// Quits Program
				JOptionPane.showMessageDialog(null ,"Invalid Data, Exiting");
				System.exit(0);
			}
		}
		
// 5. Input Maximum Speed
		String Speed = JOptionPane.showInputDialog("Enter max speed:");
		int speed = 0;
		
		// Throw exception for invalid entries
		try{
			speed = Integer.parseInt(Speed);
		}
		catch (Exception e){
			// Quits Program
			JOptionPane.showMessageDialog(null ,"Invalid Data, Exiting");
			System.exit(0);
		}
		
		// Check for negatives and 0
		while(speed <= 0)
		{
			Speed = JOptionPane.showInputDialog("Please enter a positive max speed:");
			// Throw exception for invalid entries
			try{
				speed = Integer.parseInt(Speed);
			}
			catch (Exception e){
				// Quits Program
				JOptionPane.showMessageDialog(null ,"Invalid Data, Exiting");
				System.exit(0);
			}
		}
		
// Initialize Engine object with stored variables
		Engine engine = new Engine(engineDescription, mpg, speed);
		
// Initialize Car object with stored variables, the capacity (car class creates GasTank object), 
// and the engine object we just initialized 
		Car car = new Car(carDescription, capacity, engine);
		
// Fill up the gas tank before trip
		car.fillUp();
		
// 6. Show the user their current car information
		JOptionPane.showMessageDialog(null, car.getDescription());
		
// 7 - 11. Input legs, Distance, and (x,y)-ratios
		String Legs = JOptionPane.showInputDialog("How many legs are on your trip?");
		int legs = 0;
		
		// Throw exception for invalid entries
		try{
			legs = Integer.parseInt(Legs);
		}
		catch (Exception e){
			// Quits Program
			JOptionPane.showMessageDialog(null ,"Invalid Data, Exiting");
			System.exit(0);
		}
		
		// Check for negatives and 0
		while(legs <= 0)
		{
			Legs = JOptionPane.showInputDialog("How many legs are on your trip? (enter positive value)");
			// Throw exception for invalid entries
			try{
				legs = Integer.parseInt(Legs);
			}
			catch (Exception e){
				// Quits Program
				JOptionPane.showMessageDialog(null ,"Invalid Data, Exiting");
				System.exit(0);
			}
		}
		
		// Declare Arrays to account for multiple legs on distance and ratio variables
		
		// Strings 
		String[] XRatio = new String[legs];
		String[] YRatio = new String[legs];
		String[] Distance = new String[legs];
		
		// Data
		double[] xRatio = new double[legs]; 
		double[] yRatio = new double[legs]; 
		int[] distance = new int[legs];
		// Arrays for storing the locations of each leg for drawing the graphic
		int[] xLocs = new int[legs];
		int[] yLocs = new int[legs];
		
		// Account for the case of multiple legs in the trip with while loop implimentation
		int index = 0;
		int lNum = 1;
		if(legs > 1)
		{
			
			// Multiple Legs
			while(legs > 0)
			{
				// index assignments 
				
		// Ask for distance
				
				Distance[index] = JOptionPane.showInputDialog("Enter distance for leg " + lNum + ":");
				
				// Check for exception
				try{
					distance[index] = Integer.parseInt(Distance[index]);
				}
				catch (Exception e){
					// Quits Program
					JOptionPane.showMessageDialog(null ,"Invalid Data, Exiting");
					System.exit(0);
				}
				
				// Check for negatives and 0
				while(distance[index] <= 0)
				{
					Distance[index] = JOptionPane.showInputDialog("Please enter a positive distance for leg " + lNum + ":");
					
					// Check for exception
					try{
						distance[index] = Integer.parseInt(Distance[index]);
					}
					catch (Exception e){
						// Quits Program
						JOptionPane.showMessageDialog(null ,"Invalid Data, Exiting");
						System.exit(0);
					}
				}
				
		// Ask for x Ratio
				
				XRatio[index] = JOptionPane.showInputDialog("Enter X Ratio for leg " + lNum + ":");
				
				// Check exception
				try{
					xRatio[index] = Double.parseDouble(XRatio[index]);
				}
				catch (Exception e){
					// Quits Program
					JOptionPane.showMessageDialog(null ,"Invalid Data, Exiting");
					System.exit(0);
				}
				
		// Ask for y Ratio
				
				YRatio[index] = JOptionPane.showInputDialog("Enter Y Ratio for leg " + lNum + ":");
				
				// Check exception
				try{
					yRatio[index] = Double.parseDouble(YRatio[index]);
				}
				catch (Exception e){
					// Quits Program
					JOptionPane.showMessageDialog(null ,"Invalid Data, Exiting");
					System.exit(0);
				}
				
				// decrement legs until 0 and increment index accordingly after each loop runs
				legs --;
				index ++;
				lNum++;
			}
		}else{
			// One Leg -> regular assignment
			
			Distance[0] = JOptionPane.showInputDialog("Enter distance:");
			// throw exception if invalid
			try{
				distance[0] = Integer.parseInt(Distance[0]);
			}
			catch (Exception e){
				// Quits Program
				JOptionPane.showMessageDialog(null ,"Invalid Data, Exiting");
				System.exit(0);
			}
			
			// Check for negatives and 0
			while(distance[0] <= 0)
			{
				Distance[0] = JOptionPane.showInputDialog("Please enter a positive distance:");
				// throw exception if invalid
				try{
					distance[0] = Integer.parseInt(Distance[0]);
				}
				catch (Exception e){
					// Quits Program
					JOptionPane.showMessageDialog(null ,"Invalid Data, Exiting");
					System.exit(0);
				}
			}
			
			XRatio[0] = JOptionPane.showInputDialog("Enter X Ratio:");
			// throw exception if invalid
			try{
				xRatio[0] = Double.parseDouble(XRatio[0]);
			}
			catch (Exception e){
				// Quits Program
				JOptionPane.showMessageDialog(null ,"Invalid Data, Exiting");
				System.exit(0);
			}
			
			YRatio[0] = JOptionPane.showInputDialog("Enter Y Ratio:");
			// throw exception if invalid
			try{
				yRatio[0] = Double.parseDouble(YRatio[0]);
			}
			catch (Exception e){
				// Quits Program
				JOptionPane.showMessageDialog(null ,"Invalid Data, Exiting");
				System.exit(0);
			}
			
		}
		// Reset value of lNum in case of multiple legs
		lNum = 1;
		
		// Car drives	
		for(int i = 0; i < distance.length; i++)
		{
			System.out.println("\t" + "Leg " + lNum + "\n");
			car.drive(distance[i], xRatio[i], yRatio[i]);
			xLocs[i] = car.getX();
			yLocs[i] = car.getY();
			System.out.println(car.getDescription() + "\n");
			lNum++;
		}
		
		// Test location array assignments
		System.out.println("Locations:");
		for(int i = 0; i < distance.length; i++)
		{
			System.out.println("x: " + xLocs[i] + "\t y:" + yLocs[i]);
		}
		
// Trip Graphical Representation 
		
		// Create instance of DrivePanel class
		DrivePanel dPanel = new DrivePanel(xLocs, yLocs, distance.length);
		
		// Create instance of JFrame class to take on DrivePanel object
		JFrame dFrame = new JFrame();
		
		// Set Frame Parameters 
		dFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 		// Application will accordingly shut down when window is closed
		dFrame.add(dPanel);											// adds the dPanel object onto the dFrame
		dFrame.setSize(600, 600);									// sets the initial dFrame size to 600x600 pixels
		dFrame.setVisible(true);									// Makes sure dFrame is visible
	}
}
