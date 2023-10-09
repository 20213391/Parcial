#include <iostream>
#include "VendedorController.h"

using namespace SistemaConstruccionController;
using namespace System::IO; /*Este espacio de nombres sirve para manejar los archivos de texto*/

VendedorController::VendedorController() {

}

List<Vendedor^>^ VendedorController::buscarAll() {
    /*En esta lista vamos a colocar la información de los Vendedors que encontremos en el archivo de texto*/

    List<Vendedor^>^ listaVendedorsEncontrados = gcnew List<Vendedor^>();
    array<String^>^ lineas = File::ReadAllLines("clientes.txt");
    String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/

    /*Esta instruccion for each nos permite ir elemento por elemento de un array*/

    for each (String ^ lineaVendedor in lineas) {

        /*Voy a separar cada elemento del String por ; con el split*/

        array<String^>^ datos = lineaVendedor->Split(separadores->ToCharArray());

        int codigoVendedor = Convert::ToInt32(datos[0]);
        String^ Nombre = datos[1];
        String^ apPaterno = datos[2];
        String^ apMaterno = datos[3];
        String^ dni = datos[4];
        double sueldo = Convert::ToDouble(datos[5]);
        String ^ categoria = datos[6];

        Vendedor^ objVendedor = gcnew Vendedor(codigoVendedor, Nombre, apPaterno, apMaterno, dni, sueldo, categoria);
        listaVendedorsEncontrados->Add(objVendedor);
    }

    return listaVendedorsEncontrados;
}

Vendedor^ VendedorController::buscarVendedorxDNI(String^ dni) {
    List<Vendedor^>^ listaVendedors = buscarAll();

    for (int i = 0; i < listaVendedors->Count; i++) {

        if (listaVendedors[i]->getDNI()->Contains(dni)) {

            return listaVendedors[i];

        }

    }
}


void VendedorController::escribirArchivo(List<Vendedor^>^ lista) {

    array<String^>^ lineasArchivo = gcnew array<String^>(lista->Count);

    for (int i = 0; i < lista->Count; i++) {

        Vendedor^ objVendedor = lista[i];

        lineasArchivo[i] = objVendedor->getCodigo() + ";" + objVendedor->getNombres() + ";" + objVendedor->getApellidoPaterno() + ";" + objVendedor->getApellidoMaterno() + ";" + objVendedor->getDNI() + ";" + objVendedor->getSueldo() + ";" + objVendedor->getCategoria();

    }

    File::WriteAllLines("clientes.txt", lineasArchivo);

}

void VendedorController::eliminarVendedor(int codigo) {

    List<Vendedor^>^ listaVendedors = buscarAll();

    for (int i = 0; i < listaVendedors->Count; i++) {

        if (listaVendedors[i]->getCodigo() == codigo) {

            listaVendedors->RemoveAt(i);

        }

        escribirArchivo(listaVendedors);

    }

}

void VendedorController::agregarVendedor(Vendedor^ objVendedor) {

    List<Vendedor^>^ listaVendedors = buscarAll();

    listaVendedors->Add(objVendedor);

    escribirArchivo(listaVendedors);

}

Vendedor^ VendedorController::buscarVendedorxCodigo(int codigo) {

    List<Vendedor^>^ listaVendedors = buscarAll();

    for (int i = 0; i < listaVendedors->Count; i++) {

        if (listaVendedors[i]->getCodigo() == codigo) {

            return listaVendedors[i];

        }

    }

}

/*MODIFICACION DE VALORES DE ATRIBUTOS DE OBJETO*/

void VendedorController::actualizarVendedor(Vendedor^ objVendedor) {

    List<Vendedor^>^ listaVendedores = buscarAll();

    for (int i = 0; i < listaVendedores->Count; i++) {

        if (listaVendedores[i]->getCodigo() == objVendedor->getCodigo()) {

            listaVendedores[i]->setCodigo(objVendedor->getCodigo());
            listaVendedores[i]->setNombres(objVendedor->getNombres());
            listaVendedores[i]->setApellidoPaterno(objVendedor->getApellidoPaterno());
            listaVendedores[i]->setApellidoMaterno(objVendedor->getApellidoMaterno());
            listaVendedores[i]->setDNI(objVendedor->getDNI());
            listaVendedores[i]->setSueldo(objVendedor->getSueldo());

            break;
        }
    }

    escribirArchivo(listaVendedores);
}


List<String^>^ VendedorController::obtenerDNIs() {
    List<Vendedor^>^ listaVendedors = buscarAll();
    List<String^>^ listaDNIs = gcnew List<String^>();

    for (int i = 0; i < listaVendedors->Count; i++) {

        String^ dni = Convert::ToString(listaVendedors[i]->getDNI());

        int existe = 0;
        for (int j = 0; j < listaDNIs->Count; j++) {

            if (listaDNIs[j] == dni) {
                existe = 1;
            }
        }
        if (existe == 0) {
            listaDNIs->Add(dni);
        }
        listaDNIs->Add("Todos");
    }
    return listaDNIs;
}