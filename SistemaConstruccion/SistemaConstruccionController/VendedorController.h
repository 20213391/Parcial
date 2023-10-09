#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SistemaConstruccionModel;

namespace SistemaConstruccionController {

	public ref class VendedorController {
	public:
		VendedorController();

		/*Estos métodos siempre deberían estar porque te sirven de mucho*/
		List<Vendedor^>^ buscarAll();
		Vendedor^ buscarVendedorxCodigo(int codigo);
		Vendedor^ buscarVendedorxDNI(String^ dni);

		void escribirArchivo(List<Vendedor^>^ listaVendedors);

		void eliminarVendedor(int codigo);

		void agregarVendedor(Vendedor^ objVendedor);

		void actualizarVendedor(Vendedor^ objVendedor);

		List<String^>^ obtenerDNIs();

	};


}
