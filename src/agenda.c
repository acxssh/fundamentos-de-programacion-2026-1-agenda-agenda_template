#include "agenda.h"

/**
 * Esta función se encarga de iniciar el número de contactos a cero
 */
void iniciar_agenda(Agenda *agenda){

}



// Varible que lleva la cuenta de cuantos contactos hay en la agenda
int num_contactos;

/**
 * Esta función sirve para agregar un contacto nuevo en la agenda
 */
void agregar_contacto(Agenda *agenda, Contacto c){

}


/**
 * Esta función sirve para buscar un contacto por nombre en la agenda y retorna la posición del contacto si exisite
 * En caso contrario retorna -1
 */
int buscar_contacto(Agenda *agenda, char *nombre){

}


/**
 * Esta función  sirve para buscar un contacto por su número de telefono en la agenda
 */
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]){

}


/**
 * Esta función sirve para ordenar los contactos por nombres de forma ascendente
 */
void ordenar_contactos(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre)>0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

/**
 * Esta función sirve para ordenar los contactos por nombres de forma descendente
 */
void ordenar_contactos_inv(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            //Completar basandose en la función anterior
        }
    }
}


/**
 * Función auxiliar para imprimir un contacto
 */
void mostrar_contacto(Contacto){

}


/**
 * Función auxiliar para leer un contacto
 */
void leer_contacto(Contacto *c){

}

/**
 * Función que imprime todos los contactos de la agenda en pantalla
 */
void imprimir_agenda(Agenda agenda){

}

/**
 * Función que sirve para cargar contactos escritos en un archivo a la agenda
 */
void cargar_contactos(char *filename, Agenda *agenda){
    FILE *archivo = fopen(filename, "r");
    
    if(archivo == NULL){
        printf("\n Error: No se pudo abrir el archivo '%s'\n", filename);
        return;

}

    if(fscanf(archivo, "%d\n", &agenda->num_contactos) != 1){
        printf("\n Error al leer el archivo.\n");
        fclose(archivo);
        return;
    }
    
    if(agenda->num_contactos > MAX_CONTACTOS){
        printf("\n[!] El archivo contiene mas contactos que el maximo permitido.\n");
        agenda->num_contactos = MAX_CONTACTOS;
    }
    
    
    for(int i = 0; i < agenda->num_contactos; i++){
        fscanf(archivo, "%s\n", agenda->contactos[i].nombre);
        fscanf(archivo, "%s\n", agenda->contactos[i].apellido);
        fscanf(archivo, "%d\n", (int*)&agenda->contactos[i].mes);
        fscanf(archivo, "%s\n", agenda->contactos[i].dia_nac);
        fscanf(archivo, "%s\n", agenda->contactos[i].num_tel);
        fscanf(archivo, "%d\n", (int*)&agenda->contactos[i].TipoTelefono);
    }
    
    fclose(archivo);
    printf("\n[+] %d contactos cargados exitosamente desde '%s'\n", 
           agenda->num_contactos, filename);

/**
 * Función que sirve para guardar todos los contactos de la agenda en un archivo
 */
void guardar_contactos(char *filename, Agenda agenda){
    FILE *archivo = fopen(filename, "w");
    
    if(archivo == NULL){
        printf("\n[!] Error: No se pudo crear el archivo '%s'\n", filename);
        return;
    }
    
 
    fprintf(archivo, "%d\n", agenda.num_contactos);
    
    
    for(int i = 0; i < agenda.num_contactos; i++){
        fprintf(archivo, "%s\n", agenda.contactos[i].nombre);
        fprintf(archivo, "%s\n", agenda.contactos[i].apellido);
        fprintf(archivo, "%d\n", agenda.contactos[i].mes);
        fprintf(archivo, "%s\n", agenda.contactos[i].dia_nac);
        fprintf(archivo, "%s\n", agenda.contactos[i].num_tel);
        fprintf(archivo, "%d\n", agenda.contactos[i].TipoTelefono);
    }
    
    fclose(archivo);
    printf("\n[+] %d contactos guardados exitosamente en '%s'\n", 
           agenda.num_contactos, filename);
}

}
