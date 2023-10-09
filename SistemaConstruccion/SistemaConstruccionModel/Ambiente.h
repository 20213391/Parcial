#pragma once

using namespace System;

namespace SistemaConstruccionModel {
	public ref class Ambiente {
		/*Primero definimos los atributos*/
	private:
		int codigo;
		double largo;
		double ancho;
		String^ tipo;
		int cantGrifos;
		int cantTomaCorrientes;

		/*Ahora los metodos*/
	public:
		Ambiente();
		Ambiente(int codigo, double largo, double ancho, String^ tipo, int cantGrifos, int cantTomaCorrientes);

		int getCodigo();
		void setCodigo(int codigo);

		double getLargo();
		void setLargo(double largo);

		double getAncho();
		void setAncho(double ancho);

		String^ getTipo();
		void setTipo(String^ tipo);

		int getCantGrifos();
		void setCantGrifos(int cantGrifos);

		int getCantTomaCorrientes();
		void setCantTomaCorrientes(int cantTomacorrientes);
	};
}

