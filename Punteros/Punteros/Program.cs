using System;

public class Resource : IDisposable
{
    public Resource()
    {
        Console.WriteLine("Puntero Creado");
    }

    public void Dispose()
    {
        Console.WriteLine("Puntero Borrado");
    }
}

class Program
{
    static void Main(string[] args)
    {
        using (var resource = new Resource())
        {

            Console.WriteLine("Puntero en uso ");
        }
    }
}
