#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Cliente.h"
#include "Validaciones.h"

int dm_saveAllClientes(ArrayList* pArrayClientes)
{

 int i;
    int retorno=-1;
    FILE* pFile=fopen(ARCHIVO_CLIENTES,"w");
    void* pCliente=NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"id,first_name,last_name,dni,estado\n");
        for(i=0;i<al_len(pArrayClientes);i++)
        {
            pCliente=al_get(pArrayClientes,i);
            fprintf(pFile, "%d,%s,%s,%s,%d\n", cliente_getIdCliente(pCliente),cliente_getNombre(pCliente),cliente_getApellido(pCliente),cliente_getDni(pCliente), cliente_getEstado(pCliente));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;

}

int dm_readAllClientes(ArrayList* pArrayClientes)
{


    FILE *pFile;
	Cliente* auxCliente= NULL;

	int maxId=0;

    char idCliente[50],nombre[50],apellido[50],dni[50],estado[50];

    pFile = fopen(ARCHIVO_CLIENTES,"r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idCliente,nombre,apellido,dni,estado);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idCliente,nombre,apellido,dni,estado) >0)
			{
				if(val_validarInt(idCliente)!=-1 && val_validarString(nombre)!=-1 && val_validarString(apellido)!=-1 && val_validarInt(dni)!=-1 && val_validarInt(estado)!=-1)
				{
					auxCliente=cliente_new(atoi(idCliente), nombre, apellido,dni, atoi(estado));
					al_add(pArrayClientes, auxCliente);

					if (atoi(idCliente)>maxId)
                    {
                        maxId=atoi(idCliente);
                    }
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return maxId;


}


int dm_readAllAlquileres(ArrayList* pArrayAlquileres)
{

    int retorno=-1;
    return retorno;
}

int dm_saveAllAlquileres(ArrayList* pArrayAlquileres)
{
    int i;
    int retorno=-1;
    return retorno;

}
