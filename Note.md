# Fonctionnement des méthodes

## La classe Table

### La méthode `selection(TabCondtion)`

Cette méthode se charge d'éxecuter les requêtes de selection.
Pour cela cette méthode prend en paramètre un objet de la classe TabCondition

Pour executer une selection, on commence par déclarer une nouvelle Table vide (C'est la table qui va contenire le resultat de la selection) puis on parcours la table courante (La Table sur laquelle on execute la selection) tel que chaque ligne de la cette table est passer à la méthode `verifier(TabString ligne,TabString nomAttributs)`, de la classe TabCondition, avec la première ligne de la table (Le nom des attributs) qui renvoie TRUE si les conditions sont satisfaites. La ligne est ajouté à la table resultat si TRUE est renvoyé.

### La méthode `projection(TabString)`

Cette méthode, comme son nom l'indique, exécute une projection sut la Table Courante.

Le paramètre donnée est un TabString (tableau de chaine de caractère) qui contient le nom des attributs à projeter.

On commence par déclarer une Table vide qui va contenir le resultat. Le nom des attributs de cette table est initialiser à  la de l'argument donné (l'objet TabString donné en paramètre).

Puis pour chaque element d paramètre on ajoute la colonne coresspondante à la table resultat.