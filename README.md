## 2020 Oop Project - Team Exercise

## ΑΝΤΙΚΕΙΜΕΝΟΣΤΡΑΦΗΣ ΠΡΟΓΡΑΜΜΑΤΙΣΜΟΣ - 2020/2021 - Ομαδική Εργασία


Εκφώνηση: http://cgi.di.uoa.gr/~izambo/OOPproj_2021.pdf


### Προσωπικά Στοιχεία

__Όνομα__: Ιωάννης Ζαπάντης, Ντέιβιντ Μπούσι

__Α.Μ.__: sdi1900059, sdi1900127 (αντίστοιχα με τα ονόματα)


### Παρακάτω υπάρχει το documentation για την Υλοποίηση της Ομαδικής Εργασίας

### Documentation

Το `Project` αυτό αναφέρεται στην υλοποίηση της προσομοίωσης ενός παιχνιδιού ρόλων σε C++.
Τα 3 βασικά folders του είναι τα include, που περιλαμβάνει όλα τα header files, τα modules,
που περιλαμβάνει όλες τις υλοποιήσεις των συναρτήσεων των κλάσεων που χρησιμοποιήθηκαν και
του program, που περιλαμβάνει το αρχείο με την main συνάρτηση καθώς και ένα Makefile.

Μέσα στο include folder υπάρχει ένας υποφάκελος με όνομα `Grid` και περιέχει όλους τους
απαραίτητους ορισμούς για τον πλέγμα του παιχνιδιού καθώς και των "τετραγώνων" που
το απεικονίζουν. Στο Grid.h υπάρχουν οι βασικές συναρτήσεις που έχει πρόσβαση
ο "χρήστης" μέσα από την main για την εκτέλεση του παιχνιδιού.
Οι υλοποιήσεις τους με αναλυτικά σχόλια, βρίσκονται στο modules/Grid/Grid.cc .
Κάθε τετράγωνο του πλέγματος είναι ένα Square, του οποίου το header file βρίσκεται
στο include/Grid/Square.h και η υλοποίηση των συναρτήσεων (κυρίως βοηθητικών) μαζί με
αναλυτικά σχόλια βρίσκονται στο modules/Grid/Square/Square.cc .

Στα ίδια folders (για τα headers και για τα .cc) υπάρχουν και οι ορισμοί των παιδιών-κλάσεων
(χρήση κληρονομικότητας) των `Square`. Αυτά είναι το Market, το Common και το nonAccessible.
Η λειτουργία του καθενός αναλύεται εκτενώς στην εκφώνηση της εργασίας. Επίσης στις υλοποιήσεις των
συναρτήσεων, όπως και στους ορισμούς των κλάσεων υπάρχουν σχόλια που εξηγούν οποιαδήποτε ασάφεια υπάρξει.

Στο folder του `include` υπάρχει ο υποφάκελος `Item` που περιέχει το Item.h, Armor.h,
Potion.h και Weapon.h . Το Item.h περιέχει την βασική κλάση που περιέχει όλα τα στοιχεία
και συναρτήσεις που είναι απαραίτητα για την δημιουργία κάθε είδους αντικειμένου, καθώς και
για την γενική τους συμπεριφορά. Πρόκειται για μια abstract κλάση. Τα παιδιά της (που κληρονομούν απο την Item)
είναι τα Armor, Potion και Weapon. Η καθεμία από αυτές έχει έξτρα στοιχεία και έξτρα συναρτήσεις προσαρμοσμένες
για τις ανάγκες του καθενός είδους αντικειμένου. Οι υλοποιήσεις και των 4 header files βρίσκονται
στον υποφάκελο του modules με όνομα Item. Λεπτομέρειες ως προς το αλγοριθμικό κομμάτι του κάθε αρχείου,
υπάρχουν στα σχόλια του καθενός και για αυτό προτιμήθηκε να μην αναφερθούν και εδώ.

Κατά την διαδικασία προσθήκης όπλου σε ήρωα γίνεται ο συμβιβασμός ότι το πρώτο όπλο του ήρωα θα μπει
στο αριστερό του χέρι. Με αυτόν τον τρόπο αρκεί σε κάθε επόμενη προσθήκη όπλου να ελέγχεται αν το όπλο
στο αριστερό του χέρι ή το όπλο που πρόκειται να προστεθεί απαιτούν δύο χέρια. Σε αυτήν την περίπτωση,
το νέο όπλο αντικαθιστά το όπλο του αριστερού χεριού. Αντίθετα, αν το όπλο στο αριστερό χέρι του ήρωα
δεν απαιτεί την χρήση του δεξιού χεριού και το νέο όπλο μπορεί να χειριστεί από ένα χέρι, τότε
το νεό όπλο αντικαθιστά το όπλο του δεξιού χεριού.

