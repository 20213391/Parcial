#include "Departamento.h"

using namespace SistemaConstruccionModel;

Departamento::Departamento() {

}

Departamento::Departamento(int codigo, int nroAmbientes, double area, int piso, double precio, String^ tipo, double ancho, double largo, double alto, Cliente^ objCliente, Vendedor^ objVendedor, List<Ambiente^>^ listaAmbientes) {
	this->codigo = codigo;
	this->nroAmbientes = nroAmbientes;
	this->area = area;
	this->piso = piso;
	this->precio = precio;
	this->tipo = tipo;
	this->ancho = ancho;
	this->largo = largo;
	this->alto = alto;
	this->objCliente = objCliente;
	this->objVendedor = objVendedor;
	this->listaAmbientes = listaAmbientes;
}

int Departamento::getCodigo() {
	return this->codigo;
}
void Departamento::setCodigo(int codigo) {
	this->codigo = codigo;
}


int Departamento::getNroAmbientes() {
	return this->nroAmbientes;
}
void Departamento::setNroAmbientes(int nroAmbientes) {
	this->nroAmbientes = nroAmbientes;
}


double Departamento::getArea() {
	return this->area;
}
void Departamento::setArea(double area) {
	this->area = area;
}


int Departamento::getPiso() {
	return this->piso;
}
void Departamento::setPiso(int piso) {
	this->piso = piso;
}


double Departamento::getPrecio() {
	return this->precio;
}
void Departamento::setPrecio(double precio) {
	this->precio = precio;
}


String^ Departamento::getTipo() {
	return this->tipo;
}
void Departamento::setTipo(String^ tipo) {
	this->tipo = tipo;
}


double Departamento::getAncho() {
	return this->ancho;
}
void Departamento::setAncho(double ancho) {
	this->ancho = ancho;
}


double Departamento::getLargo() {
	return this->largo;
}
void Departamento::setLargo(double largo) {
	this->largo = largo;
}


double Departamento::getAlto() {
	return this->alto;
}
void Departamento::setAlto(double alto) {
	this->alto = alto;
}

Cliente^ Departamento::getCliente() {
	return this->objCliente;
}
void Departamento::setCliente(Cliente^ objCliente) {
	this->objCliente = objCliente;
}


Vendedor^ Departamento::getVendedor() {
	return this->objVendedor;
}
void Departamento::setVendedor(Vendedor^ objVendedor) {
	this->objVendedor = objVendedor;
}

