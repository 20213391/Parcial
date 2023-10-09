#include "Edificio.h"

using namespace SistemaConstruccionModel;

Edificio::Edificio() {

}

Edificio::Edificio(int codigo, int nroPisos, int nroDepartamentos, int aforo, double areaTotal, int numero, double areaCochera, Ubicacion^ objUbicacion, List<Departamento^>^ listaDepartamentos) {
	this->codigo = codigo;
	this->nroPisos = nroPisos;
	this->nroDepartamentos = nroDepartamentos;
	this->aforo = aforo;
	this->areaTotal = areaTotal;
	this->numero = numero;
	this->areaCochera = areaCochera;
	this->objUbicacion = objUbicacion;
	this->listaDepartamentos = listaDepartamentos;
}

int Edificio::getCodigo() {
	return this->codigo;
}
void Edificio::setCodigo(int codigo) {
	this->codigo = codigo;
}


int Edificio::getNroPisos() {
	return this->nroPisos;
}
void Edificio::setNroPisos(int nroPisos) {
	this->nroPisos = nroPisos;
}

int Edificio::getNroDepartamentos() {
	return this->nroDepartamentos;
}
void Edificio::setNroDepartamentos(int nroDepartamentos) {
	this->nroDepartamentos = nroDepartamentos;
}


int Edificio::getAforo() {
	return this->aforo = aforo;
}
void Edificio::setAforo(int aforo) {
	this->aforo = aforo;
}

double Edificio::getAreaTotal() {
	return this->areaTotal = areaTotal;
}
void Edificio::setAreaTotal(double areaTotal) {
	this->areaTotal = areaTotal;
}


int Edificio::getNumero() {
	return this->numero = numero;
}
void Edificio::setNumero(int numero) {
	this->numero = numero;
}


double Edificio::getAreaCochera() {
	return this->areaCochera = areaCochera;
}
void Edificio::setAreaCochera(double areaCocehra) {
	this->areaCochera = areaCocehra;
}


Ubicacion^ Edificio::getUbicacion() {
	return this->objUbicacion;
}
void Edificio::setUbicacion(Ubicacion^ objUbicacion) {

}


List<Departamento^>^ Edificio::getListaDepartamentos() {
	return this->listaDepartamentos;
}
void Edificio::setListaDepartamentos(List<Departamento^>^ listaDepartamentos) {
	this->listaDepartamentos = listaDepartamentos;
}