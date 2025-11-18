## 🖥️ Abstract-VM

Le projet est une petite machine virtuelle en C++ qui exécute des programmes simples écrits dans des fichiers texte ressemblant à de l’assembleur.

La machine fonctionne instruction par instruction, du haut vers le bas, et utilise une pile (stack) pour traiter les données : les derniers éléments ajoutés sont les premiers à être utilisés.

Cette VM permet de simuler le fonctionnement d’une machine classique de manière simple, avec mémoire, calcul et exécution d’instructions.

---

## 🚀 Lancer le programme :

1. **Compiler** le programme :
   ```bash
   make
   ```
   (dans le dossier où se situe le `Makefile`)

2. **Exécuter** le programme :
   ```bash
   ./avm <file.avm>
   ```
   ou
   ```
   ./avm
   ```
---


## 🎥 L'entrée et la sortie du programme :

---

# 📥 L'entrée du programme :

<img width="118" height="293" alt="Screenshot from 2025-11-18 11-12-16" src="https://github.com/user-attachments/assets/fe0248d0-5278-485d-974e-3ad25e374da6" />

On peut voir des instructions, chacune des instructions sont définies dans le sujet pour connaitre les actions.

`<value>` est une valeur et peut être de type La différence est comment ces valeurs sont stockées :

| Type    | Description |
|---------|-------------|
| **int8**  | Entier sur 8 bits. |
| **int16** | Entier sur 16 bits. |
| **int32** | Entier sur 32 bits. |
| **float** | Nombre à virgule flottante simple précision sur 32 bits. |
| **double**| Nombre à virgule flottante double précision sur 64 bits. |

Comment sont définis les instructions :

| Instructions   | Définitions |                
|------------|-------------|
| **;**   | Mets en commentaire tout ce qui est après. |
| **push `<value>(n)`**   | Mets en haut de la pile `<value>`. |
| **pop**   | Retire du haut de la pile `<value>`. |
| **dump**| Affiche toute la stack. |
| **assert `<value>(n)`**   | Compare `<value>` avec la `<value>` du haut de la pile. |
| **add**   | Additionne les deux valeurs du haut de la pile et place le résultat au sommet |
| **sub**   | Soustrait la deuxième valeur du haut de la pile par la valeur du sommet et place le résultat au sommet. |
| **mul**  | Multiplie la deuxième valeur du haut de la pile par la valeur du sommet et place le résultat au sommet. |
| **div** | Divise la deuxième valeur du haut de la pile par la valeur du sommet et place le résultat au sommet. |
| **mod** | Calcule le reste de la division de la deuxième valeur du haut de la pile par la valeur du sommet, puis place le résultat au sommet. |
| **print**   |  Affiche le caractère ASCII correspondant si la valeur du sommet est un int8. |
| **exit**    | Arrête l’exécution de la VM. Les instructions après ne sont pas prises en compte. |
---

Le programme doit être capable de faire des opérations arithmétique peu importe les deux types, le résultat sera le type du plus grand.

# 📤 La sortie du programme :

```
./avm avm_test/exemple.avm
```
<img width="70" height="51" alt="Screenshot from 2025-11-18 11-51-46" src="https://github.com/user-attachments/assets/5b693dc3-e8aa-446c-9119-4215e6d6a572" />

stack = [], chaque élément garde son type.

On décompose :

```
1. push int32(42) | [42]
2. push int32(33) | [42, 33]
3. add | [75]
4. push float(44.55) | [75, 44.55]
5. mul | [3341.25]
6. push double(42.42) | [3341.25, 42.42]
7. push int32(42) | [3341.25, 42.42, 42]
8. dump | On lit de droite à gauche et on affiche la stack :
42
42.42
3341.25
9. pop | [3341.25, 42.42]
10. assert double(42.42) | On compare [42.42] avec 42.42
11. exit | On arrête le programme
```

L'étape 10 n'affiche rien car l'égalité est vraie.

Le programme s'arrête à la première erreur rencontrée.

# 🔻 Différences au lancement :

1. Quand on lance ```./a.out <file.gmr>```, il s'arrête soit quand le fichier est fini avec une erreur (il faut un exit pour finir proprement).
Le programme s'arrête quand il rencontre "exit".

2. Quand on lance ```./a.out```, pour quitter le terminal on doit écrire ";;", si il n'y a pas eu "exit", on a une erreur. Si on fait "exit", alors toutes les autres instructions seront ignorées et il faudra écrire ";;" pour quitter proprement.

## ⭐ Bonus

Le programme continue en ignorant les lignes qui comportent des erreurs.

Le code permet d'exécuter plusieurs instructions en une ligne.

## 🚀 Lancer le programme :

1. **Compiler** le programme :
   ```bash
   make bonus
   ```
   (dans le dossier où se situe le `Makefile`)

2. **Exécuter** le programme :
   ```bash
   ./avm_bonus <file.avm>
   ```
   ou
   ```
   ./avm_bonus
   ```
---

# ➕ Ajout instructions :

| Instructions   | Définitions |                
|------------|-------------|
| **rdump**   | Affiche toute la stack à l'envers. |
| **swap**   | Échange les deux valeurs en haut de la pile. |
| **min**   | Affiche la valeur la plus petite (tout type confondu). |
| **max**| Affiche la valeur la plus grande (tout type confondu). |
---

## ⚙️ Code :

1. Vérification des paramètres.

2. Si il y a un paramètre on essaie d'ouvrir le fichier. On rentre dans une boucle qui va lire chaque ligne.

3. Parsing d'une string en vector<string> pour séparer à chaque espace.

4. Passage sur tout le vector avec un lexer pour sélectionner les instructions pour s'adapter à celles qui prennent un paramètre.

5. Exécution de l'instruction.

6. Le code continue jusqu'à "exit" pour le lancement avec fichier et ";;" sans fichier.

## 💬 Explications

La classe principale à une stack<IOperand *>, le but était de rendre le code le plus polyvalent en évitant les répétitions.
L'utilisation de template à permis d'éviter la répétition des déclarations :
```
IOperand const * createInt8( std::string const & value ) const;
IOperand const * createInt16( std::string const & value ) const;
IOperand const * createInt32( std::string const & value ) const;
IOperand const * createFloat( std::string const & value ) const;
IOperand const * createDouble( std::string const & value ) const;
```

L'utilisation d'un switch case qui répertorie les différents types permets d'épurer le code.

Exemple de la création d'un enum :

<img width="709" height="351" alt="Screenshot from 2025-11-18 14-10-23" src="https://github.com/user-attachments/assets/2023aef2-5b99-47c9-aac3-c595bf8de7f8" />

La même opération a été faite pour les instructions, cela permet de faire évoluer le code si on souhaite en rajouter :

<img width="583" height="616" alt="Screenshot from 2025-11-18 14-11-52" src="https://github.com/user-attachments/assets/1f2fcc7a-4c47-4cdf-9a67-ad0317b976ab" />

Une autre façon d'éviter la répétition :

Pour les opérateurs on doit toujours, récupérer les éléments les plus haut de la pile, vérifier, sécuriser, nettoyer la mémoire et envoyer le résultat dans la pile donc :

<img width="847" height="768" alt="Screenshot from 2025-11-18 14-15-06" src="https://github.com/user-attachments/assets/8f4ea56f-c816-4211-a835-82bc1ed3d7c3" />

