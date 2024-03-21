#include <iostream>
#include <Apartment.h>
#include <User.h>
#include <Reservation.h>
#include <limits>

int main() {

    Apartment Ap1("12rg3g0", "Benidorm, Spain", "Rental Unit", "Apartment Ideal to enjoy Playa de Benidorm, in the heart of Playa de Poniente. Views from the living room to the ocean and the Isle of Benidorm.", 4, 5, 823);
    Apartment Ap2("1wd27", "Santona, Spain", "Duplex", "Unique oceanfront location within a few meters from the beach. Very large terrace to enjoy.", 4, 6, 795);
    Apartment Ap3("323w", "Altea, Spain", "Villa", "Beautiful villa with a private pool and a hot tub in Altea’s prime location, on Don Cayo golf course and nestled away from highway noise. Ideal for big families or groups.", 4, 4, 950);
    Apartment Ap4("56sf7", "Florence, Italy", "Rental Unit", "Chez Geraldine is an apartment just outside the historical center. It’s predominantly a residential district, but the cathedral, Galleria dell'Accademia, and Piazza San Marco are a 15-minute walk away. Food stores, restaurants, and bars are close by.", 3, 5, 1466);
    Apartment Ap5("9g65", "Dubrovnik, Croatia", "Rental Unit", "The apartment is perched on a small hill in Montovjerna, offering stunning views of the Adriatic Sea. Dubrovnik's Old Town is around a five-minute drive away, while the nearest beach, Bellevue, is around 300 metres away.", 4, 7, 701);
    Apartment Ap6("hdhsa", "Malaga, Spain", "Rental Unit", "Our vacation apartment with terrace and sea view is located on the beachfront, in the Huelin area. The seafront promenade and Plaza de Huelin are just 20 meters away.", 4, 7, 513);
    Apartment Ap7("dsaa53", "A Coruna, Spain", "Mansion", "La Casa de la Pradera is located in A Bana, A Coruna, Galicia. It is located 50 km from O Grove.", 4, 4, 498);

    Reservation r;
    r += Ap1; r += Ap2; r += Ap3; r += Ap4; r += Ap5; r += Ap6; r += Ap7;

    std::cout<<"Welcome to our apartment rental management system! Are you looking to rent an apartment while travelling OR would you like to put your apartment up for rent? Then, you're in the right place. Press Enter to continue browsing.";
    std::cin.get(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<std::endl<<"An interactive menu will be displayed to improve your user experience. Please select your choice of browsing:"<<std::endl;

    User current_user;
    int choice_differentiate_users, no_apts, choice_display;
    bool credentials = false;
    std::cout<<"1. Search for an apartment to rent\n2. Update/ upload details about an apartment I own\n3. Exit"<<std::endl;
    std::cin>>choice_differentiate_users; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<std::endl<<"Loading..."<<std::endl;
    switch(choice_differentiate_users)
    {
        case 1:
            std::cout<<"------- Tenant's view -------"<<std::endl;
            break;
        case 2:
            std::cout<<"------- Host's View -------"<<std::endl;
            std::cout<<"You must create an account before proceeding to upload details about an apartment."<<std::endl;
            std::cin>>current_user;
            current_user.loginMenu(current_user, credentials);
            if(credentials)
            {
                std::cout<<" Account was created successfully. Your account details:"<<std::endl;
                std::cout<<current_user<<std::endl;
                std::cout<<"How many apartments will your portfolio contain? Enter the number of apartments you would like to list on the market."<<std::endl;
                std::cout<<"Apartments to list: ";
                std::cin>>no_apts;
                for(int i = 0; i < no_apts; i++)
                {
                    Apartment Ap;
                    std::cin>>Ap;
                    r += Ap;
                }
                std::cout<<"Added successfully to the catalog."<<std::endl;
                std::cout<<"Would you like to see the updated version of the latest listed apartments?"<<std::endl;
                std::cout<<"1. Yes\n2. No"<<std::endl;
                std::cin>>choice_display;
                if(choice_display == 1)
                {
                    std::cout<<r;
                }
                std::cout<<"Thank you for choosing our services."<<std::endl;
            } else
            {
                std::cout<<" Account was not created. Stop and run this script again."<<std::endl;
            }
            break;
        case 3:
            break;
        default:
            std::cout<<"Invalid"<<std::endl;
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
