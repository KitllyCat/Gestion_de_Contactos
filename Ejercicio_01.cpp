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
    cout << "Ingrese el telefono: ";
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
//eliminar contacto
void eliminarContacto(vector<contactoEmail>& contactos, const string &nombre){
    int indice = -1;
    for (int i = 0; i < contactos.size(); ++i) {
        if (contactos[i].nombres == nombre) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        for (int i = indice; i < contactos.size() - 1; ++i) {
            contactos[i] = contactos[i + 1];
        }
        contactos.pop_back();
        cout << "El contacto ha sido eliminado correctamente" << endl;
    } else {
        cout << "Contacto no encontrado, ingrese correctamente el nombre" << endl;
    }
}
//mostrar contactos
void mostrarContacto(const vector<contactoEmail> &contactos){
	for (const auto &contacto : contactos) {
    cout << "Nombres: " << contacto.nombres << endl;
    cout << "Sexo: " << contacto.sexo << endl;
    cout << "Edad: " << contacto.edad << endl;
    cout << "Telefono: " << contacto.telefono << endl;
    cout << "Email: " << contacto.email << endl;
    cout << "Nacionalidad: " << contacto.nacionalidad << endl;
    cout << endl;
    }
}
//mostrar contactos ordenados
void mostrarContactoOrdenado(vector<contactoEmail>& contactos){
	if (contactos.empty()) {
        cout << "No existen  contactos registrados" << endl;
    } else {
        sort(contactos.begin(), contactos.end(), [](const contactoEmail& a, const contactoEmail& b) {
            return a.email < b.email;
        });

        for (const auto& contacto : contactos) {
            cout << "Nombres: " << contacto.nombres << endl;
            cout << "Sexo: " << contacto.sexo << endl;
            cout << "Edad: " << contacto.edad << endl;
            cout << "Telefono: " << contacto.telefono << endl;
            cout << "Email: " << contacto.email << endl;
            cout << "Nacionalidad: " << contacto.nacionalidad << endl;
            cout << endl;
        }
    }
}
//menu
int main(){
	int opcion;
	do{
		cout << "---Gestor de contactos---"<<endl;
		cout << "Seleccione la opcion que desea realizar en el programa:" << endl;
		cout << "(1) Agregar un nuevo contacto" << endl;
		cout << "(2) Eliminar un contacto existente" << endl;
		cout << "(3) Mostrar todos los contactos guardados" << endl;
		cout << "(4) Mostrar todos los contactos guardados en orden de correos" << endl;
		cout << "(0) Salir" << endl;
		cout << "Selecione su opcion: ";
		cin >> opcion;
		cout << endl;
		switch(opcion){
			
			case 1:{
			agregarContacto(contactos);
			break;
			}
			
			case 2:{
            string nombre;
            cout << "Ingrese el nombre del contacto que desea eliminar: " << endl;
            cin.ignore();
            getline(cin, nombre);
            eliminarContacto(contactos, nombre);
			break;
			}
		
			case 3:{
			cout<<"Mostrando todos los contactos guardados: "<<endl;
			cout<<endl;
			mostrarContacto(contactos);
			break;
			}
			
			case 4:{
			cout<<"Mostrando los contactos guardados ordenadenadamente(por correo): "<<endl;
			mostrarContactoOrdenado(contactos);
			cout<<endl;
			break;
			}
			
			case 0:{
			cout<<"Saliendo del programa..."<<endl;
			break;
			}
			
			default:{
			cout << "Opción no válida. Intente nuevamente." << endl;
			break;
			}	
					
		}
		cout << endl;
	} while (opcion != 0);
	
	return 0;
}
