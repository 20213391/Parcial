#include "Tarea.h"

using namespace SistemaConstruccionModel;

Tarea::Tarea() {

}

Tarea::Tarea(int codigo, String^ fechaInicio, String^ fechaFin, String^ nombre, float avance, String^ responsable) {
	this->codigo = codigo;
	this->fechaInicio = fechaInicio;
	this->fechaFin = fechaFin;
	this->nombre = nombre;
	this->avance = avance;
	this->responsable = responsable;
}

int Tarea::getCodigo() {
	return this->codigo;
}
void Tarea::setCodigo(int codigo) {
	this->codigo = codigo;
}


String^ Tarea::getFechaInicio() {
	return this->fechaInicio;
}
void Tarea::setFechaInicio(String^ fechaInicio) {
	this->fechaInicio = fechaInicio;
}


String^ Tarea::getFechaFin() {
	return this->fechaFin;
}
void Tarea::setFechaFin(String^ fechaFin) {
	this->fechaFin = fechaFin;
}


String^ Tarea::getNombre() {
	return this->nombre;
}
void Tarea::setNombre(String^ nombre) {
	this->nombre = nombre;
}


float Tarea::getAvance() {
	return this->avance;
}
void Tarea::setAvance(float avance) {
	this->avance = avance;
}


String^ Tarea::getResponsable() {
	return this->responsable;
}
void Tarea::setResponsable(String^ responsable) {
	this->responsable = responsable;
}