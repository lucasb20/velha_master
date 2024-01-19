namespace velha_master;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Hello World!");
        if(args[0] == "test"){
            Tests.Tests.Test_All();
        }
    }
}
