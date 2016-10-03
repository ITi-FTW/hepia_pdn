#!/bin/sh

# PRISE EN MAIN - EXERCICE

# 1
mkdir TP1_commandes_shell

# 2
cd TP1_commandes_shell

# 3
mkdir -p TP1_commandes_shell/a/b/f TP1_commandes_shell/a/b/g/h TP1_commandes_shell/a/c/d TP1_commandes_shell/a/c/e

# 4
touch TP1_commandes_shell/a/c/d/ok

# 5
touch TP1_commandes_shell/a/ok TP1_commandes_shell/a/b/ok TP1_commandes_shell/a/b/g/ok TP1_commandes/a/b/g/h/touch

# 6
cd a/b/g/h && touch ../../ok

# 7
mv a/c/d/ok a/b/f/

# 8
cd a/b/f && cp ok ok.copy

# 9
ln -s ok.copy sauvegarde

# 10
touch TP1_commandes_shell/a/texte.txt && echo "kikou voici le texte" >> TP1_commandes_shell/a/texte.txt

# 11
ls -lh TP1_commandes_shell/a/

# 12
ls -la TP1_commandes_shell/a/

# 13
ls -la TP1_commandes_shell/a/

# 15
du -hs TP1_commandes_shell

# 16
du -hs TP1_commandes_shell

# 17
sleep 1 | ps -uf

# 18
ulimit

# 19
ulimit -a

# 20
ps -uf

# 21












