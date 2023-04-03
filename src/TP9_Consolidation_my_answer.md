Question : Dans le graphe ci-dessus, pourquoi n’a-t-on pas représenté de relation entre last_wheel et wheels[3] ?

last_wheel est une copy, l'utilisateur a demandé à ce que last_wheel ne soit pas une référence
 // comment construire une wheel à partir d'une wheel&
 !! auto ne prends pas forcément le type qu'il y a à droite 

 auto last = machine.back();
 => _wheel_ = _wheel&_

Question : Dans le graphe d’ownership, comment sont représentés les pointeurs-nus ? 
Comment est représenté un pointeur nul ? En terme de code, quelles sont les différences principales entre un pointeur-nu et une référence ?

un pointeurs-nus est représenté avec un *
pointeurs-nul => possède une référence vers le symbole vide

La grosse différence est que avec les pointeurs on peut modifier à l'intérieur de la case mais pas avec des références
ils sont tout les 2 non owning

Pratique : Dessiner le graphe d’ownership correspondant au code ci-dessous. Vous pouvez
omettre de représenter les attributs size.

b1 

b2
## Question : Pourquoi le second parent de June ne référence pas directement la case
miguel_junior ?

MiguelJunior est une unique_ptr

## Question : A la suite de la destruction du contenu de miguel_junior, quel problème est
mis en avant par le graphe d’ownership ?

parents[0] devient une dandlling reference

## Question : Lorsqu’on écrit pokeball.pokemon = std::move(pikachu), est-ce que
pikachu est déplacé ? Que se passe-t-il réellement dans la mémoire lors d’un move ?

Pikachu n'est pas déplacé, seul les pointeurs ont changés : pikachu ptr vers nul et pokemon ptr mtn vers le contenu de Pokemon Buffer (content de pikachu)

Question : Quel problème apparaît dans le graphe ci-dessus ? Généralisez le problème et
déduisez-en la série d’opérations qu’il ne faut pas faire lorsqu’on utilise un std::vector<T>.
Proposez des solutions qui permettent d’éviter le problème.


la référence first_product n'a pas été update lors de la réallocation
Ne pas faire des références sur des objects d'un vector, ne pas modifier les pointers pointant sur un element d'un vecteur
privilégier les const refs mais ils sont pas réassignable mieux vaut des utiliser des unique_pointer



ist == list chainé