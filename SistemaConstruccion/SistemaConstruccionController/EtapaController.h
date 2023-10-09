#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SistemaConstruccionModel;

namespace SistemaConstruccionController {

	public ref class EtapaController {
	public:
		EtapaController();

		List<Etapa^>^ buscarAll();
		List<Etapa^>^ buscarEtapasxCronograma(int codigoCronograma);
		Etapa^ buscarEtapaxCodigo(int codigo);

		void eliminarEtapa(int codigo);

		void escribirArchivo(List<Etapa^>^ listaEtapas);

		void agregarEtapa(Etapa^ objEtapa);
		void agregarEtapaaCronograma(Etapa^ objEtapa, int codigoCronograma);

		void actualizarEtapa(Etapa^ objEtapa);

	};
}