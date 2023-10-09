#pragma once
#include "Tarea.h"

using namespace System;
using namespace System::Collections::Generic;

namespace SistemaConstruccionModel {

	public ref class Etapa {

	private:
		int codigo;
		String^ fechaInicio;
		String^ fechaFin;
		String^ nombre;
		float avance;
		List<Tarea^>^ listaTareas;

	public:
		Etapa();
		Etapa(int codigo, String^ fechaInicio, String^ fechaFin, String^ nombre, float avance, List<Tarea^>^ listaTareas);

		int getCodigo();
		void setCodigo(int codigo);

		String^ getFechaInicio();
		void setFechaInicio(String^ fechaInicio);

		String^ getFechaFin();
		void setFechaFin(String^ fechaFin);

		String^ getNombre();
		void setNombre(String^ estado);

		float getAvance();
		void setAvance(float avance);

		List<Tarea^>^ getListaTareas();
		void setListaTareas(List<Tarea^>^ listaTareas);

	};

}

