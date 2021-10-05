using System;
namespace Dice{
    class Program{
        static void Main(string[] args){
        int userno;
        int oppno;
        int user=0;
        int opponent=0;
        Random random = new Random();
        for(int i = 0;i<100;i++){
            Console.WriteLine("Press any key to roll");
            Console.ReadKey();
            userno=random.Next(1,7);
            Console.WriteLine("user rolled: "+userno);

            Console.WriteLine("...");
            System.Threading.Thread.Sleep(3000);

            oppno=random.Next(1,7);
            Console.WriteLine("user rolled: "+oppno);

            if(user>opponent){
                user++;
                Console.WriteLine("user wins round");
            }
            else if(user<opponent){
                opponent++;
                Console.WriteLine("opponent wins round");
            }
            else{
                Console.WriteLine("Draw")
            }
           Console.WriteLine("user score:"+user+"opponent score:"+opponent);
           Console.WriteLine()
        }
         if(user>opponent){
               
                Console.WriteLine("user wins");
            }
            else if(user<opponent){
                Console.WriteLine("opponent wins");
            }
        Console.ReadKey();
        }
    }
}
