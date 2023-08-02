# 2023_Analysis_monopol

## O projektu
- Analiza i primena alata je vršena na projektu **"Monopoly"**, koji se nalazi na adresi: https://gitlab.com/matf-bg-ac-rs/course-rs/projects-2020-2021/03-monopol. 

- Projekat je implementacija društvene igre "Monopol". Na početku partije, korisnik unosi svoje korisničko ime i bira jedan od ponuđenih tokena, a takođe može i da pročita pravila igre. Kada igra počne, pored korisnika, na tabli se nalaze još tri protivnička igrača, tri bota. Implementirana su sva pravila koja zaista postoje u ovoj igri. Pobednik je takmičar koji poslednji ostane u igri, odnosno onaj koji nije bankrotirao.

- Za implementaciju projekta korišćen je programski jezik **C++** i radni okvir **Qt**. 
- Alati koji su korišćeni:
    - **QtTest** - testiranje jedinica koda
    - **Gcov** - pokrivenost koda testovima
    - **Memcheck** - otkrivanje curenja memorije, upotreba memorije
    - **Massif** - upotreba memorije, raspolaganje hipom i stekom tokom igre
    - **Clang-tidy and Clazy** - statička analiza koda.

## Zaključak o projektu
- Problemi koji su uočeni na projektu:
    - curenje memorije - locirano je i otklonjeno u velikoj meri
    - nedostatak testova jedinica koda - delimično je testirano nekoliko klasa i utvrđen stepen pokrivenosti testovima
    - projektu nedostaje malo refaktorizacije, pojedini metodi su veoma veliki.
- Osim navedenog, projekat se ponaša u skladu sa očekivanim.