# Fonctionnement des méthodes

## La classe Table

### La méthode `jointure(table)`

La jointure est un produit cartésien entre un ou plusieurs tableaux donnés par la personne qui effectue la requête puis d'une selection , les tableaux donnés sont séparé par des virgules lors de l'inissialitation de la requête .

Le produit cartésien entre un tableau A et B et un tableau composé de l'ensemble des couples possible entre leurs éléments réspectives , ainsi nous aurons en resultat un tableau A\*B.

Dans notre programme nous éxecutons la projection et selection sur le tableau finale .

Le produit cartésien est donc la base et la première tache qu'éffectue notre programme lors de l'éxecution.

Un exemple est plus parlant qu'une longue éxplication , prenons deux tableaux N et B nous éffectuons un PC entre ces deux tableaux N\*B, le résultat de l'éxecution de la jointure donnera un nouveau tableau ((N\*B) - Selection). 

### La méthode `projection(TabString)`

Cette méthode, comme son nom l'indique, exécute une projection sut la Table Courante.

Le paramètre donnée est un TabString (tableau de chaine de caractère) qui contient le nom des attributs à projeter.

On commence par déclarer une Table vide qui va contenir le resultat. Le nom des attributs de cette table est initialiser à  la de l'argument donné (l'objet TabString donné en paramètre).

Puis pour chaque element d paramètre on ajoute la colonne coresspondante à la table resultat.

### La méthode `selection(TabCondition)`

La selection est la ou les conditions finales afin d'effectuer la requête SQL , comme le but d'une requête SQL est d'extraire des infromations spécifique dans des bases de données , la selection permet de spécifier la requête plus en profondeur c.à.d de selectioner seulement les élements du ou des tableaux qui répondent a certain critères donné par la personne qui éxecute la requête et de faire la concaténation de ces éléments là .
 
Nous séparons chaque condition de selection avec des opérateurs logiques (noté : AND,OR) .

La condition en elle même est composé de 3 parties (noté : A \* B) où A et B sont les opérandes et \* l'opérateur , ces conditions sont des comparaisons entre A et B , ces comparaisons sont de base de type "CHAR" mais peuvent être de "INT" ou "DATE" en fonction de la condition en elle même.