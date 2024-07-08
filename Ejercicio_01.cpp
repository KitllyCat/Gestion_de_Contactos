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
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct contactoEmail {
    string nombres;
    string sexo;
    string edad;
    string telefono;
    string email;
    string nacionalidad;
};
vector<contactoEmail> contactos;
//minifuncion para que compruebe si el email tiene @ o no
bool esEmailValido(const string& email) { 
    return email.find('@') != string::npos;
}
//agregar contacto
void agregarContacto(vector<contactoEmail>& contactos){
	
	contactoEmail nuevoContacto;
    cout << "Ingrese los nombres completos del nuevo contacto: ";
    cin.ignore();
    getline(cin, nuevoContacto.nombres);
    cout << "Ingrese el sexo (M/F): ";
    cin >> nuevoContacto.sexo;
    cout << "Ingrese la edad: ";
    cin >> nuevoContacto.edad;
    cout << "Ingrese el teléfono: ";
    cin >> nuevoContacto.telefono;
    do {
        cout << "Ingrese el email: ";
        cin >> nuevoContacto.email;
        if (!esEmailValido(nuevoContacto.email)) {
            cout << "El email es invalido. Debe contener minimo un '@'" << endl;
        }
    } while (!esEmailValido(nuevoContacto.email));
    cout << "Ingrese la nacionalidad: ";
    cin.ignore();
    getline(cin, nuevoContacto.nacionalidad);
    contactos.push_back(nuevoContacto);
	cout<<"Contacto guardado safisfactoriamente~!"<<endl;
}


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
			break;
			
			case 1:
			agregarContacto(contactos);
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
