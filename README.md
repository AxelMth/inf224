Question 4 :

Ces méthodes sont appelées méthodes abstraites. Il faut les déclarer virtual dans la classe mère et spécifier qu'elles ne seront pas implémentées dans la classe mère mais dans les classe filles en faisant :
	
	virtual void affiche() = 0

En créeant des objets fils de la classe mère, celle-ci n'est plus instanciable car elle devient ABSTRAITE.

Question 5 :

C'est la propriété de polymorphisme du C++ qui permet cela. Le tableau contiendra des pointeurs.

Question 6 :

Pour que le tableau ait plein contrôle sur ses données il faut que le getTab() renvoie une copie du tableau. 

Question 7 : 

Il faut utiliser un delete pour tous les objets dont les variables d'instances sont des pointeurs. Cela empêche les fuites mémoires. Ici, seule la classe Film doit contenir un delete tab[] dans son destructeur.
De même, pour la copie d'un Film, il est nécessaire d'opérer une copie profonde pour empêcher aux attributs tab de deux films de pointer vers la même case mémoire.

Question 10 :

Pour empêcher une classe d'appeler son constructeur, on peut par exemple redéfinir l'opérateur new. Sinon pour permettre à la table (<=> base de données)  d'être la seule capable d'appeler le constructeur des objets qu'elle contient, on déclare protected les contructeurs des objets et on déclare la table en tant que friend.

Question 11 :

Ici, la méthode la plus simple est de déclarer la fonction processRequest en tant que friend dans la table.
