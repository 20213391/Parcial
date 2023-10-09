#include "EdificioController.h"
#include "UbicacionController.h"
#include "DepartamentoController.h"

using namespace SistemaConstruccionController;
using namespace System::IO;

EdificioController::EdificioController() {

}

List<Edificio^>^ EdificioController::buscarAll() {
	/*En esta lista vamos a colocar la información de los Edificios que encontremos en el archivo de texto*/
	List<Edificio^>^ listaEdificiosEncontrados = gcnew List<Edificio^>();
	array<String^>^ lineas = File::ReadAllLines("edificios.txt");

	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	/*Esta instruccion for each nos permite ir elemento por elemento de un array*/
	for each (String ^ lineaEdificio in lineas) {
		/*Voy a separar cada elemento del String por ; con el split*/
		array<String^>^ datos = lineaEdificio->Split(separadores->ToCharArray());

		int codigo = Convert::ToInt32(datos[0]);
		int nroPisos = Convert::ToInt32(datos[1]);
		int nroDepartamentos = Convert::ToInt32(datos[2]);
		int aforo = Convert::ToInt32(datos[3]);
		double areaTotal = Convert::ToDouble(datos[4]);
		int numero = Convert::ToInt32(datos[5]);
		double areaCochera = Convert::ToInt32(datos[6]);
		int codigoUbicacion = Convert::ToInt32(datos[7]);

		DepartamentoController^ objDepartamentoController = gcnew DepartamentoController();
		List<Departamento^>^ listaDepartamentos = objDepartamentoController->buscarDepartamentosxEdificio(codigo);

		UbicacionController^ objUbicacionController = gcnew UbicacionController();
		Ubicacion^ objUbicacion = objUbicacionController->buscarUbicacionxCodigo(codigoUbicacion);

		Edificio^ objEdificio = gcnew Edificio(codigo, nroPisos, nroDepartamentos, aforo, areaTotal, numero, areaCochera, objUbicacion, listaDepartamentos);
		listaEdificiosEncontrados->Add(objEdificio);
	}
	return listaEdificiosEncontrados;
}

List<Edificio^>^ EdificioController::buscarEdificiosxNumero(String^ numeroBuscado) {
	List<Edificio^>^ listaEdificiosBuscados = gcnew List<Edificio^>();
	List<Edificio^>^ listaEdificios = buscarAll();
	for (int i = 0; i < listaEdificios->Count; i++) {
		if ((Convert::ToString(listaEdificios[i]->getNumero())->Contains(Convert::ToString(numeroBuscado))) || (numeroBuscado == "Todos")) {
			listaEdificiosBuscados->Add(listaEdificios[i]);
		}
	}
	return listaEdificiosBuscados;
}

List<Edificio^>^ EdificioController::buscarEdificiosxProyecto(int codigoProyecto) {

	/*En esta lista vamos a colocar la información de los Edificios que encontremos en el archivo de texto*/
	List<Edificio^>^ listaEdificiosEncontrados = gcnew List<Edificio^>();
	array<String^>^ lineas = File::ReadAllLines("edificios.txt");

	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	/*Esta instruccion for each nos permite ir elemento por elemento de un array*/
	for each (String ^ lineaEdificio in lineas) {
		/*Voy a separar cada elemento del String por ; con el split*/
		array<String^>^ datos = lineaEdificio->Split(separadores->ToCharArray());

		int codigo = Convert::ToInt32(datos[0]);
		int nroPisos = Convert::ToInt32(datos[1]);
		int nroEdificios = Convert::ToInt32(datos[2]);
		int aforo = Convert::ToInt32(datos[3]);
		double areaTotal = Convert::ToDouble(datos[4]);
		int numero = Convert::ToInt32(datos[5]);
		double areaCochera = Convert::ToDouble(datos[6]);
		int codigoUbicacion = Convert::ToInt32(datos[7]);

		UbicacionController^ objUbicacionController = gcnew UbicacionController();
		Ubicacion^ objUbicacion = objUbicacionController->buscarUbicacionxCodigo(codigoUbicacion);

		DepartamentoController^ objDepartamentoController = gcnew DepartamentoController();
		List<Departamento^>^ listaDepartamentos = objDepartamentoController->buscarDepartamentosxEdificio(codigo);

		if (codigo == codigoProyecto) {
			Edificio^ objEdificio = gcnew Edificio(codigo, nroPisos, nroEdificios, aforo, areaTotal, numero, areaCochera, objUbicacion, listaDepartamentos);
			listaEdificiosEncontrados->Add(objEdificio);
		}
	}
	return listaEdificiosEncontrados;
}

