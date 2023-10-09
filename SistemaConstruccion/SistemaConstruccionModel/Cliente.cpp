#include "Cliente.h"

using namespace SistemaConstruccionModel;

Cliente::Cliente():Persona() {

}

Cliente::Cliente(int codigo, String^ nombres, String^ apellidoPaterno, String^ apellidoMaterno, String^ dni, String^ fechaNacimiento): Persona(codigo,nombres,apellidoPaterno,apellidoMaterno,dni) {
	this->fechaNacimiento = fechaNacimiento;
}

int Cliente::getCodigo() {
	return this->codigo;
}
void Cliente::setCodigo(int codigo) {
	this->codigo = codigo;
}


String^ Cliente::getNombres() {
	return this->nombres;
}
void Cliente::setNombres(String^ nombres) {
	this->nombres = nombres;
}


String^ Cliente::getApellidoPaterno() {
	return this->apellidoPaterno;
}
void Cliente::setApellidoPaterno(String^ apellidoPaterno) {
	this->apellidoPaterno = apellidoPaterno;
}


String^ Cliente::getApellidoMaterno() {
	return this->apellidoMaterno;
}
void Cliente::setApellidoMaterno(String^ apellidoMaterno) {
	this->apellidoMaterno = apellidoMaterno;
}


String^ Cliente::getDNI() {
	return this->dni;
}
void Cliente::setDNI(String^ dni) {
	this->dni = dni;
}


String^ Cliente::getFechaNacimiento() {
	return this->fechaNacimiento;
}
void Cliente::setFechaNacimiento(String^ fechaNacimiento) {
	this->fechaNacimiento = fechaNacimiento;
}