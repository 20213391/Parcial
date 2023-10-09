#include <iostream>
#include "DepartamentoController.h"
#include "ClienteController.h"
#include "VendedorController.h"
#include "AmbienteController.h"

using namespace SistemaConstruccionController;
using namespace System::IO; /*Este espacio de nombres sirve para manejar los archivos de texto*/

DepartamentoController::DepartamentoController() {

}

Departamento^ DepartamentoController::buscarDepartamentoxCodigo(int codigo) {
	List<Departamento^>^ listaDepartamentos = buscarAll();
	for (int i = 0; i < listaDepartamentos->Count; i++) {
		if (listaDepartamentos[i]->getCodigo() == codigo) {
			return listaDepartamentos[i];
		}
	}
}

List<Departamento^>^ DepartamentoController::buscarDepartamentosxTipo(String^ tipoBuscado) {
	List<Departamento^>^ listaDepartamentosBuscados = gcnew List<Departamento^>();
	List<Departamento^>^ listaDepartamentos = buscarAll();
	for (int i = 0; i < listaDepartamentos->Count; i++) {
		if ((listaDepartamentos[i]->getTipo()->Contains(tipoBuscado)) || (tipoBuscado == "Todos")) {
			listaDepartamentosBuscados->Add(listaDepartamentos[i]);
		}
	}
	return listaDepartamentosBuscados;
}

List<Departamento^>^ DepartamentoController::buscarDepartamentosxEdificio(int codigoEdificio) {

	List<Departamento^>^ listaDepartamentos = gcnew List<Departamento^>();
	array<String^>^ lineas = File::ReadAllLines("Departamentos.txt");
	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	for each (String ^ lineaDepartamento in lineas) {
		array<String^>^ datos = lineaDepartamento->Split(separadores->ToCharArray());
		int codigoDepartamento = Convert::ToInt32(datos[0]);
		int nroAmbientes = Convert::ToInt32(datos[1]);
		double area = Convert::ToDouble(datos[3]);
		int piso = Convert::ToInt32(datos[4]);
		double precio = Convert::ToDouble(datos[5]);
		String^ tipo = datos[6];
		double ancho = Convert::ToDouble(datos[7]);
		double largo = Convert::ToDouble(datos[8]);
		double alto = Convert::ToDouble(datos[9]);

		int codigoCliente = Convert::ToInt32(datos[10]);
		int codigoVendedor = Convert::ToInt32(datos[11]);
		int codigoDepartamentoEdificio = Convert::ToInt32(datos[12]);

		if (codigoDepartamentoEdificio == codigoEdificio) {

			AmbienteController^ objAmbienteController = gcnew AmbienteController();
			List<Ambiente^>^ listaAmbientes = objAmbienteController->buscarAmbientesxDepartamento(codigoDepartamento);

			ClienteController^ objClienteController = gcnew ClienteController();
			Cliente^ objCliente = objClienteController->buscarClientexCodigo(codigoCliente);

			VendedorController^ objVendedorController = gcnew VendedorController();
			Vendedor^ objVendedor = objVendedorController->buscarVendedorxCodigo(codigoVendedor);

			Departamento^ objDepartamento = gcnew Departamento(codigoDepartamento, nroAmbientes, area, piso, precio, tipo, ancho, largo, alto, objCliente, objVendedor, listaAmbientes);
			listaDepartamentos->Add(objDepartamento);
		}
	}
	return listaDepartamentos;
}

List<Departamento^>^ DepartamentoController::buscarAll() {
	/*En esta lista vamos a colocar la información de los Departamentos que encontremos en el archivo de texto*/
	List<Departamento^>^ listaDepartamentosEncontrados = gcnew List<Departamento^>();
	array<String^>^ lineas = File::ReadAllLines("Departamentos.txt");

	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	/*Esta instruccion for each nos permite ir elemento por elemento de un array*/
	for each (String ^ lineaDepartamento in lineas) {
		/*Voy a separar cada elemento del String por ; con el split*/
		array<String^>^ datos = lineaDepartamento->Split(separadores->ToCharArray());

		int codigo = Convert::ToInt32(datos[0]);
		int nroAmbientes = Convert::ToInt32(datos[1]);
		double area = Convert::ToDouble(datos[3]);
		int piso = Convert::ToInt32(datos[4]);
		double precio = Convert::ToDouble(datos[5]);
		String^ tipo = datos[6];
		double ancho = Convert::ToDouble(datos[7]);
		double largo = Convert::ToDouble(datos[8]);
		double alto = Convert::ToDouble(datos[9]);

		int codigoCliente = Convert::ToInt32(datos[10]);
		int codigoVendedor = Convert::ToInt32(datos[11]);
		

		AmbienteController^ objAmbienteController = gcnew AmbienteController();
		List<Ambiente^>^ listaAmbientes = objAmbienteController->buscarAmbientesxDepartamento(codigo);

		ClienteController^ objClienteController = gcnew ClienteController();
		Cliente^ objCliente = objClienteController->buscarClientexCodigo(codigoCliente);

		VendedorController^ objVendedorController = gcnew VendedorController();
		Vendedor^ objVendedor = objVendedorController->buscarVendedorxCodigo(codigoVendedor);

		Departamento^ objDepartamento = gcnew Departamento(codigo, nroAmbientes, area, piso, precio, tipo, ancho, largo, alto, objCliente, objVendedor, listaAmbientes);
		listaDepartamentosEncontrados->Add(objDepartamento);
	}
	return listaDepartamentosEncontrados;
}

