#pragma once

namespace SistemaConstruccionModel {

	public ref class Ubicacion {
	private:
		int codigo;
		double latitud;
		double longitud;

	public:
		Ubicacion();
		Ubicacion(int codigo, double latitud, double longitud);

		int getCodigo();
		void setCodigo(int codigo);

		double getLatitud();
		void setLatitud(double latitud);

		double getLongitud();
		void setLongitud(double longitud);

	};

}