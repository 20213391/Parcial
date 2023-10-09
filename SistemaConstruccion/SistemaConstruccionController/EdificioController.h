#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SistemaConstruccionModel;

namespace SistemaConstruccionController {

	public ref class EdificioController {
	public:
		EdificioController();

		List<Edificio^>^ buscarEdificiosxNumero(String^ numeroBuscado);
		List<Edificio^>^ buscarEdificiosxProyecto(int codigoProyecto);
		List<Edificio^>^ buscarAll();
		Edificio^ buscarEdificioxCodigo(int codigo);

		void eliminarEdificio(int codigo);

		void escribirArchivo(List<Edificio^>^ listaEdificios);
		
		void agregarEdificio(Edificio^ objEdificio);
		void agregarEdificioaProyecto(Edificio^ objEdificio, int codigoProyecto);

		void actualizarEdificio(Edificio^ objEdificio);

		List<String^>^ obtenerNumeros();

	};
}