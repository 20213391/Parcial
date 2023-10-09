#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SistemaConstruccionModel;

namespace SistemaConstruccionController {

	public ref class TareaController {

	public:

		TareaController();

		List<Tarea^>^ buscarTareasxResponsable(String^ responsableBuscado);
		List<Tarea^>^ buscarAll();
		List<Tarea^>^ buscarTareasxEtapa(int codigoEtapa);
		Tarea^ buscarTareaxCodigo(int codigo);

		void eliminarTarea(int codigo);

		void editarTarea(Tarea^ objTarea);

		void agregarTareaxEtapa(Tarea^ objTarea, int codigoEtapa);
		void agregarTarea(Tarea^ objTarea);

		void escribirArchivo(List<Tarea^>^ listaEdificios);

		List<String^>^ obtenerResponsables();
	};
}