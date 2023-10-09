#include <iostream>
#include "CronogramaController.h"
#include "EtapaController.h"

using namespace SistemaConstruccionController;
using namespace System::IO; /*Este espacio de nombres sirve para manejar los archivos de texto*/


CronogramaController::CronogramaController() {

}


/*Estos métodos siempre deberían estar porque te sirven de mucho*/

List<Cronograma^>^ CronogramaController::buscarAll() {
	/*En esta lista vamos a colocar la información de los cronogramas que encontremos en el archivo de texto*/
	List<Cronograma^>^ listaCronogramasEncontrados = gcnew List<Cronograma^>();
	array<String^>^ lineas = File::ReadAllLines("cronograma.txt");
	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	for each (String ^ lineaCronograma in lineas) {
		array<String^>^ datos = lineaCronograma->Split(separadores->ToCharArray());
		int codigo = Convert::ToInt32(datos[0]);
		String^ fechaInicio = datos[1];
		String^ fechaFin = datos[2];
		String^ estado = datos[3];

		EtapaController^ objEtapaController = gcnew EtapaController();
		List<Etapa^>^ listaEtapas = objEtapaController->buscarEtapasxCronograma(codigo);


		Cronograma^ objCronograma = gcnew Cronograma(codigo, fechaInicio, fechaFin, estado, listaEtapas);
		listaCronogramasEncontrados->Add(objCronograma);
	}
	return listaCronogramasEncontrados;
}

List<Cronograma^>^ CronogramaController::buscarCronogramasxEstado(String^ estadoBuscado) {
	List<Cronograma^>^ listaCronogramasBuscados = gcnew List<Cronograma^>();
	List<Cronograma^>^ listaCronogramas = buscarAll();
	for (int i = 0; i < listaCronogramas->Count; i++) {
		if ((listaCronogramas[i]->getEstado() == estadoBuscado) || (estadoBuscado == "Todos")) {
			listaCronogramasBuscados->Add(listaCronogramas[i]);
		}
	}
	return listaCronogramasBuscados;
}

Cronograma^ CronogramaController::buscarCronogramaxCodigo(int codigo) {
	List<Cronograma^>^ listaCronogramas = buscarAll();
	for (int i = 0; i < listaCronogramas->Count; i++) {
		if (listaCronogramas[i]->getCodigo() == codigo) {
			return listaCronogramas[i];
		}
	}
}


void CronogramaController::escribirArchivo(List<Cronograma^>^ listaCronogramas) {

}

void CronogramaController::eliminarCronograma(int codigo) {

}

void CronogramaController::agregarCronograma(Cronograma^ objCronograma) {

}


void CronogramaController::actualizarCronograma(Cronograma^ objCronograma) {
	List<Cronograma^>^ listaCronogramas = buscarAll();

	for (int i = 0; i < listaCronogramas->Count; i++) {

		if (listaCronogramas[i]->getCodigo() == objCronograma->getCodigo()) {

			listaCronogramas[i]->setCodigo(objCronograma->getCodigo());
			listaCronogramas[i]->setFechaInicio(objCronograma->getFechaInicio());
			listaCronogramas[i]->setFechaFin(objCronograma->getFechaFin());
			listaCronogramas[i]->setEstado(objCronograma->getEstado());

			break;
		}
	}
	escribirArchivo(listaCronogramas);
}


List<String^>^ CronogramaController::obtenerEstados() {
	List<Cronograma^>^ listaCronogramas = buscarAll();
	List<String^>^ listaEstados = gcnew List<String^>();

	for (int i = 0; i < listaCronogramas->Count; i++) {

		String^ estado = Convert::ToString(listaCronogramas[i]->getEstado());

		int existe = 0;
		for (int j = 0; j < listaEstados->Count; j++) {

			if (listaEstados[j] == estado) {
				existe = 1;
			}
		}
		if (existe == 0) {
			listaEstados->Add(estado);
		}
		listaEstados->Add("Todos");
	}
	return listaEstados;
}