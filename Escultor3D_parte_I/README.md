# Escultor 3D - Parte I

### 1.Descrição

Este projeto tem como objetivo desenvolver um criador de esculturas 3D utilizando Voxels, os quais são utilizados algo similar no jogo Minecraft e 
dentre outros jogos.

### 2.Ferramentas

Foi utilizado o linguagem C++ com bibliotecas como iostream, fstream e cmath. Como IDE foi utilizado o QTcreator e para vizualização da escultura
foi utilizado o Mashlab.

### 3.Voxel
Estrutura do Voxel:
```cpp
struct Voxel {
    float r, g, b; // Colors
    float a; // Transparency
    bool isOn; // Uncluded or not
};
```

### 4.Sculpter
Estrutura do Escultor no header **sculpter.h**:
```cpp
class Sculptor {
private:
    Voxel ***v; // 3D matrix
    int nx, ny, nz;
    float r, g, b, a; // Current drawning color

public:
    Sculptor(int _nx, int _ny, int _nz); // Construtor
    ~Sculptor(); // Destrutor

    // Declaração das funções
    void setColor(float r, float g, float b, float a);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void writeOFF(const char* filename);
};
```

### 5.Conclusão
Como resultado da implementação de todas funções declaradas nos headers `Voxel.h` e `sculpter.h` obtemos o seguinte resultado:
```cpp
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
```

![pokebola01](https://user-images.githubusercontent.com/48110997/197431009-df9868e6-a020-47c1-9f9e-aeb828407f9e.png)
![pokebola02](https://user-images.githubusercontent.com/48110997/197431030-770d470a-da11-496e-8296-9f7d915b17eb.png)

