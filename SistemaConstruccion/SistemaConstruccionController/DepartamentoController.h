#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SistemaConstruccionModel;

namespace SistemaConstruccionController {

	public ref class DepartamentoController {
	public:
		DepartamentoController();

		List<Departamento^>^ buscarDepartamentosxTipo(String^ tipoBuscado);
		Departamento^ buscarDepartamentoxCodigo(int codigo);
		List<Departamento^>^ buscarDepartamentosxEdificio(int codigoEdificio);
		List<Departamento^>^ buscarAll();

		void eliminarDepartamento(int codigo);

		void escribirArchivo(List<Departamento^>^ listaDepartamentos);

		void agregarDepartamento(Departamento^ objDepartamento);
		void agregarDepartamentoaEdificio(Departamento^ objDepartamento, int codigoEdificio);

		void actualizarDepartamento(Departamento^ objDepartamento);

		List<String^>^ obtenerTipos();

	};


}
#pragma once
