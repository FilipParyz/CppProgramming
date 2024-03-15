#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char firstName[50];
    char lastName[50];
    char phoneNumber[20];
};

void addContact(struct Contact contacts[], int *numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Ksiazka adresowa jest pelna.\n");
        return;
    }

    struct Contact newContact;

    printf("Podaj imie: ");
    scanf("%s", newContact.firstName);

    printf("Podaj nazwisko: ");
    scanf("%s", newContact.lastName);

    printf("Podaj numer telefonu: ");
    scanf("%s", newContact.phoneNumber);

    contacts[*numContacts] = newContact;
    (*numContacts)++;

    printf("Kontakt zostal dodany.\n");
}

void findContact(struct Contact contacts[], int numContacts, char lastName[]) {
    int found = 0;

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].lastName, lastName) == 0) {
            printf("Znaleziono kontakt:\n");
            printf("Imie: %s\n", contacts[i].firstName);
            printf("Nazwisko: %s\n", contacts[i].lastName);
            printf("Numer telefonu: %s\n", contacts[i].phoneNumber);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Nie znaleziono kontaktu o nazwisku %s.\n", lastName);
    }
}

void deleteContact(struct Contact contacts[], int *numContacts, char lastName[]) {
    int found = 0;

    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(contacts[i].lastName, lastName) == 0) {
            for (int j = i; j < *numContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*numContacts)--;
            found = 1;
            printf("Kontakt zostal usuniety.\n");
            break;
        }
    }

    if (!found) {
        printf("Nie znaleziono kontaktu o nazwisku %s.\n", lastName);
    }
}

void printContacts(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Ksiazka adresowa jest pusta.\n");
        return;
    }

    printf("Ksiazka adresowa:\n");

    for (int i = 0; i < numContacts; i++) {
        printf("Kontakt %d:\n", i + 1);
        printf("Imie: %s\n", contacts[i].firstName);
        printf("Nazwisko: %s\n", contacts[i].lastName);
        printf("Numer telefonu: %s\n", contacts[i].phoneNumber);
        printf("\n");
    }
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;
    char lastName[50];

    do {
        printf("Wybierz opcje:\n");
        printf("1. Dodaj kontakt\n");
        printf("2. Znajdz kontakt\n");
        printf("3. Usun kontakt\n");
        printf("4. Wyswietl wszystkie kontakty\n");
        printf("0. Wyjdz\n");
        printf("Wybor: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                printf("Podaj nazwisko kontaktu do znalezienia: ");
                scanf("%s", lastName);
                findContact(contacts, numContacts, lastName);
                break;
            case 3:
                printf("Podaj nazwisko kontaktu do usuniecia: ");
                scanf("%s", lastName);
                deleteContact(contacts, &numContacts, lastName);
                break;
            case 4:
                printContacts(contacts, numContacts);
                break;
            case 0:
                printf("Koniec programu.\n");
                break;
            default:
                printf("Nieprawidlowy wybor.\n");
                break;
        }

        printf("\n");
    } while (choice != 0);

    return 0;
}