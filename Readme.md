# Implémentation d’un moteur de requêtes SQL simples

## Objectif

Le projet consiste a implémenter un moteur d’évaluation de requêtes SQL en mémoire vive.
Les requêtes considérées seront de la forme SELECT ... FROM ... WHERE sans imbrication. À partir d’un fichier de données il est demandé de construire une représentation en mémoire des relations et des requêtes et d’implémenter les procédures de projection, sélection, et jointure découlant de l’interrogation SQL.

## Manière d'executer le programme

### Mode ligne de commande

`$ prog table1.csv ... tableN.csv "SELECT ... FROM ... WHERE ..."`

Chaque table utilisé dans le FROM doit être donné en argmument.

### Mode intéractif

`$ prog table1.csv ... tableN.csv`
OU
`$ prog -d dossier/`

Les requêtes SQL seront données au programme lors de son execution

PS : Les requêtes prise en charge par le programme sont de la forme suivante :

SELECT nom,des,attributs,projeter
FROM nom,des,tables,utilisé
WHERE   age < 28
    AND age > 18
    OR  nom = "Michelle";

## Les etapes d'execution du programmes

- Lire les arguments et identifié les tables (càd les fichiers .csv) et la requête;
  - Si la requête n'est pas donnée dans les arguments, le programme donne la main à l'utilisateur pour la saisir manuellement;
- Charger les tables en mémoire vive (càd creer des instances de la classe "Table")
- Décripter la requête SQL;
  - Stocker dans une variable les attributs a projetés (Ce qui vient après le SELECT);
  - Executer les jointures (Ce qui vient après le FROM);
  - Décripter les conditions de selections (Ce qui vient après le WHERE);
- Appliquer les conditions de selection sur la table;
- Appliquer la projection;
- Ecrire le resultat dans un flux de sortie;

## Encadrant et Étudiants :

Encadrante : Anne-Muriel Chifolleau : `chifolleau@lirmm.fr`

Étudiants :

- Massili KEZZOUL : `massy.kezzoul@gmail.com`
- Belkassim BOUZIDI : `bouzidibelkassim@gmail.com`
- Chakib ELHOUITI : `celhouiti@gmail.com`
- Ramzi ZEROUAL : `ramzizerr@gmail.com`
- Fei YANG : `fei.yang@insa-cvl.fr`

- Début du projet : Janvier 2019
- Fin du projet   : Mai 2019
- Langage Utilisé : C++
