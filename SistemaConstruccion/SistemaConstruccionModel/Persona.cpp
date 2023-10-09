#include "Persona.h"

using namespace SistemaConstruccionModel;

Persona::Persona() {

}

Persona::Persona(int codigo, String^ nombres, String^ apellidoPaterno, String^ apellidoMaterno, String^ dni) {
	this->codigo = codigo;
	this->nombres = nombres;
	this->apellidoPaterno = apellidoPaterno;
	this->apellidoMaterno = apellidoMaterno;
	this->dni = dni;
}

int Persona::getCodigo() {
	return this->codigo;
}
void Persona::setCodigo(int codigo) {
	this->codigo = codigo;
}


String^ Persona::getNombres() {
	return this->nombres;
}
void Persona::setNombres(String^ nombres) {
	this->nombres = nombres;
}


String^ Persona::getApellidoPaterno() {
	return this->apellidoPaterno;
}
void Persona::setApellidoPaterno(String^ apellidoPaterno) {
	this->apellidoPaterno = apellidoPaterno;
}


String^ Persona::getApellidoMaterno() {
	return this->apellidoMaterno;
}
void Persona::setApellidoMaterno(String^ apellidoMaterno) {
	this->apellidoMaterno = apellidoMaterno;
}


String^ Persona::getDNI() {
	return this->dni;
}
void Persona::setDNI(String^ dni) {
	this->dni = dni;

}