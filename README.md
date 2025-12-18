# add42

## Introduction

`add42` est un serveur avec une page d'accueil et une api qui ajoute 42.

## Compilation

Installer `cmake`, `catch2` et `drogon`, puis :

```
cmake -S . -B build
cmake --build build
```

## Usage

Pour lancer les tests unitaires :

```
./build/test.out
```

Pour lancer le serveur :

```
./build/add42.out
```

(puis aller à l'url <localhost:3000> dans un navigateur web)

