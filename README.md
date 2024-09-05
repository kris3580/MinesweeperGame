# MinesweeperGame
Proiect în care se declară structurile conceptuale ale jocului Minesweeper.

### Reguli:
* Se dă un tabel de pătrățele pustii. La apăsarea unuia dintre pătrățele se vor divulga ce este în spatele acestuia. 
* La prima apăsare se divulgă doar pătrățele și numere. 
* Numerele indică câte bombe sunt în jurul numărului dat (părțile laterale și colțuri).
* La apăsarea unui pătrățel care la divulgarea acestuia este o bombă, jocul este pierdut. 
* La divulgarea tuturor pătrățelelor sub care nu este o bombă jocul se consideră câștigat. 
* Se pot utiliza steaguri pentru a nota unde sunt bombele deduse. 

### Descriere pe scurt a structurilor jocului

* `Game` gestionează stările jocului și trecerea de la una la alta al acestuia.
* `Input` gestionează intrările jucătorului.
* `Random` răspunde de generarea numerelor aleatoare utilizate pentru a determina unde se vor apărea bombele pe tabel.
* `Timer` gestionează cronometrul jocului (pornirea, oprirea, resetarea acestuia).
* `Difficulty` duce cont de dificultățile pe care jocului poate să le aibă (mărimea tabelului, numărul de bombe) și care din acestea este selectată
* `Cell` gestionează o oarecare celulă, și anume poziția acesteia pe tablă și tipul acesteia.
* `Grids` gestionează tabelele, și anume cel văzut de jucător și cel generat dinainte. Răspunde de generarea și resetarea tabelelor, dezvăluirea pătrățelelor, verificarea apăsării unei bombe etc.
* `GameEngine` răspunde de inițializarea și rularea jocului.



