# OpenGL-Tutorial

## Introdução
Tutorial básico para aprender a como utilizar as principais funções do OpenGL em C++.

_Obs: Este tutorial é direto e não se aprofunda em conceitos do OpenGL._

Estou criando esses tutoriais para repassar da forma mais simples possível o que eu aprendi sobre o OpenGL. Se você tiver alguma ideia para melhorar esse tutorial, por favor cria um novo issue com sua a ideia nesse repositório pra gente ajudar os próximos que utilizarem. Obrigado! :D

Minicurso 22/04/2020: https://youtu.be/grzhVlLKsto

## Tutoriais
- **1-PrintBasicShapes** - Como desenhar triângulos, retângulos e círculos
<p align="center">
<img src="./img/Tutorial1.png?raw=true" height="250">
</p>

- **2-Animation** - Como criar animações de objetos
<p align="center">
<img src="./img/Tutorial2.png?raw=true" height="250">
</p>

- **3-MouseClick** - Como receber os dados do mouse na janela
<p align="center">
<img src="./img/Tutorial3.png?raw=true" height="250">
</p>

- **4-MenuWindow** - Como criar um menu de seleção
<p align="center">
<img src="./img/Tutorial4.png?raw=true" height="250">
</p>

## Instalação

```
$ sudo apt-get install mesa-common-dev
$ sudo apt-get install freeglut3-dev
```

## Execução

```
$ cd OpenGL-Tutorial/tutoriais
$ make clean
$ make
```

Para executar o tutorial 1: `./run1`.<br>
Para executar o tutorial 2: `./run2`.<br>
(...)

### Alguns projetos que utilizam OpenGL
[**ObstacleAvoidanceOpenGL**](https://github.com/Brenocq/EvolutiveSystemOpenGL-ObstacleAvoidance)
<p align="center">
<img src="https://github.com/Brenocq/EvolutiveSystemOpenGL-ObstacleAvoidance/blob/master/img/gifReleasev1.0.gif?raw=true" height="200">
</p>

[**ComputationalGeometry**](https://github.com/Brenocq/ComputationalGeometryOpenGL)
<p align="center">
<img src="https://github.com/Brenocq/OpenGL-Tutorial/blob/master/img/CompGeometry.png?raw=true" height="200">
</p>

_Se você criou um projeto legal a partir desse tutorial e quer adicionar aqui, só mandar um pull request com essa parte do README editada! :)_
