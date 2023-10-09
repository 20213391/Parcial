
#include "EtapaController.h"
#include "TareaController.h"

using namespace SistemaConstruccionController;
using namespace System::IO;

EtapaController::EtapaController() {

}

List<Etapa^>^ EtapaController::buscarAll() {
	/*En esta lista vamos a colocar la información de los Etapas que encontremos en el archivo de texto*/
	List<Etapa^>^ listaEtapasEncontrados = gcnew List<Etapa^>();
	array<String^>^ lineas = File::ReadAllLines("etapas.txt");

	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	/*Esta instruccion for each nos permite ir elemento por elemento de un array*/
	for each (String ^ lineaEtapa in lineas) {
		/*Voy a separar cada elemento del String por ; con el split*/
		array<String^>^ datos = lineaEtapa->Split(separadores->ToCharArray());

		int codigo = Convert::ToInt32(datos[0]);
		String^ fechaInicio = datos[1];
		String^ fechaFin = datos[2];
		String^ nombre = datos[3];
		float avance = Convert::ToDouble(datos[4]);

		TareaController^ objTareaController = gcnew TareaController();
		List<Tarea^>^ listaTareas = objTareaController->buscarTareasxEtapa(codigo);

		Etapa^ objEtapa = gcnew Etapa(codigo, fechaInicio, fechaFin, nombre, avance, listaTareas);
		listaEtapasEncontrados->Add(objEtapa);
	}
	return listaEtapasEncontrados;
}

List<Etapa^>^ EtapaController::buscarEtapasxCronograma(int codigoCronograma) {

	/*En esta lista vamos a colocar la información de los Etapas que encontremos en el archivo de texto*/
	List<Etapa^>^ listaEtapasEncontradas = gcnew List<Etapa^>();
	array<String^>^ lineas = File::ReadAllLines("etapas.txt");

	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	/*Esta instruccion for each nos permite ir elemento por elemento de un array*/
	for each (String ^ lineaEtapa in lineas) {
		/*Voy a separar cada elemento del String por ; con el split*/
		array<String^>^ datos = lineaEtapa->Split(separadores->ToCharArray());

		int codigo = Convert::ToInt32(datos[0]);
		String^ fechaInicio = datos[1];
		String^ fechaFin = datos[2];
		String^ nombre = datos[3];
		float avance = Convert::ToDouble(datos[4]);

		TareaController^ objTareaController = gcnew TareaController();
		List<Tarea^>^ listaTareas = objTareaController->buscarTareasxEtapa(codigo);

		if (codigo == codigoCronograma) {
			Etapa^ objEtapa = gcnew Etapa(codigo, fechaInicio, fechaFin, nombre, avance, listaTareas);
			listaEtapasEncontradas->Add(objEtapa);
		}
	}
	return listaEtapasEncontradas;
}

Etapa^ EtapaController::buscarEtapaxCodigo(int codigo) {
	List<Etapa^>^ listaEtapas = buscarAll();
	for (int i = 0; i < listaEtapas->Count; i++) {
		if (listaEtapas[i]->getCodigo() == codigo) {
			return listaEtapas[i];
		}
	}
}


void EtapaController::eliminarEtapa(int codigo) {
	List<Etapa^>^ listaEtapas = buscarAll();

	for (int i = 0; i < listaEtapas->Count; i++) {
		if (listaEtapas[i]->getCodigo() == codigo) {

			listaEtapas->RemoveAt(i);
		}
		escribirArchivo(listaEtapas);
	}
}


void EtapaController::escribirArchivo(List<Etapa^>^ listaEtapas) {
	array<String^>^ lineasArchivo = gcnew array<String^>(listaEtapas->Count);
	for (int i = 0; i < listaEtapas->Count; i++) {
		Etapa^ objEtapa = listaEtapas[i];
		lineasArchivo[i] = objEtapa->getCodigo() + ";" + objEtapa->getFechaInicio() + ";" + objEtapa->getFechaFin() + ";" + objEtapa->getNombre() + ";" + objEtapa->getAvance();
	}
	File::WriteAllLines("etapas.txt", lineasArchivo);
}


void EtapaController::agregarEtapa(Etapa^ objEtapa) {
	List<Etapa^>^ listaEtapas = buscarAll();
	listaEtapas->Add(objEtapa);
	escribirArchivo(listaEtapas);
}

void EtapaController::agregarEtapaaCronograma(Etapa^ objEtapa, int codigoCronograma) {

	array<String^>^ lineas = File::ReadAllLines("etapas.txt");
	int cantLineas = 0;
	for each (String ^ linea in lineas) {
		cantLineas++;
	}
	array<String^>^ lineasArchivo = gcnew array<String^>(cantLineas + 1);
	int i;
	for (i = 0; i < (cantLineas); i++) {
		lineasArchivo[i] = lineas[i];
	}
	lineasArchivo[i] = objEtapa->getCodigo() + ";" + objEtapa->getFechaInicio() + ";" + objEtapa->getFechaFin() + ";" + objEtapa->getNombre() + ";" + objEtapa->getAvance() + ";" + codigoCronograma;
	File::WriteAllLines("etapas.txt", lineasArchivo);
}


void EtapaController::actualizarEtapa(Etapa^ objEtapa) {
	List<Etapa^>^ listaEtapas = buscarAll();

	for (int i = 0; i < listaEtapas->Count; i++) {

		if (listaEtapas[i]->getCodigo() == objEtapa->getCodigo()) {

			listaEtapas[i]->setCodigo(objEtapa->getCodigo());
			listaEtapas[i]->setFechaInicio(objEtapa->getFechaInicio());
			listaEtapas[i]->setFechaFin(objEtapa->getFechaFin());
			listaEtapas[i]->setNombre(objEtapa->getNombre());
			listaEtapas[i]->setAvance(objEtapa->getAvance());

			break;
		}
	}
	escribirArchivo(listaEtapas);
}

