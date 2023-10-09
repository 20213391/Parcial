#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SistemaConstruccionModel;

namespace SistemaConstruccionController {

	public ref class AmbienteController {

	public:

		AmbienteController();

		List<Ambiente^>^ buscarAmbientesxTipo(String^ tipoBuscado);
		List<Ambiente^>^ buscarAll();
		List<Ambiente^>^ buscarAmbientesxDepartamento(int codigoDepartamento);
		Ambiente^ buscarAmbientexCodigo(int codigo);

		void eliminarAmbiente(int codigo);

		void editarAmbiente(Ambiente^ objAmbiente);

		void agregarAmbientexDepartamento(Ambiente^ objAmbiente, int codigoDepartamento);
		void agregarAmbiente(Ambiente^ objAmbiente);

		void escribirArchivo(List<Ambiente^>^ listaEdificios);
		
		List<String^>^ obtenerTipos();
	};
}