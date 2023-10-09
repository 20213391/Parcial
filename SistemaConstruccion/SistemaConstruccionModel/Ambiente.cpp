#include "Ambiente.h"

using namespace SistemaConstruccionModel;

Ambiente::Ambiente() {

}

Ambiente::Ambiente(int codigo, double largo, double ancho, String^ tipo, int cantGrifos, int cantTomaCorrientes) {
	this->codigo = codigo;
	this->largo = largo;
	this->ancho = ancho;
	this->tipo = tipo;
	this->cantGrifos = cantGrifos;
	this->cantTomaCorrientes = cantTomaCorrientes;
}

int Ambiente::getCodigo() {
	return this->codigo;
}
void Ambiente::setCodigo(int codigo) {
	this->codigo = codigo;
}


double Ambiente::getLargo() {
	return this->largo;
}
void Ambiente::setLargo(double largo) {
	this->largo = largo;
}


double Ambiente::getAncho() {
	return this->ancho;
}
void Ambiente::setAncho(double ancho) {
	this->ancho = ancho;
}


String^ Ambiente::getTipo() {
	return this->tipo;
}
void Ambiente::setTipo(String^ tipo) {
	this->tipo = tipo;
}


int Ambiente::getCantGrifos() {
	return this->cantGrifos;
}
void Ambiente::setCantGrifos(int cantGrifos) {
	this->cantGrifos = cantGrifos;
}


int Ambiente::getCantTomaCorrientes() {
	return this->cantTomaCorrientes;
}
void Ambiente::setCantTomaCorrientes(int cantTomacorrientes) {
	this->cantTomaCorrientes = cantTomacorrientes;
}
