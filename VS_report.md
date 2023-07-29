## Unit Testing - QtTest

- Unit testovi, odnosno testovi jedinica koda, predstavljaju vrstu dinamičke verifikacije softvera. Pomoću njih se utvrđuje ispravnost manjih jedinica sistema, to mogu biti različite celine u zavisnosti od paradigme koja je korišćena.
- U ovom projektu dominira objektno-orijentisana paradigma, pa su u skladu sa tim testirani metodi na nivou klasa. Testirane su klase: **Player**, **Bank** i **Field**. Najpre je kreiran zaseban Qt projekat, tipa auto test project, koji automatski generiše kostur .pro fajla, kao i same klase tst_monopoly.cpp.  


- Testovi kojima se testira klasa **Player**:
    - void testSetNumberOfHousesBuildTrue();
        - Test proverava rad metoda set_number_of_houses kojim se postavlja vrednost parametra broja kuća na određenu vrednost u zavisnosti od vrednosti prodleđenog parametra - uvećava se.

    - void testSetNumberOfHousesBuildFalse();
        - Test proverava rad metoda set_number_of_houses kojim se postavlja vrednost parametra broja kuća na određenu vrednost u zavisnosti od vrednosti prodleđenog parametra - ostaje isti.

    - void testPayToBankSumLessThanBudget();
        - Test proverava rad metoda pay_to_bank kojim se vrsi isplata banci u jer je iznos manji od trenutnog budžeta igrača.

    - void testPayToBankSumMoreThanBudget();
        - Test proverava rad metoda pay_to_bank kojim se ne vrsi isplata banci jer je iznos veći od trenutnog budžeta igrača.

    - void testReceiveMoney();
        - Test proverava rad metoda receive_money kojim se povećava vrednost budžeta prilikom uplate neke sume igraču.

    - void testMoveForward();
        - Test proverava rad metoda move_forward kojim se vrši kretanje igrača po tabli i time mu se pomera tekuća pozicija.

    - void testCalculateTotalWorth()
        - Test proverava rad metoda calculate_total_worth koji racuna ukupnu vrednost svih poseda i nekretnina koje igrač poseduje.

    - void testAddPropertyNotSuccess();
        - Test proverava rad metoda add_property kojim se ne kupuje posed jer ne postoji dovoljna kolicina novca u budžetu.

    - void testAddPropertySuccess();
        - Test proverava rad metoda add_property kojim se kupuje uspesno posed jer postoji dovoljna kolicina novca u budžetu.

    - void testPayMortgage();
        - Test proverava rad metoda pay_mortgage koji visi proveru mogucnosti placanja hipoteke u zavisnosti od trenutnog budžeta.

    - void testUpdateNumEstates();
        - Test proverava rad metoda update_num_estates koji vrsi ažuriranje broja nekretnina u zavisnosti od njene vrste.

    - void testSellProperty();
        - Test provrava rad metoda sell_property kojim se vrsi prodaja citavog poseda. 

    - void testSellEstate();
        - Test proverava rad metoda sell_estate kojim se vrsi prodaja nekretnine sa prosleđenog poseda u zavisnosti od vrste nekretnine na posedu.

- Testovi kojima se testira klasa **Bank**:
    - void testPaySalary();
        - Test proverava rad metoda pay_salary kojim se isplaćuje plata iz budžeta banke.

    - void testBuyEstate();
        - Test proverava rad metoda buy_estate kojim banka kupuje nekretnine.

    - void testSellHouse();
        - Test proverava rad metoda sell_house kojim banka prodaje nekretnine tipa kuća novcem iz svog budžeta.

    - void testBuyProperty()
        - Test proverava rad metoda buy_property kojim banka prodaje posede novcem iz svog budžeta.

- Testovi kojima se testira klasa **Field**:
    - void testDestroyHotel();
        - Test proverava rad metoda destroy_hotel kojim se smanjuje broj hotela na posedu. 

    - void testDestroyHouse();
        - Test proverava rad metoda destroy_house kojim se smanjuje broj kuća na posedu. 


- U nastavku je data izlaz pokretanja projekta monopolyUnitTests: 
![image](./screenshots/unitTesting.png)

- **Zakljucak**: Sa slike se može primetiti da su svi napisani testovi uspešno prošli i  time se potvrđuje funkcionalnost testiranih metoda - oni zaista rade ono što se od njih očekuje. Međutim, to ne znači nuzno da su svi metodi ispravni. Vise o tome će biti reči u sledećoj temu - pokrivenosti koda testovima.
