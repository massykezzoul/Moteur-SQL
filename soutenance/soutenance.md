# Soutenance

--/ RAMZI /-- 2 min
Presentation du groupe et de ce qu'on va parler.

## Introduction

### Organisation

--/ YANG FEÏ /-- 3 Minutess

### Presentation du SQL et des bases de données

Maintenants, je vais vous présenter les bases de données et le langage SQL.

Une base de données. C’est un ensemble qui va permettre de stocker des données, En termes simples, les données peuvent être des faits liés à tout objet considéré. Par exemple, un nom un âge, une taille etc.

En informatique, une base de données est la pièce centrale des dispositifs de collecte, mise en forme, stockage et utilisation d'informations. Ce dispositif comporte un système de gestion de base de données, qu’on appelle SGBD. Un SGBD est un ensemble de programmes qui permet à ses utilisateurs d'accéder, de manipuler ainsi que de contrôler l'accès a une base de données, tout en cachant la complexité des opérations exécutées.
Les opérations de recherche et de manipulation des données peuvent être exprimées sous forme de requêtes dans un langage informatique reconnu par le SGBD. Le langage sql est le langage informatique le plus populaire.

Le SQL est un langage standard pour traiter les données d’une bases de données relationnelles. La programmation SQL peut être utilisée efficacement pour insérer, rechercher, mettre à jour et supprimer des enregistrements de base de données. Les instructions SQL s'écrivent d'une manière qui ressemble à celle de phrases ordinaires en anglais. Cette ressemblance voulue vise à faciliter l'apprentissage et son utilisation.

Pour notre projet, le domaine considéré est le langage de manipulation de données simple sans imbrication.

## Modélisation / Conception

--/ CHAKIB /-- 5 min

## Implémentation

--/ MASSY /-- 5 min

### Intro

Cette partie consistais à trouver la meilleur façon de realiser les fonction precedement modéliser.

#### Choix du langage

Mais avant ça, nous avons tout d'abord choisie le langage de programmation a utilisé.

Le C++ est l’un des principaux langages enseignées dans notre formation. Nous nous somme donc naturellement tourné vers ce langage.

#### Dév

Puis nous avons répartie le dév en 3 parties principales, que nous allons brievement détailer :

- Chargement des données;
- Intérpretation des données;
- Restitution des données;

#### Utilisation

Esuite vient, la façon dont l'utilisateur vas utiliser le programme final. Nous avons notamment décider de réaliser deux versions

- Une version en ligne de commande très utile pour l'automatisation des tâches;
- Une version intéractif plus agréable à l'utilisation;

#### Test

Nous avons aussi penser à réaliser des test durant le développement.
En effet pour le bon déroulement de l'implémentation, nous avons à chaque étape écrit des programmes de test unitaire ainsi que de test d'intégration.

### Développement

Revenont donc à la parie principale de l'implémentaion, Le dév.

#### Chargements des données

Tout d'abord nous avonc coommencé par implémenter les classes que nous avions modélisées lors de la phase de conception.
Puis, la principale difficulté étais de trouver un moyen d'interpréter et d'éxtraire les données d'un fichier CSV.
Pour cela nous avons éctit une fonction, strsplit, qui se charge de segmenter une ligne du fichier en plusieurs chaine de caractères.

Cette fonction prend en paramètre une ligne d'un fichier CSV et caractère séparateur, par défault une virgule, et retourne une instance de TabString (un tableau de chaine de caractères) qui contient les différentes valeurs.

Maintenant qu’on peut parser, on commence par lire la première ligne du fichier CSV et la passer à la fonction strsplit en stockant le resultat dans l’attribut nomAttributs de la classe Table. Pour le reste du fichier, on passe chaque ligne à la fonction strsplit et on ajoute le resultat dans la matrice valeursAttributs de la classe Table

#### La requete

Concernant la requête

--/ BOUZIDI /-- 3 minute

## Démonstration

Scénario ecrit. 2/3 minute.

--/ RAMZI /-- 2 minute

## Conclusion

## Autre

Aborder quelque point d'implementation