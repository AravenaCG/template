#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"
#include "Cliente.h"
#include "Alquiler.h"


static ArrayList* nominaClientes;
static int proximoIdCliente=0;
static int getNewIdCliente();
static int setNewIdCliente(int id);

static ArrayList* nominaAlquileres;
static int proximoIdAlquiler=0;
static int getNewIdAlquiler();
static int setNewIdAlquiler(int id);


void cont_init()
{
    nominaClientes = al_newArrayList();
    setNewIdCliente(dm_readAllClientes(nominaClientes) + 1);
    nominaAlquileres = al_newArrayList();
    setNewIdAlquiler(dm_readAllAlquileres(nominaAlquileres)+1);
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();


}

int cont_altaCliente (char* nombre,char* apellido,char* dni)
{
    Cliente* auxCliente;
    auxCliente = cliente_new(getNewIdCliente(), nombre,apellido,dni,CLIENTE_ACTIVO);
    al_add(nominaClientes,auxCliente);
    dm_saveAllClientes(nominaClientes);
    return 0;

}

int cont_altaAlquiler (int idCliente,int idEquipo,int tiempoEstimado, int tiempoReal, int idAquiler, int estado)
{
    Alquiler* auxAlquiler;
    auxAlquiler = alquiler_new( idCliente, idEquipo, tiempoEstimado, tiempoReal,  idAquiler, estado);
    al_add(nominaAlquileres, auxAlquiler);
    dm_saveAllAlquileres(nominaAlquileres);
    return 0;
}

int cont_bajaCliente (int id)
{
    Cliente* auxCliente;
    auxCliente= cliente_findByIdCliente(nominaClientes,id);
    if(auxCliente!=NULL)
    {
        if (cliente_getEstado(auxCliente)== CLIENTE_ACTIVO)
        {
            cliente_setEstado(auxCliente,CLIENTE_INACTIVO);
            dm_saveAllClientes(nominaClientes);
        }
        else
        {
            vista_mostrarError("EL CLIENTE YA ESTA DADO DE BAJA!!!\n");
        }
    }
    else
    {
        vista_mostrarError("EL CLIENTE NO EXISTE!!!\n");
    }


    return 0;

}


int cont_bajaALquiler (int id)
{


    return 0;
}


int cont_modificarCliente (int id, char* nombre,char* apellido,char* dni)
{
   Cliente* auxCliente;

    auxCliente=cliente_findByIdCliente(nominaClientes,id);

    if(auxCliente!=NULL)
    {
        cliente_setNombre(auxCliente,nombre);
        cliente_setApellido(auxCliente,apellido);
        cliente_setDni(auxCliente,dni);
        cliente_setEstado(auxCliente,CLIENTE_ACTIVO);
        dm_saveAllClientes(nominaClientes);
    }

    return 0;
}

int cont_IdExiste(int id)
{
    int retorno=0;
    Cliente* auxCliente;
    auxCliente= cliente_findByIdCliente(nominaClientes,id);
    if(auxCliente!=NULL)
    {
        if (cliente_getEstado(auxCliente)== CLIENTE_ACTIVO)
        {
            retorno=1;
        }
        else
        {
            retorno=-1;
        }

    }
    return retorno;
}
int cont_modificarAlquiler (int id, char* a,char* b,int c)
{

    return 0;
}


int cont_listarCliente ()
{
    vista_mostrarCliente(nominaClientes);
    return 0;
}

int cont_listarAlquiler ()
{
    //vista_mostrarX(nominaX);
    return 0;
}

int cont_ordenarClientes ()
{
    al_sort(nominaClientes,cliente_compareByApellido,1);
    return 0;
}

int cont_ordenarAlquileres ()
{

    return 0;
}

static int getNewIdCliente()
{
    return proximoIdCliente++;
}

static int getNewIdAlquiler()
{
    return proximoIdAlquiler++;
}

static int setNewIdCliente(int id)
{
    proximoIdCliente = id;
    return 0;
}


static int setNewIdAlquiler(int id)
{
    proximoIdAlquiler = id;
    return 0;
}
