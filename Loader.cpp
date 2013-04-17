#include "Loader.h"

/***********************************************************************************/
/***********************************************************************************/
int Loader::filtroArchivos(const struct dirent * dire, const char* raiz){
    
    /* Descartar "." y ".." , NO se listan */
    if( strncmp(dire->d_name, ".", 2) == 0
        || strncmp(dire->d_name, "..", 3) == 0 )
        return -1;
        
    /* Chequear si es directorio o no. Se pregunta por el tipo UNKNOWN tambien.
     * Devuelve 0 porque es directorio (y no se lista)
    * */
    if( dire->d_type == DT_UNKNOWN || dire->d_type == DT_DIR ){
                return 0;
                }
        /*if(dire->d_type == DT_DIR )
                return 0;*/
    /* Seguramente es un archivo corriente, y se debe listar
     * */
    return 1;
}

/***********************************************************************************/
/***********************************************************************************/
string Loader::sacarRaizPpal (string unArchivo){
    return unArchivo.erase (0, largoRaizStr);
}

/***********************************************************************************/
/***********************************************************************************/
bool Loader::filtroExtensiones(string nombreArchivo, string extension){
    return nombreArchivo.find(extension) != string::npos; //Si es distinto, encuentra la extension
}

/***********************************************************************************/
/***********************************************************************************/
void Loader::insertar(string archivoPorAgregar, string extension){
    if (filtroExtensiones (archivoPorAgregar, extension))
        direcciones.push_back(archivoPorAgregar);
}

/***********************************************************************************/
/***********************************************************************************/
void Loader::listarArchivos(const char* unDirectorio, string extension = ""){
        DIR *pDIR;
        struct dirent *entrada;
        string raiz (unDirectorio);
        int stopper; //estado del filtro
        
        if ( pDIR=opendir(unDirectorio) ){
                while ( entrada = readdir(pDIR) ){
                    
                        stopper = filtroArchivos(entrada, unDirectorio);
                        
                        if (stopper == 1){
                            /* Se lista porque es fichero comun */
                            string archivo(entrada->d_name);
                            string rutaDelArchivo;
                            
                            //Si es la raizPpal NO se agrega el cosito: "/" = SEPARADOR_DIR
                            if (raiz == raizPpalStr)
                                rutaDelArchivo = archivo;
                            else{
                                //Si es otro directorio, se agrega la barra y se borra
                                //del string el directorio raiz
                                rutaDelArchivo = raiz + SEPARADOR_DIR + archivo;
                                rutaDelArchivo = sacarRaizPpal (rutaDelArchivo);
                                }
                            
                            insertar(rutaDelArchivo, extension);
                            
                            }else if (stopper == 0) {
                                /* Se hace llamada recursiva por ser directorio
                                 * Se descarta en otro caso
                                 **/
                                string directorioRama (entrada->d_name);
                                string rama;
                                
                                rama = raiz + SEPARADOR_DIR + directorioRama;
                                
                                listarArchivos(rama.c_str());
                                }
                }
                closedir(pDIR);
        }
}

/***********************************************************************************/
/***********************************************************************************/
Loader::Loader (string directorio, string extension = ""){
    raizPpalStr = directorio;
    raizPpal = directorio.c_str();
    largoRaizStr = directorio.length();
    
    laPosicion = 0;
    
    listarArchivos(raizPpal, extension); //llamadas
    //std::sort(direcciones.begin(), direcciones.end()); //ordena
    direcciones.sort();
    };

/***********************************************************************************/
/***********************************************************************************/
bool Loader::estaVacio(){
    return direcciones.empty();
}

/***********************************************************************************/
/***********************************************************************************/
string Loader::getDocumento(){
    string Archivo = direcciones.front();
    
    direcciones.pop_front();
    
    return raizPpalStr + SEPARADOR_DIR + Archivo;
};

/***********************************************************************************/
/***********************************************************************************/
unsigned Loader::getPosicion(){
    
    unsigned devuelve = laPosicion++;
    return devuelve;
};
