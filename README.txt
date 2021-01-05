TODO!

TODO: constants!!!
    - Adjust monster's level when they create

TODO: Check, in a call, main_game

TODO: decide where functions will be (Hero or Grid)

TODO: check when use item or spell in a fight. it could not have item/spell the selected hero (data problem. We can assume user gets correct data)

TODO: market closes after only one buy



## 2020 Oop Project - Team Exercise

## ΑΝΤΙΚΕΙΜΕΝΟΣΤΡΑΦΗΣ ΠΡΟΓΡΑΜΜΑΤΙΣΜΟΣ - 2020/2021 - Ομαδική Εργασία


Εκφώνηση: http://cgi.di.uoa.gr/~izambo/OOPproj_2021.pdf


### Προσωπικά Στοιχεία

__Όνομα__: Ιωάννης Ζαπάντης, Ντέιβιντ Μπούσι

__Α.Μ.__: sdi1900059, sdi1900127 (αντίστοιχα με τα ονόματα)


### Παρακάτω υπάρχει το documentation για Υλοποίηση της Ομαδικής Εργασίας

### Documentation

    Το Project αυτό αναφέρεται στην υλοποίηση της προσομοίωσης ενός παιχνιδιού ρόλων σε C++. Τα 3 βασικά folders του είναι τα include, που
    περιλαμβάνει όλα τα header files, τα modules, που περιλαμβάνει όλες τις υλοποιήσεις των συναρτήσεων των κλάσεων που χρησιμοποιήθηκαν και
    του program, που περιλαμβάνει το αρχείο με την main συνάρτηση καθώς και ένα Makefile.

    Μέσα στο include folder υπάρχει ένας υποφάκελος με όνομα Grid και περιέχει όλους τους απαραίτητους ορισμούς για τον πλέγμα του παιχνιδιού
    καθώς και των "τετραγώνων" που το απεικονίζουν. Στο Grid.h υπάρχουν οι βασικές συναρτήσεις που έχει πρόσβαση ο "χρήστης" μέσα από την main
    για την εκτέλεση του παιχνιδιού. Οι υλοποιήσεις τους με αναλυτικά σχόλια, βρίσκονται στο modules/Grid/Grid.cc . Κάθε τετράγωνο του πλέγματος
    είναι ένα Square, του οποίου το header file βρίσκεται στο include/Grid/Square.h και η υλοποίηση των συναρτήσεων (κυρίως βοηθητικών) μαζί με
    αναλυτικά σχόλια βρίσκονται στο modules/Grid/Square/Square.cc .

    Στα ίδια folders (για τα headers και για τα .cc) υπάρχουν και οι ορισμοί των παιδιών-κλάσεων (χρήση κληρονομικότητας) των Square. Αυτά είναι
    το Market, το Common και το nonAccessible. Η λειτουργία του καθενός αναλύεται εκτενώς στην εφκώνηση της εργασίας. Επίσης στις υλοποιήσεις των
    συναρτήσεων, όπως και στους ορισμούς των κλάσεων υπάρχουν σχόλια που εξηγούν οποιαδήποτε ασάφεια υπάρξει.

