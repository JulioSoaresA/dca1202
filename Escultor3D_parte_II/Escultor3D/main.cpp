#include "figurageometrica.h"
#include "interpretador.h"
#include "sculptor.h"

#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Sculptor *escultor;

       Interpretador interpretador;

       vector<FiguraGeometrica*>figs;

       figs = interpretador.parse("/home/julio/QtProjects/dca1202/Escultor3D_parte_II/Escultor3D/pokebola");

       escultor = new Sculptor(interpretador.getDimX(), interpretador.getDimY(), interpretador.getDimZ());

       for(size_t index=0;index<figs.size();index++){
           figs[index]->draw(*escultor);
       }

       escultor->writeOFF((char*) "pokebola.off");
       for(size_t index=0;index<figs.size();index++){
           delete figs[index];
       }
       delete escultor;
       return 0;
}
