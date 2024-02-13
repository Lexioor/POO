using System;

public class Usuario
{
    protected string nombre;
    protected string telefono;
    protected int edad;
    protected string contraseña;
    protected bool logged_in;

    public Usuario(string nombre, string telefono, int edad, string contraseña)
    {
        this.nombre = nombre;
        this.telefono = telefono;
        this.edad = edad;
        this.contraseña = contraseña;
        this.logged_in = false;
    }

    public void Login(string nombreUsuario, string contraseña)
    {
        if (nombreUsuario == this.nombre && contraseña == this.contraseña)
        {
            this.logged_in = true;
            Console.WriteLine("¡Inicio de sesión exitoso!");
        }
        else
        {
            Console.WriteLine("Nombre de usuario o contraseña incorrectos.");
        }
    }

    public void Logout()
    {
        this.logged_in = false;
        Console.WriteLine($"Sesión cerrada. ¡Hasta luego, {nombre}!");
    }
}

public class Proveedor : Usuario
{
    public Proveedor(string nombre, string telefono, int edad, string contraseña)
        : base(nombre, telefono, edad, contraseña) { }

    public void Vender(string producto, int cantidad)
    {
        if (logged_in)
        {
            Console.WriteLine($"{nombre} ha vendido {cantidad} unidades de {producto}");
        }
        else
        {
            Console.WriteLine("Debe iniciar sesión para vender.");
        }
    }

    public void ActualizarInventario(string producto, int cantidad)
    {
        if (logged_in)
        {
            Console.WriteLine($"Inventario actualizado: {producto} - {cantidad} unidades");
        }
        else
        {
            Console.WriteLine("Debe iniciar sesión para actualizar el inventario.");
        }
    }
}

    public class Cliente : Usuario
{
    public Cliente(string nombre, string telefono, int edad, string contraseña)
        : base(nombre, telefono, edad, contraseña) { }

    public void Comprar(string producto, int cantidad)
    {
        if (logged_in)
        {
            Console.WriteLine($"{nombre} ha comprado {cantidad} unidades de {producto}");
        }
        else
        {
            Console.WriteLine("Debe iniciar sesión para comprar.");
        }
    }

    public void VerPerfil()
    {
        Console.WriteLine($"Nombre: {nombre}, Teléfono: {telefono}, Edad: {edad}");
    }
}


class Program
{
    static void Main(string[] args)
    {
        Proveedor proveedor1 = new Proveedor("Lala", "3347239503", 30, "Lala2024");
        Cliente usuario1 = new Cliente("Marcelo", "3310245798", 25, "Marcelosky1");

        // Iniciar sesión
        proveedor1.Login("Lala", "Lala2024");

        // Ejecutar funciones del proveedor
        proveedor1.Vender("Leche", 50);
        proveedor1.ActualizarInventario("Yogurt", 25);

        // Cerrar sesión
        proveedor1.Logout();

        //Iniciar sesión
        usuario1.Login("Marcelo", "Marcelosky1");

        //Ver información del usuario
        usuario1.VerPerfil();

        //Comprar Producto
        usuario1.Comprar("Leche", 1);

        //Cerrar sesión
        usuario1.Logout();

    }
}
