#pragma once
#include "Persona.h"

using namespace System;

namespace SistemaConstruccionModel {

	//Para representar la herencia se hace a traves de los : (dos puntos)
	public ref class Cliente : Persona {

	private:
		String^ fechaNacimiento;

	public:
		Cliente();
		Cliente(int codigo, String^ nombres, String^ apellidoPaterno, String^ apellidoMaterno, String^ dni, String^ fechaNacimiento);

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

		String^ getFechaNacimiento();
		void setFechaNacimiento(String^ fechaNacimiento);
	};

} 