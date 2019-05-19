# Soutenance

--/ RAMZI /-- 2 min
Presentation du groupe et de ce qu'on va parler.

## Introduction

### Organisation

--/ YANG FEÏ /-- 3 Minutes

### Presentation du SQL et des bases de données

Maintenants, je vais vous présenter les bases de données et le langage SQL.

Une base de données. C’est un ensemble qui va permettre de stocker des données, En termes simples, les données peuvent être des faits liés à tout objet considéré. Par exemple, un nom un âge, une taille etc.

En informatique, une base de données est la pièce centrale des dispositifs de collecte, mise en forme, stockage et utilisation d'informations. Ce dispositif comporte un système de gestion de base de données, qu’on appelle SGBD. Un SGBD est un ensemble de programmes qui permet à ses utilisateurs d'accéder, de manipuler ainsi que de contrôler l'accès a une base de données, tout en cachant la complexité des opérations exécutées.
Les opérations de recherche et de manipulation des données peuvent être exprimées sous forme de requêtes dans un langage informatique reconnu par le SGBD. Le langage sql est le langage informatique le plus populaire.

Le SQL est un langage standard pour traiter les données d’une bases de données relationnelles. La programmation SQL peut être utilisée efficacement pour insérer, rechercher, mettre à jour et supprimer des enregistrements de base de données. Les instructions SQL s'écrivent d'une manière qui ressemble à celle de phrases ordinaires en anglais. Cette ressemblance voulue vise à faciliter l'apprentissage et son utilisation.

Pour notre projet, le domaine considéré est le langage de manipulation de données simple sans imbrication.

## Modélisation / Conception

--/ CHAKIB /-- 5 min

### Intro

Maintenant on va parler de la partie conception qui est la partie la plus importante pour réaliser un projet informatique.
Mes collegues et moi,on a pensé a decouper la modelisation du moteur de requetes SQl en deux parties principales ou élémentaires : 
premièrement comment stocker ou lire les données à partir d'un fichier CSV ?, ce qu'on a appelé structuration des données 
Deuxièment comment stocker ou interpreter la requête SQL ? ,ce qu'on a appelé Structure de la requête.

pour réaliser cette modelisation ,nous avons choisis l'approche orientée objet qui est parfaitement adaptée à notre problème
En  effet,  utiliser  cette  approche  nous  a permis de découper nos deux parties en plusieurs classes.

Pour Cela on a fait un Diagramme UML pour chacune des deux Parties.
 Voila le diagramme qu'on a réalisé pour stocker les données.
comme vous le voyer notre classe principale est en rouge qui est la classe Table , qui permet en quelques sortes de stocker
un fichier CSV

## Implémentation

--/ MASSY /-- 5 min

### Intro Implé

la partie d'implémentation consiste à trouver la meilleur façon de realiser les classes ainsi que les fonction precedement modéliser.

#### Choix du langage

Mais avant ça, nous avons tout d'abord choisie le langage de programmation a utilisé.

Le C++ est un langage orienté objet qui est donc parfaitement adapté à la modélisation que nous avons réaliser. C'est aussi l’un des principaux langages enseignées dans notre formation. Nous nous somme donc naturellement tourné vers ce langage.

#### Dév

Puis nous avons répartie le dév en 3 parties principales, que nous allons brievement détailler un peu plus tard :

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

<--New Slide >

### Développement

Revenont donc à la parie principale de l'implémentaion, Le dév.

#### Chargements des données

Tout d'abord nous avonc commencé par implémenter les classes que nous avions modélisées lors de la phase de conception.
Puis, la principale difficulté étais de trouver un moyen d'interpréter et d'éxtraire les données d'un fichier CSV.
Pour cela nous avons éctit une fonction, strsplit, qui se charge de segmenter une ligne du fichier en plusieurs chaine de caractères.

Cette fonction prend en paramètre une ligne d'un fichier CSV et un caractère séparateur, par défault une virgule, et retourne une instance de TabString (un tableau de chaine de caractères) qui contient les différentes valeurs.

Maintenant qu’on peut parser, on commence par lire la première ligne du fichier CSV et la passer à la fonction strsplit en stockant le resultat dans l’attribut nomAttributs de la classe Table. Pour le reste du fichier, on passe chaque ligne à la fonction strsplit et on ajoute le resultat dans la matrice valeursAttributs de la classe Table

<-- New Slide -->

#### La requete

Une fois les données chargées en mémoire, il faut à present intérpreter la requête SQL. On peut clairement découper une requête SQL en trois partie.

- Une partie Select,
- Une partie From,
- Une partie Where,

Cela nous a permis de developper trois méthode :

- Une fonction parseSelect(),
- Une fonction parseFrom(),
- Une fonction parseWhere(),

Ou chaqu'une d'entre elle parse une partie de la requete et stocke les données récuperer dans l'attribut correspondant de la classe Requete.

Maintenant que la requête a été interpretée, la question qui sait posé est comment notre programme va-t-il exécuter la requête sur les données chargées en mémoire ?

L'Éxecution de la requête se fait en trois étape clé :

- Le produit cartésien entre deux tables, ou chaque ligne de la première table est concatener avec chaqu'une des lignes de la deuxième table à travers deux boucle imbriqué.
- Puis on applique à la table resultante, la selection. La selection parcours les lignes de la table une par une. Si une ligne ne vérifie pas les condition spécifié dans le Where alors cette ligne est enlevée.
- Enfin il ne reste qu'a projeter les attributs que l'utilisateur a demandés. La fonction de projection parcours la table colonne par colonne et ne garde que les colonnes dont le noms apparait dans l'attribut select de la requête.

<-- New Slide -->

Maintenant je laisse mon collègue vous faire une petite démonstration du fonctionnement du programme.

--/ BOUZIDI /-- 3 minute

## Démonstration

Scénario ecrit. 2/3 minute.

--/ RAMZI /-- 2 minute

## Conclusion & Perspective
