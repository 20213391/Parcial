#pragma once
#include "Etapa.h"

using namespace System;

namespace SistemaConstruccionModel {

	public ref class Cronograma {

		private:

			int codigo;
			String^ fechaInicio;
			String^ fechaFin;
			String^ estado;
			List<Etapa^>^ listaEtapas;

		public:

			Cronograma();
			Cronograma(int codigo, String^ fechaInicio, String^ fechaFin, String^ estado, List<Etapa^>^ listaEtapas);

			int getCodigo();
			void setCodigo(int codigo);

			String^ getFechaInicio();
			void setFechaInicio(String^ fechaInicio);

			String^ getFechaFin();
			void setFechaFin(String^ fechaFin);

			String^ getEstado();
			void setEstado(String^ estado);


	};
}