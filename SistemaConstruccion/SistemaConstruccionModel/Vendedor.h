#pragma once
#include "Persona.h"

namespace SistemaConstruccionModel {

	public ref class Vendedor : Persona {
	private:
		double sueldo;
		String^ categoria;

	public:
		Vendedor();
		Vendedor(int codigo, String^ nombres, String^ apellidoPaterno, String^ apellidoMaterno, String^ dni, double sueldo, String^ categoria);

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

		double getSueldo();
		void setSueldo(double sueldo);

		String^ getCategoria();
		void setCategoria(String^ categoria);
	};

}