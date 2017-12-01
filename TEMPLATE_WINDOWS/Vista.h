#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n1. ALTA CLIENTE\n2. MODIFICAR CLIENTE\n3.BAJA CLIENTE\n4. NUEVO ALQUILER\n4. FIN DEL ALQUILER\n6. INFORMAR\n \n9. SALIR\n\n\n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"




int vista_init (int idioma);
int vista_mostrarMenu();
void vista_mostrarCliente(ArrayList* pListaClientes);
void vista_mostrarError(char * mensaje);




