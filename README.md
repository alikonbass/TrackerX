Arduino Solar Tracker

Au démarrage, les panneaux solaires seront dans leur état neutre. Selon la valeur mesurée sur les LDR, les moteurs pas à pas feront tourner le panneau de sorte que le côté supérieur et le côté inférieur de la plaque ne diront pas plus que la tolérance. Si les côtés supérieur et inférieur ne sont pas dans la tolérance. Les LDR gauche et droit sont ensuite évalués de la même manière. Une fois que gauche contre droite et haut contre bas ont été comparés, le processus redémarre.

Dans ce code nous allons réaliser un panneau solaire intelligent qui suit automatiquement le mouvement du soleil durant la journée. Ce système assure une augmentation optimale du rendement du panneau solaire.

Pour cela on vous présentera l'ensemble du dispositif expérimental que nous avons réalisé et les étapes de réalisation du notre prototype.
 
Composantes 

Les composants sont à base électronique, et comprend un moteur pas à pas (17HS4401), un circuit de commande microcontrôleur Arduino (Arduino-Mega 2560 REV3), Driver de moteur pas à pas TB6560 3A, LDR 5mm, Bouton poussoir 6*6*5mm.

Outils de développement  

Logiciels utilisés ARDUINO, Fritzing

Montage
https://github.com/alikonbass/TrackerX/issues/1#issue-642572353

Nous avons également réalisé un diagramme . Ce dernier nous permet de définir les solutions constructives choisies pour répondre aux problématiques. 
https://github.com/alikonbass/TrackerX/issues/2#issue-642573819
