#include <iostream>
#include "ClienteController.h"

using namespace SistemaConstruccionController;
using namespace System::IO; /*Este espacio de nombres sirve para manejar los archivos de texto*/

ClienteController::ClienteController() {

}

List<Cliente^>^ ClienteController::buscarAll() {
    /*En esta lista vamos a colocar la información de los Clientes que encontremos en el archivo de texto*/

    List<Cliente^>^ listaClientesEncontrados = gcnew List<Cliente^>();
    array<String^>^ lineas = File::ReadAllLines("clientes.txt");
    String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/

    /*Esta instruccion for each nos permite ir elemento por elemento de un array*/

    for each (String ^ lineaCliente in lineas) {

        /*Voy a separar cada elemento del String por ; con el split*/

        array<String^>^ datos = lineaCliente->Split(separadores->ToCharArray());

        int codigoCliente = Convert::ToInt32(datos[0]);
        String^ Nombre = datos[1];
        String^ apPaterno = datos[2];
        String^ apMaterno = datos[3];
        String^ dni = datos[4];
        String^ fechaNacimineto = datos[5];

        Cliente^ objCliente = gcnew Cliente(codigoCliente, Nombre, apPaterno, apMaterno, dni, fechaNacimineto);
        listaClientesEncontrados->Add(objCliente);
    }

    return listaClientesEncontrados;
}

Cliente^ ClienteController::buscarClientexCodigo(int codigo) {

    List<Cliente^>^ listaClientes = buscarAll();

    for (int i = 0; i < listaClientes->Count; i++) {

        if (listaClientes[i]->getCodigo() == codigo) {

            return listaClientes[i];

        }

    }

}

Cliente^ ClienteController::buscarClientexDNI(String^ dni) {
    List<Cliente^>^ listaClientes = buscarAll();

    for (int i = 0; i < listaClientes->Count; i++) {

        if (listaClientes[i]->getDNI()->Contains(dni)) {

            return listaClientes[i];

        }

    }
}


void ClienteController::escribirArchivo(List<Cliente^>^ lista) {

    array<String^>^ lineasArchivo = gcnew array<String^>(lista->Count);

    for (int i = 0; i < lista->Count; i++) {

        Cliente^ objCliente = lista[i];

        lineasArchivo[i] = objCliente->getCodigo() + ";" + objCliente->getNombres() + ";" + objCliente->getApellidoPaterno() + ";" + objCliente->getApellidoMaterno() + ";" + objCliente->getDNI() + ";" + objCliente->getFechaNacimiento();

    }

    File::WriteAllLines("clientes.txt", lineasArchivo);

}

void ClienteController::eliminarCliente(int codigo) {

    List<Cliente^>^ listaClientes = buscarAll();

    for (int i = 0; i < listaClientes->Count; i++) {

        if (listaClientes[i]->getCodigo() == codigo) {

            listaClientes->RemoveAt(i);

        }

        escribirArchivo(listaClientes);

    }

}

void ClienteController::agregarCliente(Cliente^ objCliente) {

    List<Cliente^>^ listaClientes = buscarAll();

    listaClientes->Add(objCliente);

    escribirArchivo(listaClientes);

}


/*MODIFICACION DE VALORES DE ATRIBUTOS DE OBJETO*/

void ClienteController::actualizarCliente(Cliente^ objCliente) {

    List<Cliente^>^ listaClientes = buscarAll();

    for (int i = 0; i < listaClientes->Count; i++) {

        if (listaClientes[i]->getCodigo() == objCliente->getCodigo()) {

            listaClientes[i]->setCodigo(objCliente->getCodigo());
            listaClientes[i]->setNombres(objCliente->getNombres());
            listaClientes[i]->setApellidoPaterno(objCliente->getApellidoPaterno());
            listaClientes[i]->setApellidoMaterno(objCliente->getApellidoMaterno());
            listaClientes[i]->setDNI(objCliente->getDNI());
            listaClientes[i]->setFechaNacimiento(objCliente->getFechaNacimiento());

            break;
        }
    }

    escribirArchivo(listaClientes);
}


List<String^>^ ClienteController::obtenerDNIs() {
    List<Cliente^>^ listaClientes = buscarAll();
    List<String^>^ listaDNIs = gcnew List<String^>();

    for (int i = 0; i < listaClientes->Count; i++) {

        String^ dni = Convert::ToString(listaClientes[i]->getDNI());

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