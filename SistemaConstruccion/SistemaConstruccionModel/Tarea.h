#pragma once

using namespace System;

namespace SistemaConstruccionModel {

	public ref class Tarea {

	private:
		int codigo;
		String^ fechaInicio;
		String^ fechaFin;
		String^ nombre;
		float avance;
		String^ responsable;

	public:
		Tarea();
		Tarea(int codigo, String^ fechaInicio, String^ fechaFin, String^ nombre, float avance, String^ responsable);

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

		String^ getResponsable();
		void setResponsable(String^ responsable);
	};

}

