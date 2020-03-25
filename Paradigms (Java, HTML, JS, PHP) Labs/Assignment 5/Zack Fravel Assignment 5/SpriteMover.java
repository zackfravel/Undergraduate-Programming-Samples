// Zack Fravel
// Programming Paradigms
// SpriteMover.java

public class SpriteMover implements Runnable 
{
	Model model;
	View view;
	
	public SpriteMover(Model m, View v)
	{
		model = m;
		view = v;
	}
	
	public void run()
	{
		while(true)
		{
			// scene updated
			model.updateScene(view.getWidth(), view.getHeight());
			
			// scene redrawn
			view.repaint();
			
			// Sleep for 2 milliseconds
			try{
				Thread.sleep(2);
			}catch(Exception e){}
		}
	}
}
