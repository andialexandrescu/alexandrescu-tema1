#include <iostream>
#include <array>

#include <Apartment.h>
#include <User.h>
#include <Reservation.h>

using namespace std;

int main() {

    Apartment Ap1("Benidorm, Spain", "Rental Unit", "Apartment Ideal to enjoy Playa de Benidorm, in the heart of Playa de Poniente. Views from the living room to the ocean and the Isle of Benidorm.", 4, 823);
    Apartment Ap2("Santona, Spain", "Duplex", "Unique oceanfront location within a few meters from the beach. Very large terrace to enjoy.", 5, 795);
    Apartment Ap3("Altea, Spain", "Villa", "Beautiful villa with a private pool and a hot tub in Altea’s prime location, on Don Cayo golf course and nestled away from highway noise. Ideal for big families or groups.", 6, 950);
    Apartment Ap4("Florence, Italy", "Rental Unit", "Chez Geraldine is an apartment just outside the historical center. It’s predominantly a residential district, but the cathedral, Galleria dell'Accademia, and Piazza San Marco are a 15-minute walk away. Food stores, restaurants, and bars are close by.", 3, 1466);
    Apartment Ap5("Dubrovnik, Croatia", "Rental Unit", "The apartment is perched on a small hill in Montovjerna, offering stunning views of the Adriatic Sea. Dubrovnik's Old Town is around a five-minute drive away, while the nearest beach, Bellevue, is around 300 metres away.", 4, 701);
    Ap1.printApartment();
    std::cout<<endl;
    Ap2.printApartment();
    std::cout<<endl;
    Ap3.printApartment();
    std::cout<<endl;
    Ap4.printApartment();
    std::cout<<endl;


    std::cout<<"Welcome to our apartment rental management system! Are you looking to rent an apartment while travelling OR would you like to put your apartment up for rent? Then, you're in the right place. Press any key to continue browsing.";
    std::cin.get();
    std::cout<<"An interactive menu will be displayed to improve your user experience. Please select your choice of browsing:"<<endl;
    int choice_differentiate_users;
    std::cout<<"1. Search for an apartment to rent\n2. Update/ upload details about an apartment I own"<<endl;
    std::cin>>choice_differentiate_users;
    std::cout<<endl<<"Loading..."<<endl;
    switch(choice_differentiate_users)
    {
        case 1:
            cout<<"Tenant's view";
            break;
        case 2:
            cout<<"Host View";
            break;
        default:
            cout<<"Invalid"<<endl;
            return 1;
    }

    /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];
    ///
    ///////////////////////////////////////////////////////////////////////////
    ///                Exemplu de utilizare cod generat                     ///
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    return 0;
}
