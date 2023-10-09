#pragma once
//#include "CronogramaController.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace SistemaConstruccionModel;

namespace SistemaConstruccionController {

	public ref class ClienteController {
	public:
		ClienteController();

		/*Estos métodos siempre deberían estar porque te sirven de mucho*/

		List<Cliente^>^ buscarAll();
		Cliente^ buscarClientexCodigo(int codigo);
		Cliente^ buscarClientexDNI(String^ dni);


		void escribirArchivo(List<Cliente^>^ listaClientes);

		void eliminarCliente(int codigo);

		void agregarCliente(Cliente^ objCliente);

		void actualizarCliente(Cliente^ objCliente);

		List<String^>^ obtenerDNIs();

	};


}
