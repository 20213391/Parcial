#include <iostream>
#include "AmbienteController.h"

using namespace SistemaConstruccionController;
using namespace System::IO;

AmbienteController::AmbienteController() {

}

List<Ambiente^>^ AmbienteController::buscarAmbientesxTipo(String^ tipoBuscado) {
    List<Ambiente^>^ listaAmbientesBuscados = gcnew List<Ambiente^>();
    List<Ambiente^>^ listaAmbientes = buscarAll();
    for (int i = 0; i < listaAmbientes->Count; i++) {
        if ((listaAmbientes[i]->getTipo()->Contains(tipoBuscado)) || (tipoBuscado == "Todos")) {
            listaAmbientesBuscados->Add(listaAmbientes[i]);
        }
    }
    return listaAmbientesBuscados;
}

List<Ambiente^>^ AmbienteController::buscarAll() {
    /*En esta lista vamos a colocar la información de los Ambientes que encontremos en el archivo de texto*/

    List<Ambiente^>^ listaAmbientesEncontrados = gcnew List<Ambiente^>();
    array<String^>^ lineas = File::ReadAllLines("ambientes.txt");
    String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/

    /*Esta instruccion for each nos permite ir elemento por elemento de un array*/

    for each (String ^ lineaAmbiente in lineas) {

        /*Voy a separar cada elemento del String por ; con el split*/

        array<String^>^ datos = lineaAmbiente->Split(separadores->ToCharArray());

        int codigo = Convert::ToInt32(datos[0]);
        double largo = Convert::ToDouble(datos[1]);
        double ancho = Convert::ToDouble(datos[2]);
        String^ tipo = datos[3];
        int cantGrifos = Convert::ToInt32(datos[4]);
        int cantTomaCorrientes = Convert::ToInt32(datos[5]);

        Ambiente^ objAmbiente = gcnew Ambiente(codigo, largo, ancho, tipo, cantGrifos, cantTomaCorrientes);
        listaAmbientesEncontrados->Add(objAmbiente);
    }

    return listaAmbientesEncontrados;
}

List<Ambiente^>^ AmbienteController::buscarAmbientesxDepartamento(int codigoDepartamento) {
    /*En esta lista vamos a colocar la información de los Ambientes que encontremos en el archivo de texto*/
    List<Ambiente^>^ listaAmbientesEncontrados = gcnew List<Ambiente^>();
    array<String^>^ lineas = File::ReadAllLines("ambientes.txt");

    String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
    /*Esta instruccion for each nos permite ir elemento por elemento de un array*/
    for each (String ^ lineaAmbiente in lineas) {
        /*Voy a separar cada elemento del String por ; con el split*/
        array<String^>^ datos = lineaAmbiente->Split(separadores->ToCharArray());

        int codigo = Convert::ToInt32(datos[0]);
        double largo = Convert::ToDouble(datos[1]);
        double ancho = Convert::ToDouble(datos[2]);
        String^ tipo = datos[3];
        int cantGrifos = Convert::ToInt32(datos[4]);
        int cantTomaCorrientes = Convert::ToInt32(datos[5]);

        int codigoAmbienteDepartamento = Convert::ToInt32(datos[6]);

        if (codigoAmbienteDepartamento == codigoDepartamento) {
            Ambiente^ objAmbiente = gcnew Ambiente(codigo, largo, ancho, tipo, cantGrifos, cantTomaCorrientes);
            listaAmbientesEncontrados->Add(objAmbiente);
        }
    }
    return listaAmbientesEncontrados;
}

Ambiente^ AmbienteController::buscarAmbientexCodigo(int codigo) {

    List<Ambiente^>^ listaAmbientes = buscarAll();

    for (int i = 0; i < listaAmbientes->Count; i++) {

        if (listaAmbientes[i]->getCodigo() == codigo) {

            return listaAmbientes[i];

        }
    }
}


void AmbienteController::eliminarAmbiente(int codigo) {

    List<Ambiente^>^ listaAmbientes = buscarAll();

    for (int i = 0; i < listaAmbientes->Count; i++) {

        if (listaAmbientes[i]->getCodigo() == codigo) {

            listaAmbientes->RemoveAt(i);

        }

        escribirArchivo(listaAmbientes);

    }

}


/*MODIFICACION DE VALORES DE ATRIBUTOS DE OBJETO*/

void AmbienteController::editarAmbiente(Ambiente^ objAmbiente) {

    List<Ambiente^>^ listaAmbientes = buscarAll();

    for (int i = 0; i < listaAmbientes->Count; i++) {

        if (listaAmbientes[i]->getCodigo() == objAmbiente->getCodigo()) {

            listaAmbientes[i]->setCodigo(objAmbiente->getCodigo());
            listaAmbientes[i]->setLargo(objAmbiente->getLargo());
            listaAmbientes[i]->setAncho(objAmbiente->getAncho());
            listaAmbientes[i]->setCantGrifos(objAmbiente->getCantGrifos());
            listaAmbientes[i]->setCantTomaCorrientes(objAmbiente->getCantTomaCorrientes());

            break;
        }
    }
    escribirArchivo(listaAmbientes);
}


void AmbienteController::agregarAmbientexDepartamento(Ambiente^ objAmbiente, int codigoDepartamento) {

    array<String^>^ lineas = File::ReadAllLines("ambientes.txt");
    int cantLineas = 0;
    for each (String ^ linea in lineas) {
        cantLineas++;
    }
    array<String^>^ lineasArchivo = gcnew array<String^>(cantLineas + 1);
    int i;
    for (i = 0; i < (cantLineas); i++) {
        lineasArchivo[i] = lineas[i];
    }
    lineasArchivo[i] = objAmbiente->getCodigo() + ";" + objAmbiente->getLargo() + ";" + objAmbiente->getAncho() + ";" + objAmbiente->getCantGrifos() + ";" + objAmbiente->getCantTomaCorrientes() + ";" + codigoDepartamento;
    File::WriteAllLines("ambientes.txt", lineasArchivo);
}
void AmbienteController::agregarAmbiente(Ambiente^ objAmbiente) {

    List<Ambiente^>^ listaAmbientes = buscarAll();

    listaAmbientes->Add(objAmbiente);

    escribirArchivo(listaAmbientes);

}


void AmbienteController::escribirArchivo(List<Ambiente^>^ lista) {

    array<String^>^ lineasArchivo = gcnew array<String^>(lista->Count);

    for (int i = 0; i < lista->Count; i++) {

        Ambiente^ objAmbiente = lista[i];

        lineasArchivo[i] = objAmbiente->getCodigo() + ";" + objAmbiente->getLargo() + ";" + objAmbiente->getAncho() + ";" + objAmbiente->getTipo() + ";" + objAmbiente->getCantGrifos() + ";" + objAmbiente->getCantTomaCorrientes();

    }

    File::WriteAllLines("ambientes.txt", lineasArchivo);

}


/*BUSQUEDA DE ITEMS SEGUN CRITERIO DE BUSQUEDA*/

List<String^>^ AmbienteController::obtenerTipos() {

    List<Ambiente^>^ listaAmbientes = buscarAll();
    List<String^>^ listaTipos = gcnew List<String^>();

    for (int i = 0; i < listaAmbientes->Count; i++) {

        String^ tipo = listaAmbientes[i]->getTipo();

        int existe = 0;
        for (int j = 0; j < listaTipos->Count; j++) {

            if (listaTipos[j] == tipo) {
                existe = 1;
            }
        }
        if (existe == 0) {
            listaTipos->Add(tipo);
        }
        listaTipos->Add("Todos");
    }
    return listaTipos;
}