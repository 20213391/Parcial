#include <iostream>
#include "TareaController.h"

using namespace SistemaConstruccionController;
using namespace System::IO;

TareaController::TareaController() {

}

List<Tarea^>^ TareaController::buscarTareasxResponsable(String^ responsableBuscado) {
    List<Tarea^>^ listaTareasBuscados = gcnew List<Tarea^>();
    List<Tarea^>^ listaTareas = buscarAll();
    for (int i = 0; i < listaTareas->Count; i++) {
        if ((listaTareas[i]->getResponsable() == responsableBuscado) || (responsableBuscado == "Todos")) {
            listaTareasBuscados->Add(listaTareas[i]);
        }
    }
    return listaTareasBuscados;
}

List<Tarea^>^ TareaController::buscarAll() {
    /*En esta lista vamos a colocar la información de los Tareas que encontremos en el archivo de texto*/

    List<Tarea^>^ listaTareasEncontrados = gcnew List<Tarea^>();
    array<String^>^ lineas = File::ReadAllLines("tareas.txt");
    String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/

    /*Esta instruccion for each nos permite ir elemento por elemento de un array*/

    for each (String ^ lineaTarea in lineas) {

        /*Voy a separar cada elemento del String por ; con el split*/

        array<String^>^ datos = lineaTarea->Split(separadores->ToCharArray());

        int codigo = Convert::ToInt32(datos[0]);
        String^ fechaInicio = datos[1];
        String^ fechaFin = datos[2];
        String^ nombre = datos[3];
        float avance = Convert::ToDouble(datos[4]);
        String^ responsable = datos[5];

        Tarea^ objTarea = gcnew Tarea(codigo, fechaInicio, fechaFin, nombre, avance, responsable);
        listaTareasEncontrados->Add(objTarea);
    }

    return listaTareasEncontrados;
}
List<Tarea^>^ TareaController::buscarTareasxEtapa(int codigoEtapa) {
    /*En esta lista vamos a colocar la información de los Tareas que encontremos en el archivo de texto*/
    List<Tarea^>^ listaTareasEncontrados = gcnew List<Tarea^>();
    array<String^>^ lineas = File::ReadAllLines("ambientes.txt");

    String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
    /*Esta instruccion for each nos permite ir elemento por elemento de un array*/
    for each (String ^ lineaTarea in lineas) {
        /*Voy a separar cada elemento del String por ; con el split*/
        array<String^>^ datos = lineaTarea->Split(separadores->ToCharArray());

        int codigo = Convert::ToInt32(datos[0]);
        String^ fechaInicio = datos[1];
        String^ fechaFin = datos[2];
        String^ nombre = datos[3];
        float avance = Convert::ToDouble(datos[4]);
        String^ responsable = datos[5];

        int codigoTareaEtapa = Convert::ToInt32(datos[6]);

        if (codigoTareaEtapa == codigoEtapa) {
            Tarea^ objTarea = gcnew Tarea(codigo, fechaInicio, fechaFin, nombre, avance, responsable);
            listaTareasEncontrados->Add(objTarea);
        }
    }
    return listaTareasEncontrados;
}
Tarea^ TareaController::buscarTareaxCodigo(int codigo) {

    List<Tarea^>^ listaTareas = buscarAll();

    for (int i = 0; i < listaTareas->Count; i++) {

        if (listaTareas[i]->getCodigo() == codigo) {

            return listaTareas[i];

        }
    }
}


void TareaController::eliminarTarea(int codigo) {

    List<Tarea^>^ listaTareas = buscarAll();

    for (int i = 0; i < listaTareas->Count; i++) {

        if (listaTareas[i]->getCodigo() == codigo) {

            listaTareas->RemoveAt(i);

        }

        escribirArchivo(listaTareas);

    }

}


/*MODIFICACION DE VALORES DE ATRIBUTOS DE OBJETO*/

void TareaController::editarTarea(Tarea^ objTarea) {

    List<Tarea^>^ listaTareas = buscarAll();

    for (int i = 0; i < listaTareas->Count; i++) {

        if (listaTareas[i]->getCodigo() == objTarea->getCodigo()) {

            listaTareas[i]->setCodigo(objTarea->getCodigo());
            listaTareas[i]->setFechaInicio(objTarea->getFechaInicio());
            listaTareas[i]->setFechaFin(objTarea->getFechaFin());
            listaTareas[i]->setNombre(objTarea->getNombre());
            listaTareas[i]->setAvance(objTarea->getAvance());
            listaTareas[i]->setResponsable(objTarea->getResponsable());
            
            break;
        }
    }
    escribirArchivo(listaTareas);
}


void TareaController::agregarTareaxEtapa(Tarea^ objTarea, int codigoEtapa) {

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
    lineasArchivo[i] = objTarea->getCodigo() + ";" + objTarea->getFechaInicio() + ";" + objTarea->getFechaFin() + ";" + objTarea->getNombre() + ";" + objTarea->getAvance() + ";" + objTarea->getResponsable() + ";" + codigoEtapa;
    File::WriteAllLines("ambientes.txt", lineasArchivo);
}
void TareaController::agregarTarea(Tarea^ objTarea) {

    List<Tarea^>^ listaTareas = buscarAll();

    listaTareas->Add(objTarea);

    escribirArchivo(listaTareas);

}


void TareaController::escribirArchivo(List<Tarea^>^ lista) {

    array<String^>^ lineasArchivo = gcnew array<String^>(lista->Count);

    for (int i = 0; i < lista->Count; i++) {

        Tarea^ objTarea = lista[i];

        lineasArchivo[i] = objTarea->getCodigo() + ";" + objTarea->getFechaInicio() + ";" + objTarea->getFechaFin() + ";" + objTarea->getNombre() + ";" + objTarea->getAvance() + ";" + objTarea->getResponsable();

    }

    File::WriteAllLines("ambientes.txt", lineasArchivo);

}


/*BUSQUEDA DE ITEMS SEGUN CRITERIO DE BUSQUEDA*/

List<String^>^ TareaController::obtenerResponsables() {

    List<Tarea^>^ listaTareas = buscarAll();
    List<String^>^ listaResponsables = gcnew List<String^>();

    for (int i = 0; i < listaTareas->Count; i++) {

        String^ responsable = listaTareas[i]->getResponsable();

        int existe = 0;
        for (int j = 0; j < listaResponsables->Count; j++) {

            if (listaResponsables[j] == responsable) {
                existe = 1;
            }
        }
        if (existe == 0) {
            listaResponsables->Add(responsable);
        }
        listaResponsables->Add("Todos");
    }
    return listaResponsables;
}
