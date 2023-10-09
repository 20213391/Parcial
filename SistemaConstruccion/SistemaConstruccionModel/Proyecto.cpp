#include "Proyecto.h"
#include "Cronograma.h"

using namespace SistemaConstruccionModel;

Proyecto::Proyecto() {

}

Proyecto::Proyecto(int codigo, String^ fechaInicio, String^ fechaEntrega, String^ departamento, String^ provincia, String^ distrito, int nroEdificios, String^ nombre, float presupuesto, Cronograma^ objCronograma, List<Edificio^>^ listaEdificios) {
	this->codigo = codigo;
	this->fechaInicio = fechaInicio;
	this->fechaEntrega = fechaEntrega;
	this->departamento = departamento;
	this->provincia = provincia;
	this->distrito = distrito;
	this->nroEdificios = nroEdificios;
	this->nombre = nombre;
	this->presupuesto = presupuesto;
	this->objCronograma = objCronograma;
	this->listaEdificios = listaEdificios;
}

/*Las propiedades son metodos que nos permiten acceder y modificar
			  un atributo. Son los famosos GET y SET y se hace uno por cada atributo*/
int Proyecto::getCodigo() {
	return this->codigo;
}
void Proyecto::setCodigo(int codigo) {
	this->codigo = codigo;
}


String^ Proyecto::getFechaInicio() {
	return this->fechaInicio;
}
void Proyecto::setFechaInicio(String^ fechaInicio) {
	this->fechaInicio = fechaInicio;
}


String^ Proyecto::getFechaEntrega() {
	return this->fechaEntrega;
}
void Proyecto::setFechaEntrega(String^ fechaEntrega) {
	this->fechaEntrega = fechaEntrega;
}


String^ Proyecto::getDepartamento() {
	return this->departamento;
}
void Proyecto::setDepartamento(String^ departamento) {
	this->departamento = departamento;
}


String^ Proyecto::getProvincia() {
	return this->provincia;
}
void Proyecto::setProvincia(String^ provincia) {
	this->provincia = provincia;
}


String^ Proyecto::getDistrito() {
	return this->distrito;
}
void Proyecto::setDistrito(String^ distrito) {
	this->distrito = distrito;
}


int Proyecto::getNroEdificios() {
	return this->nroEdificios;
}
void Proyecto::setNroEdificios(int nroEdificios) {
	this->nroEdificios = nroEdificios;
}


String^ Proyecto::getNombre() {
	return this->nombre;
}
void Proyecto::setNombre(String^ nombre) {
	this->nombre = nombre;
}


float Proyecto::getPresupuesto() {
	return this->presupuesto;
}
void Proyecto::setPresupuesto(float presupuesto) {
	this->presupuesto = presupuesto;
}


Cronograma^ Proyecto::getCronograma() {
	return this->objCronograma;
}
void Proyecto::setCronograma(Cronograma^ objCronograma) {
	this->objCronograma = objCronograma;
}


List<Edificio^>^ Proyecto::getListaEdificios() {
	return this->listaEdificios;
}
void Proyecto::setListaEdificios(List<Edificio^>^ listaEdificios) {
	this->listaEdificios = listaEdificios;
}