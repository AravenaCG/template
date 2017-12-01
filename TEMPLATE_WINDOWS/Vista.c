#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"
#include "Cliente.h"
#include "Alquiler.h"


static void opcionAltaCliente();
static void opcionBajaCliente();
static void opcionModificacionCliente();
static void opcionListadoCliente();
static void opcionOrdenarClientes();
static void opcionAltaAlquiler();
static void opcionBajaAlquiler();
static void opcionModificacionAlquiler();
static void opcionListadoAlquiler();
static void opcionOrdenarAlquiler();
static int idiomaVista;

int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 9)
    {
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionAltaCliente();
                break;
            case 2:
                opcionModificacionCliente();
                break;
            case 3:
                opcionBajaCliente();
                break;
            case 4:
                opcionAltaAlquiler();
                break;
            case 5:
                opcionBajaAlquiler();
                break;
            case 6:
                opcionListadoCliente();
                break;
            case 7:
                opcionOrdenarClientes();
                break;
            case 9:
                break;
        }
    }

    return 0;
}

void vista_mostrarCliente(ArrayList* pListaClientes)
{

    printf("\nIMPRIMO LISTA DE ENTIDAD CLIENTES\n");
    al_map( pListaClientes,cliente_imprimir);

}


void vista_mostrarError(char * mensaje)
{

    printf("%s", mensaje);

}

static void opcionAltaCliente()
{

    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];
    val_getString(auxNombre, "Nombre? ", "Error",2,50);
    val_getString(auxApellido, "Apellido? ", "Error",2,50);
    val_getInt(auxDni, "DNI? ", "Error",2,50);
    cont_altaCliente(auxNombre,auxApellido,auxDni);

}

static void opcionBajaCliente()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaCliente(id);
    }

}

static void opcionModificacionCliente()
{
    char auxId[10];
    int id;
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {

        id = atoi(auxId);
        if (cont_IdExiste(id)== 1)
        {
            if(val_getString(auxNombre, "Nombre? ", "Error",2,50) == 0 &&
                val_getInt(auxDni, "DNI? ", "Error",2,50) == 0 &&
                val_getInt(auxDni, "DNI? ", "Error",2,50) == 0)
        {
            cont_modificarCliente(id,auxNombre,auxApellido,auxDni);
        }
        }
        else
        {
            vista_mostrarError("NO EXISTE EL CLIENTE!!!");
        }
    }



}

static void opcionAltaAlquiler()
{
   /* char a[50];
    char b[50];
    char c[50];
    if(val_getString(a, "A? ", "Error",2,50) == 0 &&
       val_getString(b, "B? ", "Error",2,50) == 0 &&
       val_getInt(c, "C? ", "Error",2,50) == 0)
    {
        cont_altaCliente(a,b,atoi(c));
    }*/
}


static void opcionBajaAlquiler()
{
    /* char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaCliente(id);
    }

*/

}
static void opcionModificacionAlquiler()
{
   /* char auxId[10];
    int id;
    char a[50];
    char b[50];
    char c[50];

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(a, "A? ", "Error",2,50) == 0 &&
           val_getString(b, "B? ", "Error",2,50) == 0 &&
           val_getInt(c, "C? ", "Error",2,50) == 0)
        {
            cont_modificarCliente(id,a,b,atoi(c));
        }
    }
*/
}



static void opcionListadoCliente()
{
    cont_listarCliente();
}


static void opcionListadoAlquiler()
{
    cont_listarAlquiler();
}

static void opcionOrdenarAlquiler()
{
    cont_ordenarAlquileres();
}

static void opcionOrdenarClientes()
{
    cont_ordenarClientes();
}


