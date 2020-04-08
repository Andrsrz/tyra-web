#include <iostream>
#include "../include/AddPet.hpp"

const char* WINDOW_TITLE = "Agregar Mascota";
const char* LABEL_PET = "Agregar una Mascota";
const char* LABEL_PET_SPECIE = "Especie :";
const char* LABEL_PET_BREED = "Raza :";
const char* LABEL_PET_NAME = "Nombre :";
const char* LABEL_PET_BIRTHDAY = "Fecha de Nacimiento :";
const char* LABEL_OWNER_NAME = "Nombre (Dueño) :";
const char* LABEL_OWNER_LAST_NAME = "Apellido :";
const char* LABEL_OWNER_GENDER = "Genero :";
const char* LABEL_OWNER_EMAIL = "Correo :";
const char* LABEL_OWNER_ADDRESS = "Direccion :";
const char* LABEL_OWNER_PHONE_NUMBER = "Telefono :";
const char* BUTTON_ADD_PET = "Agregar";
const char* CLEAN_ENTRY = "";
const bool WINDOW_RESIZABLE = false;
const bool GRID_ROW_HOMOGENEOUS = true;
// Avoid magic numbers
const int PHONE_MAX_LENGTH = 10;
const int WINDOW_WIDTH = 300;
const int WINDOW_HEIGHT = 500;

AddPet::AddPet() : labelPet(::LABEL_PET),
                   labelPetSpecie(::LABEL_PET_SPECIE),
                   labelPetBreed(::LABEL_PET_BREED),
                   labelPetName(::LABEL_PET_NAME),
                   labelPetBirthday(::LABEL_PET_BIRTHDAY),
                   labelOwnerName(::LABEL_OWNER_NAME),
                   labelOwnerLastName(::LABEL_OWNER_LAST_NAME),
                   labelOwnerGender(::LABEL_OWNER_GENDER),
                   labelOwnerEmail(::LABEL_OWNER_EMAIL),
                   labelOwnerAddress(::LABEL_OWNER_ADDRESS),
                   labelOwnerPhoneNumber(::LABEL_OWNER_PHONE_NUMBER){
    // this = the window
    this->set_title(::WINDOW_TITLE);
    this->set_default_size(::WINDOW_WIDTH, ::WINDOW_HEIGHT);
    this->set_resizable(::WINDOW_RESIZABLE);

    // Add Main Grid to Window
    this->add(gridMain);
    // Set same size for rows
    gridMain.set_row_homogeneous(::GRID_ROW_HOMOGENEOUS);
    // Populate Grid
    // attach(widget, column, row, width, height)
    gridMain.attach(labelPetSpecie, 0, 0, 1, 1);
    gridMain.attach(entryPetSpecie, 1, 0, 3, 1);
    gridMain.attach(labelPetBreed, 0, 1, 1, 1);
    gridMain.attach(entryPetBreed, 1, 1, 4, 1);
    gridMain.attach(labelPetName, 0, 2, 1, 1);
    gridMain.attach(entryPetName, 1, 2, 3, 1);
    gridMain.attach(labelPetBirthday, 0, 3, 1, 1);
    gridMain.attach(entryPetBirthday, 1, 3, 3, 1);
    gridMain.attach(labelOwnerName, 0, 4, 1, 1);
    gridMain.attach(entryOwnerName, 1, 4, 3, 1);
    gridMain.attach(labelOwnerLastName, 0, 5, 1, 1);
    gridMain.attach(entryOwnerLastName, 1, 5, 3, 1);
    gridMain.attach(labelOwnerGender, 0, 6, 1, 1);
    gridMain.attach(entryOwnerGender, 1, 6, 3, 1);
    gridMain.attach(labelOwnerEmail, 0, 7, 1, 1);
    gridMain.attach(entryOwnerEmail, 1, 7, 3, 1);
    gridMain.attach(labelOwnerAddress, 0, 8, 1, 1);
    gridMain.attach(entryOwnerAddress, 1, 8, 3, 1);
    gridMain.attach(labelOwnerPhoneNumber, 0, 9, 1, 1);
    entryOwnerPhoneNumber.set_max_length(::PHONE_MAX_LENGTH);
    gridMain.attach(entryOwnerPhoneNumber, 1, 9, 3, 1);
    buttonAddPet.set_label(::BUTTON_ADD_PET);
    gridMain.attach(buttonAddPet, 0, 10, 4, 1);

    // Button event
    buttonAddPet.signal_clicked().connect(sigc::mem_fun(*this, &AddPet::on_button_add_pet));

    // And show it
    this->show_all_children();
}

//! Class destructor
AddPet::~AddPet(){}

//!
void AddPet::on_button_add_pet(){
    // Check entries
    if((entryPetSpecie.get_text() == ::CLEAN_ENTRY) ||
       (entryPetBreed.get_text() == ::CLEAN_ENTRY) ||
       (entryPetName.get_text() == ::CLEAN_ENTRY) ||
       (entryPetBirthday.get_text() == ::CLEAN_ENTRY) ||
       (entryOwnerName.get_text() == ::CLEAN_ENTRY) ||
       (entryOwnerLastName.get_text() == ::CLEAN_ENTRY) ||
       (entryOwnerGender.get_text() == ::CLEAN_ENTRY) ||
       (entryOwnerEmail.get_text() == ::CLEAN_ENTRY) ||
       (entryOwnerAddress.get_text() == ::CLEAN_ENTRY) ||
       (entryOwnerPhoneNumber.get_text() == ::CLEAN_ENTRY)){
        std::cout << "Enter all data\n";
        return;
    }

    // Save data
    std::cout << "Passed!\n";

    // Clean entries
    entryPetSpecie.set_text(::CLEAN_ENTRY);
    entryPetBreed.set_text(::CLEAN_ENTRY);
    entryPetName.set_text(::CLEAN_ENTRY);
    entryPetBirthday.set_text(::CLEAN_ENTRY);
    entryOwnerName.set_text(::CLEAN_ENTRY);
    entryOwnerLastName.set_text(::CLEAN_ENTRY);
    entryOwnerGender.set_text(::CLEAN_ENTRY);
    entryOwnerEmail.set_text(::CLEAN_ENTRY);
    entryOwnerAddress.set_text(::CLEAN_ENTRY);
    entryOwnerPhoneNumber.set_text(::CLEAN_ENTRY);
}