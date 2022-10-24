#include "sculpter.h"
#include <iostream>

using namespace std;

int main(){
    int i, j, k;
    double esfera;
    Sculptor pokebola(51, 51, 51);
    // Metade superior da pokebola
    pokebola.setColor(1.0, 0, 0, 1.0);
    pokebola.putSphere(26, 26, 26, 25);

    // Metade inferir da pokebola
    pokebola.setColor(1.0, 1.0, 1.0, 1.0);

    for(k = 0; k < 51; k++){
        for(j = 0; j < 25; j++){
            for(i = 0; i < 51; i++){
                esfera = ((i - 26)*(i - 26)) + ((j - 26)*(j - 26)) + ((k - 26)*(k - 26));
                if(esfera <= (25)*(25)){
                    pokebola.putVoxel(i, j, k);
                }
            }
        }
    }

    // Remove o meio
    pokebola.cutBox(0, 50, 25, 27, 0, 50);

    // Preenche a pokebola por dentro com preto
    pokebola.setColor(0, 0, 0, 1);
    pokebola.putSphere(26, 26, 26, 24);
    pokebola.cutSphere(26, 26, 26, 20);

    // Tapa buraco no topo da pokepola
    pokebola.setColor(1, 0, 0, 1);
    pokebola.putVoxel(26, 50, 26);

    // Remove excesso na parte frontal da pokebola
    pokebola.cutEllipsoid(26, 26, 50, 10, 10, 0);
    pokebola.cutEllipsoid(26, 26, 49, 8, 8, 0);

    // Coloca botão branco na parte frontal da pokebola
    pokebola.setColor(1, 1, 1, 1);
    pokebola.putEllipsoid(26, 26, 49, 6, 6, 0);
    pokebola.putEllipsoid(26, 26, 50, 3, 3, 0);

    // Remove excesso e tapa buraco na parte inferior da pokebola
    pokebola.setColor(1, 1, 1, 1);
    pokebola.putVoxel(26, 2, 26);
    pokebola.cutVoxel(26, 1, 26);

    // Remove excesso dos lados e atrás da pokebola
    pokebola.setColor(1, 1, 0, 0);
    pokebola.cutVoxel(2, 26, 26);
    pokebola.cutVoxel(26, 26, 2);
    pokebola.cutVoxel(50, 26, 26);

    pokebola.writeOFF("pokebola-parte01.off");
    return 0;
}
