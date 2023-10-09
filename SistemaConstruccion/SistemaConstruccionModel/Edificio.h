#pragma once
#include "Departamento.h"
#include "Ubicacion.h"

using namespace System::Collections::Generic;

namespace SistemaConstruccionModel {

	public ref class Edificio {
	private:
		int codigo;
		int nroPisos;
		int nroDepartamentos;
		int aforo;
		double areaTotal;
		int numero;
		double areaCochera;
		Ubicacion^ objUbicacion;
		List<Departamento^>^ listaDepartamentos;

	public:
		Edificio();
		Edificio(int codigo, int nroPisos, int nroDepartamentos, int aforo, double areaTotal, int numero, double areaCochera, Ubicacion^ objUbicacion, List<Departamento^>^ listaDepartamentos);

		int getCodigo();
		void setCodigo(int codigo);

		int getNroPisos();
		void setNroPisos(int nroPisos);

		int getNroDepartamentos();
		void setNroDepartamentos(int nroDepartamentos);

		int getAforo();
		void setAforo(int aforo);

		double getAreaTotal();
		void setAreaTotal(double areaTotal);

		int getNumero();
		void setNumero(int numero);

		double getAreaCochera();
		void setAreaCochera(double areaCocehra);

		Ubicacion^ getUbicacion();
		void setUbicacion(Ubicacion^ objUbicacion);

		List<Departamento^>^ getListaDepartamentos();
		void setListaDepartamentos(List<Departamento^>^ listaDepartamentos);
		
	};
}