Σε κάθε αλλαγή όπλου ή ασπίδας, το αντικείμενο που αντικαθίσταται αποθηκεύεται στο
inventory του ήρωα για πιθανή μελλοντική χρήση.

Κατά την επίθεση ενός τέρατος σε έναν ήρωα ελέγχεται αν ο ήρωας διαθέτει ασπίδα. Αν έχει, η ασπίδα
απορροφά το ποσό ζημιάς που προκαλεί το τέρας και μπορεί να απορροφήσει, ενώ το υπόλοιπο ποσό ζημιάς
το χρεώνεται η ζωή του ήρωα. Αν δεν έχει ασπίδα, ολόκληρο το ποσό ζημιάς το χρεώνεται ο ήρωας.

Κάτι αντίστοιχο συμβαίνει και με τα τέρατα, όπου το ποσό άμυνας το οποίο αϕαιρείται από τη ζημιά
που δέχονται σε μια επίθεση των ηρώων χρησιμεύει ουσιαστικά σαν ασπίδα.

Κατά την επίθεση ενός ήρωα ή τέρατος, αποφασίζει η Common αν θα προκληθεί ζημιά στον αντίπαλο,
λαμβάνοντας υπόψιν την ευκινησία του ήρωα και την ικανότητα αποφυγής μίας επίθεσης των τεράτων.
Ο λόγος είναι ότι κάθε ζωντανό ων επιθυμεί να αποφύγει όλες τις επιθέσεις, επομένως είναι δικαιότερο η
Common να αποφασίζει αν τελικά θα προκληθεί επίθεση, "ως αντικειμενικός κριτής".
Ομοίως, έλεγχοι για το αν ο ήρωας διαθέτει χρήματα για την αγορά ενός αντικειμένου και το ποσό ζημιάς
που προκαλείται σε μία επίθεση αποφασίζονται από την Common, αφού οι κλάσεις τής παρέχουν
τους απαραίτητους getters, ώστε να είναι αυτό δυνατό.

Τα ποσά που δεν προσδιορίζονται από την εκφώνηση (πχ η τιμή αντικειμένων στην αγορά,
το αρχικό ποσό χρημάτων που διαθέτουν οι ήρωες κλπ) ορίζονται ως σταθερές στο αρχείο
constants.h που βρίσκεται στον φάκελο include.

Για τα ονόματα όλων των αντικειμένων γίνεται χρήση των βοηθητικών αρχείων που βρίσκονται στον φάκελο samples.


- Στο folder με όνομα `program`, υπάρχει το `main.cc` και ένα `Makefile`.

- Στο main.cc υπάρχει η main συνάρτηση που ο χρήστης παίζει το παιχνίδι. Αρχικά, η main δημιουργεί 3 ήρωες
και στην συνέχεια δημιουργεί τον χώρο του παιχνιδιού (grid). Ύστερα ξεκινάει ένα while loop
που λήγει μόνο όταν ο χρήστης επιλέξει να τερματίσει το παιχνίδι. Σε διαφορετική περίπτωση δίνονται
όλες οι επιλογές στον χρήστη να μετακινηθεί, αν δει τους ήρωές του με τα αντικείμενά τους κλπ.

- Στο Makefile υπάρχουν κάποιες απλές εντολές. Αυτές χρησιμεύουν στη μεταγλώττιση,
στο τρέξιμο του προγράμματος και στον καθαρισμό των αρχείων που δημιουργήθηκαν.
Με την εντολή make γίνεται η μεταγλώττιση, με το run τρέχει το πρόγραμμα,
με το clean διαγράφονται όλα τα αρχεία που δημιουργήθηκαν
και με το valgrind γίνεται έλεγχος για leaks (δεν υπάρχουν).

### Μεταγλώττιση και εκτέλεση

Η πλήρης εντολή μεταγλώττισης είναι: g++ -o main main.cc (όλα τα υπόλοιπα αρχεία)  
Η εντολή για να τρέξει το πρόγραμμα είναι: `./game` ή, με την βοήθεια του Makefile τρέχοντας, `make run` στον φάκελο `program`.  
Πιο λεπτομερής περιγραφή αυτών φαίνονται στο Makefile.
