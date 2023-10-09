#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SistemaConstruccionModel;

namespace SistemaConstruccionController {

	public ref class CronogramaController {
	public:
		CronogramaController();


		/*Estos métodos siempre deberían estar porque te sirven de mucho*/

		List<Cronograma^>^ buscarAll();
		List<Cronograma^>^ buscarCronogramasxEstado(String^ estadoBuscado);
		Cronograma^ buscarCronogramaxCodigo(int codigo);


		void escribirArchivo(List<Cronograma^>^ listaCronogramas);
		void eliminarCronograma(int codigo);
		void agregarCronograma(Cronograma^ objCronograma);


		void actualizarCronograma(Cronograma^ objCronograma);

		List<String^>^ obtenerEstados();

	};

}