void DepartamentoController::escribirArchivo(List<Departamento^>^ lista) {
	array<String^>^ lineasArchivo = gcnew array<String^>(lista->Count);
	for (int i = 0; i < lista->Count; i++) {
		Departamento^ objeto = lista[i];
		lineasArchivo[i] = objeto->getCodigo() + ";" + objeto->getNroAmbientes() + ";" + objeto->getArea() + ";" + objeto->getPiso() + ";" + objeto->getPrecio() + ";" + objeto->getTipo() + ";" + objeto->getAncho() + ";" + objeto->getLargo() + ";" + objeto->getAlto() + ";" + objeto->getCliente()->getCodigo() + ";" + objeto->getVendedor()->getCodigo();
	}
	File::WriteAllLines("departamentos.txt", lineasArchivo);
}

void DepartamentoController::eliminarDepartamento(int codigo) {
	List<Departamento^>^ listaDepartamentos = buscarAll();
	for (int i = 0; i < listaDepartamentos->Count; i++) {
		/*encontr[*/
		if (listaDepartamentos[i]->getCodigo() == codigo) {
			listaDepartamentos->RemoveAt(i);
		}
	}
	escribirArchivo(listaDepartamentos);
}

void DepartamentoController::agregarDepartamento(Departamento^ objDepartamento) {
	List<Departamento^>^ listaDepartamentos = buscarAll();
	listaDepartamentos->Add(objDepartamento);
	escribirArchivo(listaDepartamentos);
}

void DepartamentoController::agregarDepartamentoaEdificio(Departamento^ objeto, int codigoEdificio) {

	array<String^>^ lineas = File::ReadAllLines("departamentos.txt");
	int cantLineas = 0;
	for each (String ^ linea in lineas) {
		cantLineas++;
	}
	array<String^>^ lineasArchivo = gcnew array<String^>(cantLineas + 1);
	int i;
	for (i = 0; i < (cantLineas); i++) {
		lineasArchivo[i] = lineas[i];
	}
	lineasArchivo[i] = objeto->getCodigo() + ";" + objeto->getNroAmbientes() + ";" + objeto->getArea() + ";" + objeto->getPiso() + ";" + objeto->getPrecio() + ";" + objeto->getTipo() + ";" + objeto->getAncho() + ";" + objeto->getLargo() + ";" + objeto->getAlto() + ";" + objeto->getCliente()->getCodigo() + ";" + objeto->getVendedor()->getCodigo() + ";" + codigoEdificio;
	File::WriteAllLines("departamentos.txt", lineasArchivo);
}

void DepartamentoController::actualizarDepartamento(Departamento^ objDepartamento) {
	List<Departamento^>^ listaDepartamentos = buscarAll();
	for (int i = 0; i < listaDepartamentos->Count; i++) {
		if (listaDepartamentos[i]->getCodigo() == objDepartamento->getCodigo()) {
			/*Voy a actualizar cada dato de ese Departamento en la lista*/
			listaDepartamentos[i]->setCodigo(objDepartamento->getCodigo());
			listaDepartamentos[i]->setNroAmbientes(objDepartamento->getNroAmbientes());
			listaDepartamentos[i]->setArea(objDepartamento->getArea());
			listaDepartamentos[i]->setPiso(objDepartamento->getPiso());
			listaDepartamentos[i]->setPrecio(objDepartamento->getPrecio());
			listaDepartamentos[i]->setTipo(objDepartamento->getTipo());
			listaDepartamentos[i]->setAncho(objDepartamento->getAncho());
			listaDepartamentos[i]->setLargo(objDepartamento->getLargo());
			listaDepartamentos[i]->setAlto(objDepartamento->getAlto());
			listaDepartamentos[i]->setCliente(objDepartamento->getCliente());
			listaDepartamentos[i]->setVendedor(objDepartamento->getVendedor());

			break;
		}
	}
	escribirArchivo(listaDepartamentos);
}

List<String^>^ DepartamentoController::obtenerTipos() {
	List<Departamento^>^ listaDepartamentos = buscarAll();
	List<String^>^ listaTipos = gcnew List<String^>();
	for (int i = 0; i < listaDepartamentos->Count; i++) {
		/*Aqui voy a buscar cada tipo si ya se encuentra en la lista de tipos*/
		String^ tipo = listaDepartamentos[i]->getTipo();
		/*Voy a buscarlo en la listaTipos*/
		int existe = 0;
		for (int j = 0; j < listaTipos->Count; j++) {
			if (listaTipos[j]->Contains(tipo)) {
				existe = 1;
			}
		}
		if (existe == 0) {
			listaTipos->Add(tipo);
		}
	}
	return listaTipos;
}