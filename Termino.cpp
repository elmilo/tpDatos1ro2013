#include "Termino.h"

/*************************************************************************************/
/*************************************************************************************/
Termino::Termino (string unTermino){
    token = unTermino;
};

/*************************************************************************************/
/*************************************************************************************/
IteradorDocumentos Termino::buscarDocumento(unsigned unDocID){

IteradorDocumentos elemento;
Documento* desref;

for (elemento = documentos.begin(); elemento != documentos.end(); ++elemento){
    desref = *elemento;
    if (desref->getDocID() == unDocID){
        return elemento;
    }
}

return documentos.end();
};

/*************************************************************************************/
/*************************************************************************************/
void Termino::agregarPosicion (unsigned unaPosicion, unsigned unDocID){

IteradorDocumentos elemento = buscarDocumento (unDocID);
Documento* desref = *elemento;

    if (elemento != documentos.end()){
        desref->agregarOcurrencia(unaPosicion);
    } else {
        documentos.push_back(new Documento(unDocID));
        desref->agregarOcurrencia(unaPosicion); //Atencion! con la referencia, se mantiene si es lista
    }
};

string Termino::getTermino(){
    return token;
};

/*************************************************************************************/
/*************************************************************************************/
bool Termino::operator== (Termino &rhs){
    return this->getTermino() == rhs.getTermino();
};

/*************************************************************************************/
/*************************************************************************************/
bool Termino::operator!= (Termino &rhs){
    return !(*this == rhs);
    };
