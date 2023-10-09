#include "UbicacionController.h"

using namespace SistemaConstruccionController;
using namespace System::IO;
using namespace System;

UbicacionController::UbicacionController() {

}

List<Ubicacion^>^ UbicacionController::buscarAll() {
	/*En esta lista vamos a colocar la información de los proyectos que encontremos en el archivo de texto*/
	List<Ubicacion^>^ listaEncontrados = gcnew List<Ubicacion^>();
	array<String^>^ lineas = File::ReadAllLines("ubicaciones.txt");

	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	/*Esta instruccion for each nos permite ir elemento por elemento de un array*/
	for each (String ^ linea in lineas) {
		/*Voy a separar cada elemento del String por ; con el split*/
		array<String^>^ datos = linea->Split(separadores->ToCharArray());
		int codigo = Convert::ToInt32(datos[0]);
		double latitud = Convert::ToDouble(datos[1]);
		double longitud = Convert::ToDouble(datos[2]);

		Ubicacion^ obj = gcnew Ubicacion(codigo, latitud, longitud);
		listaEncontrados->Add(obj);
	}
	return listaEncontrados;
}

Ubicacion^ UbicacionController::buscarUbicacionxCodigo(int codigo) {
	List<Ubicacion^>^ listaUbicaciones = buscarAll();

	for (int i = 0; i < listaUbicaciones->Count; i++) {

		if (listaUbicaciones[i]->getCodigo() == codigo) {

			return listaUbicaciones[i];
		}
	}
}

void UbicacionController::escribirArchivo(List<Ubicacion^>^ lista) {
	array<String^>^ lineasArchivo = gcnew array<String^>(lista->Count);
	for (int i = 0; i < lista->Count; i++) {
		Ubicacion^ objeto = lista[i];
		lineasArchivo[i] = objeto->getCodigo() + ";" + objeto->getLatitud() + ";" + objeto->getLongitud();
	}
	File::WriteAllLines("ubicaciones.txt", lineasArchivo);
}

void UbicacionController::agregarUbicacion(Ubicacion^ objUbicacion) {
	List<Ubicacion^>^ listaUbicaciones = buscarAll();
	listaUbicaciones->Add(objUbicacion);
	escribirArchivo(listaUbicaciones);
}