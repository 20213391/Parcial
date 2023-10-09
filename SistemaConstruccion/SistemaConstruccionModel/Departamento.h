#pragma once
#include "Ambiente.h"
#include "Cliente.h"
#include "Vendedor.h"

using namespace System;
using namespace System::Collections::Generic;

namespace SistemaConstruccionModel {

	public ref class Departamento {

	private:
		int codigo;
		int nroAmbientes;
		double area;
		int piso;
		double precio;
		String^ tipo;
		double ancho;
		double largo;
		double alto;
		Cliente^ objCliente;
		Vendedor^ objVendedor;
		List<Ambiente^>^ listaAmbientes; //Asi se representa la composicion o agreagacion

	public:
		Departamento();
		Departamento(int codigo, int nroAmbientes, double area, int piso, double precio, String^ tipo, double ancho, double largo, double alto, Cliente^ objCliente, Vendedor^ objVendedor, List<Ambiente^>^ listaAmbientes);

		int getCodigo();
		void setCodigo(int codigo);

		int getNroAmbientes();
		void setNroAmbientes(int nroAmbientes);

		double getArea();
		void setArea(double area);

		int getPiso();
		void setPiso(int piso);

		double getPrecio();
		void setPrecio(double precio);

		String^ getTipo();
		void setTipo(String^ tipo);

		double getAncho();
		void setAncho(double ancho);

		double getLargo();
		void setLargo(double largo);

		double getAlto();
		void setAlto(double alto);

		Cliente^ getCliente();
		void setCliente(Cliente^ objCliente);

		Vendedor^ getVendedor();
		void setVendedor(Vendedor^ objVendedor);

	};
}