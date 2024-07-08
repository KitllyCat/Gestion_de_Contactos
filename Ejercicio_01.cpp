/* 1.
Gestión de Contactos
Crear una estructura llamada contactoEmail que tenga las siguientes características: nombres completos, sexo, edad, teléfono, email, nacionalidad
El programa debe constar de un menú que permita:
a) Agregar un contacto
b) Eliminar un contacto
c) Mostrar listado general de contactos registrados hasta ese momento.
d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas (gmail.com, outlook.com, yahoo.com, etc.)
e) Salir del programa
El programa debe mantenerse en ejecución continuamente hasta que usuario indique que desea salir del mismo. */
#include <iostream>
using namespace std;

int main(){
	int opcion;
	do{
		cout << "---Gestor de contactos---"<<endl;
		cout << "Seleccione la acción que desea realizar" << endl;
		cout << "A. Agregar un nuevo contacto" << endl;
		cout << "B. Eliminar un contacto existente" << endl;
		cout << "C. Mostrar todos los contactos guardados" << endl;
		cout << "D. Mostrar todos los contactos guardados en orden de correos" << endl;
		cout << "0. Salir" << endl;
		cout << "Selecione su opcion: ";
		cin >> opcion;
		cout << endl;
		switch(opcion){
			case 0;
			//salir del programa
			break;
			
			case 1:
			//aqui va la funcion de agregarContacto
			break;
			
			case 2:
			//aqui va la funcion eliminarContacto
			break;
		
			case 3;
			//aqui va la funcion mostrarContacto
			break;
			
			case 4;
			//aqui va la funcion mostrarContactoCorreo
			break;
			
			default;
			//error
			cout << "Opción no válida. Intente nuevamente." << endl;
			break;			
		}
		cout << endl;
	} while (opcion != 0);
	
	return 0;
}