Edificio^ EdificioController::buscarEdificioxCodigo(int codigo) {
	List<Edificio^>^ listaEdificios = buscarAll();
	for (int i = 0; i < listaEdificios->Count; i++) {
		if (listaEdificios[i]->getCodigo() == codigo) {
			return listaEdificios[i];
		}
	}
}


void EdificioController::eliminarEdificio(int codigo) {
	List<Edificio^>^ listaEdificios = buscarAll();

	for (int i = 0; i < listaEdificios->Count; i++) {
		if (listaEdificios[i]->getCodigo() == codigo) {

			listaEdificios->RemoveAt(i);
		}
		escribirArchivo(listaEdificios);
	}
}

void EdificioController::escribirArchivo(List<Edificio^>^ listaEdificios) {/*falta implementar codigo de proyecto,se lo tiene que buscar*/
	array<String^>^ lineasArchivo = gcnew array<String^>(listaEdificios->Count);
	for (int i = 0; i < listaEdificios->Count; i++) {
		Edificio^ objEdificio = listaEdificios[i];
		lineasArchivo[i] = objEdificio->getCodigo() + ";" + objEdificio->getNroPisos() + ";" + objEdificio->getNroDepartamentos() + ";" + objEdificio->getAforo() + ";" + objEdificio->getAreaTotal() + ";" + objEdificio->getNumero() + ";" + objEdificio->getAreaCochera() + ";" + objEdificio->getUbicacion()->getCodigo();
	}
	File::WriteAllLines("edificios.txt", lineasArchivo);
}


void EdificioController::agregarEdificio(Edificio^ objEdificio) {
	List<Edificio^>^ listaEdificios = buscarAll();
	listaEdificios->Add(objEdificio);
	escribirArchivo(listaEdificios);
}

void EdificioController::agregarEdificioaProyecto(Edificio^ objEdificio, int codigoProyecto) {

	array<String^>^ lineas = File::ReadAllLines("edificios.txt");
	int cantLineas = 0;
	for each (String ^ linea in lineas) {
		cantLineas++;
	}
	array<String^>^ lineasArchivo = gcnew array<String^>(cantLineas + 1);
	int i;
	for (i = 0; i < (cantLineas); i++) {
		lineasArchivo[i] = lineas[i];
	}
	lineasArchivo[i] = objEdificio->getCodigo() + ";" + objEdificio->getNroPisos() + ";" + objEdificio->getNroDepartamentos() + ";" + objEdificio->getAforo() + ";" + objEdificio->getAreaTotal() + ";" + objEdificio->getNumero() + ";" + objEdificio->getAreaCochera() + ";" + objEdificio->getCodigo() + ";" + codigoProyecto;
	File::WriteAllLines("edificios.txt", lineasArchivo);
}


void EdificioController::actualizarEdificio(Edificio^ objEdificio) {
	List<Edificio^>^ listaEdificios = buscarAll();

	for (int i = 0; i < listaEdificios->Count; i++) {

		if (listaEdificios[i]->getCodigo() == objEdificio->getCodigo()) {

			listaEdificios[i]->setCodigo(objEdificio->getCodigo());
			listaEdificios[i]->setNroPisos(objEdificio->getNroPisos());
			listaEdificios[i]->setNroDepartamentos(objEdificio->getNroDepartamentos());
			listaEdificios[i]->setAforo(objEdificio->getAforo());
			listaEdificios[i]->setAreaTotal(objEdificio->getAreaTotal());
			listaEdificios[i]->setNumero(objEdificio->getNumero());
			listaEdificios[i]->setAreaCochera(objEdificio->getAreaCochera());
			listaEdificios[i]->setUbicacion(objEdificio->getUbicacion());

			break;
		}
	}
	escribirArchivo(listaEdificios);
}


List<String^>^ EdificioController::obtenerNumeros() {
	List<Edificio^>^ listaEdificios = buscarAll();
	List<String^>^ listaNumeros = gcnew List<String^>();

	for (int i = 0; i < listaEdificios->Count; i++) {

		String^ numero = Convert::ToString(listaEdificios[i]->getNumero());

		int existe = 0;
		for (int j = 0; j < listaNumeros->Count; j++) {

			if (listaNumeros[j] == numero) {
				existe = 1;
			}
		}
		if (existe == 0) {
			listaNumeros->Add(numero);
		}
		listaNumeros->Add("Todos");
	}
	return listaNumeros;
}