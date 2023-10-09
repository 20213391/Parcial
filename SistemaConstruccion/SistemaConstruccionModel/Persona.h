#pragma once

using namespace System;

namespace SistemaConstruccionModel {

	public ref class Persona {
	protected: //Esto es por la herencia
		int codigo;
		String^ nombres;
		String^ apellidoPaterno;
		String^ apellidoMaterno;
		String^ dni;

	public:
		Persona();
		Persona(int codigo, String^ nombres, String^ apellidoPaterno, String^ apellidoMaterno, String^ dni);

		int getCodigo();
		void setCodigo(int codigo);

		String^ getNombres();
		void setNombres(String^ nombres);
			
		String^ getApellidoPaterno();
		void setApellidoPaterno(String^ apellidoPaterno);
			
		String^ getApellidoMaterno();
		void setApellidoMaterno(String^ apellidoMaterno);
			
		String^ getDNI();
		void setDNI(String^ dni);

	};

} 