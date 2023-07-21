using System;

class HelloWorld
{
  
    static void Main ()
      {
        
        String[]Player = new String[2];
            
         
        int[] PlayerTotal = new int[2];
            
        PlayerTotal[0] = 0;
            
        PlayerTotal[1] = 0;
            
        Console.Write ("Enter the name of Player 1: ");
            
        Player[0] = Console.ReadLine ();
            
        Console.Write ("Enter the name of Player 2: ");
            
        Player[1] = Console.ReadLine ();
            
         
        Random DiceRandom = new Random ();
            
        int turn = 0;
            
        while (true)
              {
        	
            Console.Write ("Turn: " + Player[turn] + "\nPress Enter to roll" +
            			"\n");
            	
            Console.ReadLine ();
            	
            int tmp = DiceRandom.Next (1, 6);
            	
            PlayerTotal[turn] += tmp;
            	
            Console.Write (Player[turn] + "'s Roll: " + tmp + ", Total: " +
            			PlayerTotal[turn] + "\n");
            	
            if (PlayerTotal[turn] >= 20)
            	  {
            	    
            Console.Write ("Player " + Player[turn] + " won!!!!!",
            			    Player[turn] + "\n");
            	    
            break;
            	  
            }
            	
            if (tmp != 6)
            	  {
            	    
                turn ^= 1;
            	  
            }
              
         
        }
      
     
    }

}


