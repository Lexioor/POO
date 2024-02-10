using System;

public class Animal
{
    public string Nombre { get; set; }
    public int Patas { get; set; }

    public Class1(string nombre, int patas)
    {
        Nombre = nombre;
        Patas = patas;
    }

    public virtual void Moverse()
    {
        Console.WriteLine($"{Nombre} se mueve.");
    }
}

public class AnimalTerrestre : Animal
{
    public AnimalTerrestre(string nombre, int patas) : base(nombre, patas)
    {
    }

    public override void Moverse()
    {
        Console.WriteLine($"{Nombre} esta caminando.");
    }
}

public class AnimalVolador : Animal
{
    public AnimalVolador(string nombre, int patas) : base(nombre, patas)
    {
    }

    public override void Moverse()
    {
        Console.WriteLine($"{Nombre} esta volando.");
    }
}

class Programa
{
    static void Main(string[] args)
    {
        AnimalTerrestre gato = new AnimalTerrestre("Gato", 4);
        AnimalVolador perico = new AnimalVolador("Perico", 2);

        gato.Moverse();
        perico.Moverse();

        Console.ReadLine();
    }
}