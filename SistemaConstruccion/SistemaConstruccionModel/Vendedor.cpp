#include "Vendedor.h"

using namespace SistemaConstruccionModel;

Vendedor::Vendedor():Persona() {

}

Vendedor::Vendedor(int codigo, String^ nombres, String^ apellidoPaterno, String^ apellidoMaterno, String^ dni, double sueldo, String^ categoria): Persona(codigo,nombres,apellidoPaterno,apellidoMaterno,dni) {
	this->sueldo = sueldo;
	this->categoria = categoria;
}

int Vendedor::getCodigo() {
	return this->codigo;
}
void Vendedor::setCodigo(int codigo) {
	this->codigo = codigo;
}


String^ Vendedor::getNombres() {
	return this->nombres;
}
void Vendedor::setNombres(String^ nombres) {
	this->nombres = nombres;
}


String^ Vendedor::getApellidoPaterno() {
	return this->apellidoPaterno;
}
void Vendedor::setApellidoPaterno(String^ apellidoPaterno) {
	this->apellidoPaterno = apellidoPaterno;
}


String^ Vendedor::getApellidoMaterno() {
	return this->apellidoMaterno;
}
void Vendedor::setApellidoMaterno(String^ apellidoMaterno) {
	this->apellidoMaterno = apellidoMaterno;
}


String^ Vendedor::getDNI() {
	return this->dni;
}
void Vendedor::setDNI(String^ dni) {
	this->dni = dni;
}


double Vendedor::getSueldo() {
	return this->sueldo = sueldo;
	
}
void Vendedor::setSueldo(double sueldo) {
	this->sueldo = sueldo;
}


String^ Vendedor::getCategoria() {
	return this->categoria;
}
void Vendedor::setCategoria(String^ categoria) {
	this->categoria = categoria;
}