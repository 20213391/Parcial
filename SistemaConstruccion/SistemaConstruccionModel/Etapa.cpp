#include "Etapa.h"

using namespace SistemaConstruccionModel;

Etapa::Etapa() {

}

Etapa::Etapa(int codigo, String^ fechaInicio, String^ fechaFin, String^ nombre, float avance, List<Tarea^>^ listaTareas) {
	this->codigo = codigo;
	this->fechaInicio = fechaInicio;
	this->fechaFin = fechaFin;
	this->nombre = nombre;
	this->avance = avance;
	this->listaTareas = listaTareas;
}

int Etapa::getCodigo() {
	return this->codigo;
}
void Etapa::setCodigo(int codigo) {
	this->codigo = codigo;
}


String^ Etapa::getFechaInicio() {
	return this->fechaInicio;
}
void Etapa::setFechaInicio(String^ fechaInicio) {
	this->fechaInicio = fechaInicio;
}


String^ Etapa::getFechaFin() {
	return this->fechaFin;
}
void Etapa::setFechaFin(String^ fechaFin) {
	this->fechaFin = fechaFin;
}


String^ Etapa::getNombre() {
	return this->nombre;
}
void Etapa::setNombre(String^ nombre) {
	this->nombre = nombre;
}


float Etapa::getAvance() {
	return this->avance;
}
void Etapa::setAvance(float avance) {
	this->avance = avance;
}


List<Tarea^>^ Etapa::getListaTareas() {
	return this->listaTareas;
}
void Etapa::setListaTareas(List<Tarea^>^ listaDTareas) {
	this->listaTareas = listaTareas;
}