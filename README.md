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

