public class Animal
{
    public string Nombre { get; set; }
    public int Patas { get; set; }

    // Constructor
    public Animal(string nombre, int patas)
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
        Console.WriteLine($"El/La {Nombre} esta caminando con sus {Patas} patas.");
    }
}

public class AnimalVolador : Animal
{
    public AnimalVolador(string nombre, int patas) : base(nombre, patas)
    {
    }

    public override void Moverse()
    {
        Console.WriteLine($"El/La {Nombre} esta volando con sus {Patas} alas.");
    }
}

public class AnimalMarino : Animal
{
    public AnimalMarino(string nombre, int patas) : base (nombre, patas) 
    { 
    }

    public override void Moverse()
    {
        Console.WriteLine($"El/La {Nombre} esta nadando con sus {Patas} aletas.");
    }
}

class Programa
{
    static void Main(string[] args)
    {
        AnimalTerrestre gato = new AnimalTerrestre("Gato", 4);
        AnimalVolador perico = new AnimalVolador("Perico", 2);
        AnimalMarino tiburon = new AnimalMarino("Tiburon", 8);
        AnimalTerrestre perro = new AnimalTerrestre("Perro", 4);
        AnimalVolador aguila = new AnimalVolador("Aguila", 2);
        AnimalMarino foca = new AnimalMarino("Foca", 4);



        gato.Moverse();
        perico.Moverse();
        tiburon.Moverse();
        perro.Moverse();
        aguila.Moverse();
        foca.Moverse();

        Console.ReadLine();
    }
}