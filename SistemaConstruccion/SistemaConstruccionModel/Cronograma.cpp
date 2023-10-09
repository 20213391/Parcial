#include "Cronograma.h"

using namespace SistemaConstruccionModel;

Cronograma::Cronograma() {

}

Cronograma::Cronograma(int codigo, String^ fechaInicio, String^ fechaFin, String^ estado, List<Etapa^>^ listaEtapas) {
	this->codigo = codigo;
	this->fechaInicio = fechaInicio;
	this->fechaFin = fechaFin;
	this->estado = estado;
	this->listaEtapas = listaEtapas;
}

/*Las propiedades son metodos que nos permiten acceder y modificar
			  un atributo. Son los famosos GET y SET y se hace uno por cada atributo*/
int Cronograma::getCodigo() {
	return this->codigo;
}
void Cronograma::setCodigo(int codigo) {
	this->codigo = codigo;
}

String^ Cronograma::getFechaInicio() {
	return this->fechaInicio;
}
void Cronograma::setFechaInicio(String^ fechaInicio) {
	this->fechaInicio = fechaInicio;
}

String^ Cronograma::getFechaFin() {
	return this->fechaFin;
}
void Cronograma::setFechaFin(String^ fechaEntrega) {
	this->fechaFin = fechaEntrega;
}

String^ Cronograma::getEstado() {
	return this->estado;
}
void Cronograma::setEstado(String^ estado) {
	this->estado = estado;
}
