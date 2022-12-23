# Escultor 3D - Parte III

### 1.Descrição

Este projeto tem como objetivo desenvolver um criador de esculturas 3D utilizando Voxels, os quais são utilizados algo similar no jogo Minecraft e 
dentre outros jogos, e como continuação, foi criado toda estrutura visual do nosso programa.

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

### 4.Como ultilizar
Primeiramente deve-se selecionar a caixa "Dimensões" para definir os limites e o tamanho total do espaço que será usado como mostra a imagem abaixo:

![tela-dimensao01](https://user-images.githubusercontent.com/48110997/209256826-5a3f4688-5bcb-47c2-b5ed-86553303e21b.png)

Logo após abrirá uma nova janela para definir as dimensões como mostra abaixo:

![tela-dimensao02](https://user-images.githubusercontent.com/48110997/209257041-aafcfcf1-34c3-4c30-8063-5d7f441dbb8e.png)

Após definir as dimensões, poderá ser usado qualquer função do editor.



### 5.Conclusão
Como resultado da implementação de todas funções utilizadas ao longo do projeto, obtemos o seguinte resultado, visualizando com um programa que suporte arquivos OFF:


![pokebola01](https://user-images.githubusercontent.com/48110997/197431009-df9868e6-a020-47c1-9f9e-aeb828407f9e.png)
![pokebola02](https://user-images.githubusercontent.com/48110997/197431030-770d470a-da11-496e-8296-9f7d915b17eb.png)

