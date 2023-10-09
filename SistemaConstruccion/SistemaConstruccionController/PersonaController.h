#pragma once
//#include "CronogramaController.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace SistemaConstruccionModel;

namespace SistemaConstruccionController {

	public ref class PersonaController {
	public:
		PersonaController();

		/*Estos métodos siempre deberían estar porque te sirven de mucho*/

		List<Persona^>^ buscarAll();
		Persona^ buscarPersonaxCodigo(int codigo);
		Persona^ buscarPersonaxDNI(String^ dni);

		void escribirArchivo(List<Persona^>^ listaPersonas);

		void eliminarPersona(int codigo);

		void agregarPersona(Persona^ objPersona);
		
		void actualizarPersona(Persona^ objPersona);

		List<String^>^ obtenerDNIs();

	};


}
