#pragma once
#include "Edificio.h"
#include "Cronograma.h"

using namespace System; //Esto es para la clase String
using namespace System::Collections::Generic;

namespace SistemaConstruccionModel {

	public ref class Proyecto {

	private:
		int codigo;
		String^ fechaInicio;
		String^ fechaEntrega;
		String^ departamento;
		String^ provincia;
		String^ distrito;
		int nroEdificios;
		String^ nombre;
		float presupuesto;
		Cronograma^ objCronograma;
		List<Edificio^>^ listaEdificios;


		//Siempre hay 2 constructores, uno vacio y otro con todo ojo O_O
	public:
		Proyecto();
		Proyecto(int codigo, String^ fechaInicio, String^ fechaEntrega, String^ departamento, String^ provincia, String^ distrito, int nroEdificios, String^ nombre, float presupuesto, Cronograma^ objCronograma, List<Edificio^>^ listaEdificios);

		int getCodigo();
		void setCodigo(int codigo);

		String^ getFechaInicio();
		void setFechaInicio(String^ fechaInicio);

		String^ getFechaEntrega();
		void setFechaEntrega(String^ fechaEntrega);

		String^ getDepartamento();
		void setDepartamento(String^ departamento);

		String^ getProvincia();
		void setProvincia(String^ provincia);

		String^ getDistrito();
		void setDistrito(String^ distrito);

		int getNroEdificios();
		void setNroEdificios(int nroEdificios);

		String^ getNombre();
		void setNombre(String^ nombre);

		float getPresupuesto();
		void setPresupuesto(float presupuesto);

		Cronograma^ getCronograma();
		void setCronograma(Cronograma^ objCronograma);

		List<Edificio^>^ getListaEdificios();
		void setListaEdificios(List<Edificio^>^ listaEdificios);

	};

}