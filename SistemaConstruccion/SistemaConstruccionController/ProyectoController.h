#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SistemaConstruccionModel;

namespace SistemaConstruccionController{

	public ref class ProyectoController {
		public:
			ProyectoController();

			List<Proyecto^>^ buscarProyectosxDpto(String^ departamento);
			Proyecto^ buscarProyectoxCodigo(int codigo);
			List<Proyecto^>^ buscarAll();


			/*Estos métodos siempre deberían estar porque te sirven de mucho*/

			void escribirArchivo(List<Proyecto^>^ listaProyectos);

			void eliminarProyecto(int codigo);

			void agregarProyecto(Proyecto^ objProyecto);



			void actualizarProyecto(Proyecto^ objProyecto);

			List<String^>^ obtenerDepartamentos();

	};


}
