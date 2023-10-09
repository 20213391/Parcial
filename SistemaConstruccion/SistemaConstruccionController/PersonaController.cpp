#include "PersonaController.h"

using namespace SistemaConstruccionController;
using namespace System::IO;

PersonaController::PersonaController() {

};

List<Persona^>^ PersonaController::buscarAll() {
	List<Persona^>^ listaPersonasEncontradas = gcnew List<Persona^>();
	array<String^>^ listaClientes = File::ReadAllLines("clientes.txt");
	array<String^>^ listaVendedores = File::ReadAllLines("vendedores.txt");
	String^ Separador = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	for each (String ^ Linea in listaClientes) {
		array<String^>^ datos = Linea->Split(Separador->ToCharArray());

		int codigo = Convert::ToInt32(datos[0]);
		String^ nombres = datos[1];
		String^ apellidoPaterno = datos[2];
		String^ apellidoMaterno = datos[3];
		String^ dni = datos[4];

		Persona^ objPersona = gcnew Persona(codigo, nombres, apellidoPaterno, apellidoMaterno, dni);
		listaPersonasEncontradas->Add(objPersona);
	}
	for each (String ^ Linea in listaVendedores) {
		array<String^>^ datos = Linea->Split(Separador->ToCharArray());
		
		int codigo = Convert::ToInt32(datos[0]);
		String^ nombres = datos[1];
		String^ apellidoPaterno = datos[2];
		String^ apellidoMaterno = datos[3];
		String^ dni = datos[4];

		Persona^ objPersona = gcnew Persona(codigo, nombres, apellidoPaterno, apellidoMaterno, dni);
		listaPersonasEncontradas->Add(objPersona);
	}
	return listaPersonasEncontradas;
};

Persona^ PersonaController::buscarPersonaxCodigo(int codigo) {
	List<Persona^>^ listaPersonas = buscarAll();
	for (int i = 0; i < listaPersonas->Count; i++) {
		if (listaPersonas[i]->getCodigo() == codigo) {
			return listaPersonas[i];
		}
	}
}

Persona^ PersonaController::buscarPersonaxDNI(String^ dni) {
	List<Persona^>^ listaPersonas = buscarAll();

	for (int i = 0; i < listaPersonas->Count; i++) {

		if (listaPersonas[i]->getDNI()->Contains(dni)) {

			return listaPersonas[i];
		}
	}
}


void PersonaController::escribirArchivo(List<Persona^>^ listaPersonas) {
	array<String^>^ Lineas = gcnew array<String^>(listaPersonas->Count);
	for (int i = 0; i < listaPersonas->Count; i++) {
		Persona^ objPersona = listaPersonas[i];
		Lineas[i] = objPersona->getCodigo() + ";" + objPersona->getNombres() + ";" + objPersona->getApellidoPaterno() + ";" + objPersona->getApellidoMaterno() + ";" + objPersona->getDNI();
	}
	File::WriteAllLines("personas.txt", Lineas);
};


void PersonaController::eliminarPersona(int codigo) {
	List<Persona^>^ listaPersonas = buscarAll();

	for (int i = 0; i < listaPersonas->Count; i++) {
		if (listaPersonas[i]->getCodigo() == codigo) {

			listaPersonas->RemoveAt(i);
		}
		escribirArchivo(listaPersonas);
	}
}


void PersonaController::agregarPersona(Persona^ objPersona) {
	List<Persona^>^ listaPersonas = buscarAll();
	listaPersonas->Add(objPersona);
	escribirArchivo(listaPersonas);
}


void PersonaController::actualizarPersona(Persona^ objPersona) {
	List<Persona^>^ listaPersonas = buscarAll();

	for (int i = 0; i < listaPersonas->Count; i++) {

		if (listaPersonas[i]->getCodigo() == objPersona->getCodigo()) {

			listaPersonas[i]->setCodigo(objPersona->getCodigo());
			listaPersonas[i]->setNombres(objPersona->getNombres());
			listaPersonas[i]->setApellidoPaterno(objPersona->getApellidoPaterno());
			listaPersonas[i]->setApellidoMaterno(objPersona->getApellidoMaterno());
			listaPersonas[i]->setDNI(objPersona->getDNI());

			break;
		}
	}
	escribirArchivo(listaPersonas);
}


List<String^>^ PersonaController::obtenerDNIs() {
	List<Persona^>^ listaPersonas = buscarAll();
	List<String^>^ listaDNIs = gcnew List<String^>();

	for (int i = 0; i < listaPersonas->Count; i++) {

		String^ dni = Convert::ToString(listaPersonas[i]->getDNI());

		int existe = 0;
		for (int j = 0; j < listaDNIs->Count; j++) {

			if (listaDNIs[j] == dni) {
				existe = 1;
			}
		}
		if (existe == 0) {
			listaDNIs->Add(dni);
		}
		listaDNIs->Add("Todos");
	}
	return listaDNIs;
}