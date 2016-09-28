## 4.1 hepia

### Énoncé
Certaines techniques de codage de l’informations, utilisent les fichiers BITMAP pour insérer des informations secrètes. Dans cet exercice, nous vous présentons une méthode simple permettant de cacher un message textuel dans une image. La figure 3 contient un message secret. A première vue invisible, ça présence peut être détecté, soit en modifiant le contraste et la luminosité, soit en analysant son contenu avec un éditeur hexadécimal.  
Pour cette image (téléchargeable sur cyberlearn) vous trouverez un message caché entre les adresses 0x40 et 0x8F.


![alt text](https://gitlab.com/s.cardoso/hepia_pdn/raw/master/SLO/lab/representation-information/4-bonus/4.1-hepia/message_secret_hepia.bmp)



Saurez vous le retrouver ?  
**indice** : utilisez la table ASCII

### Solution

Données brutes (de 0x40 à 0x8F) :  
FE FF FE FE FF FE FE FF FE FE FF FE FE FE FE FE  
FE FF FF FE FF FF FE FE FE FF FF FE FF FF FF FF  
FE FF FF FF FE FF FF FE FE FF FF FE FE FF FE FF  
FE FE FF FE FE FE FE FE FE FF FE FF FE FE FF FF  
FE FF FE FE FF FF FE FE FE FF FE FE FF FF FF FF
	
|   Paquets de 8 octets   | Combinaison des LSB | HEXA |  ASCII  |
| ----------------------- | :-----------------: | :--: | :-----: |
| FE FF FE FE FF FE FE FF |   0 1 0 0 1 0 0 1   |  49  |    I    |
| FE FE FF FE FE FE FE FE |   0 0 1 0 0 0 0 0   |  20  | [space] |
| FE FF FF FE FF FF FE FE |   0 1 1 0 1 1 0 0   |  6C  |    l    |
| FE FF FF FE FF FF FF FF |   0 1 1 0 1 1 1 1   |  6F  |    o    |
| FE FF FF FF FE FF FF FE |   0 1 1 1 0 1 1 0   |  76  |    v    |
| FE FF FF FE FE FF FE FF |   0 1 1 0 0 1 0 1   |  65  |    e    |
| FE FE FF FE FE FE FE FE |   0 0 1 0 0 0 0 0   |  20  | [space] |
| FE FF FE FF FE FE FF FF |   0 1 0 1 0 0 1 1   |  53  |    S    |
| FE FF FE FE FF FF FE FE |   0 1 0 0 1 1 0 0   |  4C  |    L    |
| FE FF FE FE FF FF FF FF |   0 1 0 0 1 1 1 1   |  4F  |    O    |

**Message caché** : I love SLO