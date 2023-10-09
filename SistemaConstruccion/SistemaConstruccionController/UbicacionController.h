#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SistemaConstruccionModel;

namespace SistemaConstruccionController {

	public ref class UbicacionController {
	public:
		UbicacionController();
		List<Ubicacion^>^ buscarAll();
		Ubicacion^ buscarUbicacionxCodigo(int codigo);

		void escribirArchivo(List<Ubicacion^>^ lista);

		void agregarUbicacion(Ubicacion^ objUbicacion);
	};
}
