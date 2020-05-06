#include <iostream>
#include <gtkmm/messagedialog.h>
#include <pqxx/pqxx>
#include "../include/AddPet.hpp"
#include "../include/Pet.hpp"
#include "../include/Owner.hpp"

const std::string WINDOW_TITLE = "Agregar Mascota";
const std::string LABEL_PET = "Agregar una Mascota";
const std::string LABEL_PET_SPECIE = "Especie :";
const std::string LABEL_PET_BREED = "Raza :";
const std::string LABEL_PET_NAME = "Nombre :";
const std::string LABEL_PET_BIRTHDAY = "Fecha de Nacimiento :";
const std::string LABEL_OWNER_NAME = "Nombre (Dueño) :";
const std::string LABEL_OWNER_LAST_NAME = "Apellido :";
const std::string LABEL_OWNER_GENDER = "Genero :";
const std::string LABEL_OWNER_EMAIL = "Correo :";
const std::string LABEL_OWNER_ADDRESS = "Direccion :";
const std::string LABEL_OWNER_PHONE_NUMBER = "Telefono :";
const std::string BUTTON_ADD_PET = "Agregar";
const std::string CLEAN_ENTRY = "";
const std::string MESSAGE_DIALOG_WARNING = "WARNING";
const std::string MESSAGE_DIALOG_WARNING_2 = "Ingresa todo los datos";
const bool WINDOW_RESIZABLE = false;
const bool GRID_ROW_HOMOGENEOUS = true;
const bool MESSAGE_DIALOG_MARKUP = false;
/* Avoid magic numbers */
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
	this->set_title(::WINDOW_TITLE);
	this->set_default_size(::WINDOW_WIDTH, ::WINDOW_HEIGHT);
	this->set_resizable(::WINDOW_RESIZABLE);

	this->add(gridMain);
	gridMain.set_row_homogeneous(::GRID_ROW_HOMOGENEOUS);
	/* Populate Grid */
	/* attach(widget, column, row, width, height) */
	gridMain.attach(labelPetSpecie, 0, 0, 1, 1);
	gridMain.attach(entryPetSpecie, 1, 0, 3, 1);
	gridMain.attach(labelPetBreed, 0, 1, 1, 1);
	gridMain.attach(entryPetBreed, 1, 1, 4, 1);
	gridMain.attach(labelPetName, 0, 2, 1, 1);
	gridMain.attach(entryPetName, 1, 2, 3, 1);
	gridMain.attach(labelPetBirthday, 0, 3, 1, 1);
	gridMain.attach(calendarPetBirthday, 1, 3, 3, 1);
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

	/* Events */
	buttonAddPet.signal_clicked().connect(sigc::mem_fun(*this, &AddPet::on_button_add_pet));

	this->show_all_children();
}

//! Class destructor
AddPet::~AddPet(){}

//!
void AddPet::on_button_add_pet(){
	/* The user may enter want to enter a new Pet with
	 * an empty entry. This prevents the user to do so.
	 * We don't want empty data in the database. */
	if((entryPetSpecie.get_text() == ::CLEAN_ENTRY) ||
		(entryPetBreed.get_text() == ::CLEAN_ENTRY) ||
		(entryPetName.get_text() == ::CLEAN_ENTRY) ||
		(entryOwnerName.get_text() == ::CLEAN_ENTRY) ||
		(entryOwnerLastName.get_text() == ::CLEAN_ENTRY) ||
		(entryOwnerGender.get_text() == ::CLEAN_ENTRY) ||
		(entryOwnerEmail.get_text() == ::CLEAN_ENTRY) ||
		(entryOwnerAddress.get_text() == ::CLEAN_ENTRY) ||
		(entryOwnerPhoneNumber.get_text() == ::CLEAN_ENTRY)){
		Gtk::MessageDialog dialog(*this,
									::MESSAGE_DIALOG_WARNING,
									::MESSAGE_DIALOG_MARKUP,
									Gtk::MESSAGE_WARNING,
									Gtk::BUTTONS_OK);
	dialog.set_secondary_text(::MESSAGE_DIALOG_WARNING_2);
		dialog.run();
		return;
	}

	// TODO Save data
	printf("Passed!\n");
	// Create object// s
	// Owner* myOwner = new Owner(std::string(entryOwnerName.get_text()),
	// 							std::string(entryOwnerGender.get_text()),
	// 							std::string(entryOwnerEmail.get_text()),
	// 							std::string(entryOwnerAddress.get_text()),
	// 							std::string(entryOwnerPhoneNumber.get_text()));

	// Pet* myPet = new Pet(std::string(entryPetSpecie.get_text()),
	// 						std::string(entryPetBreed.get_text()),
	// 						std::string(entryPetName.get_text()),
	// 						std::string(entryPetBirthday.get_text()),
	// 						myOwner);
	// TODO object serialization
	// std::string pet;
	// std::string fileExtention = ".dat";
	// pet = myPet->getName() + myOwner->getName() + fileExtention;

	// std::ofstream ofs(pet, std::ios::binary);
	// boost::archive::binary_oarchive oa(ofs);
	// oa << myPet;

	// Save to DB
	// try{
	//     pqxx::connection connection("postgresql://admin:1234@localhost/vet");
	//     std::cout << "Connected to " << connection.dbname() << std::endl;
	//     connection.prepare( "test", "INSERT INTO pet( id, binfile ) VALUES ($1, $2)" );
	//     pqxx::work work(connection);

	//     int id = 1;
	//     void * bin_data = oa;
	//     size_t bin_size = sizeof(bin_data);

	//     pqxx::binarystring blob( bin_data, bin_size );
	//     pqxx::result r = work.exec_prepared( "test" )( id )( blob ).exec();

	//     std::cout << "Making changes definite..." << std::endl;
	//     work.commit();
	//     std::cout << "OK!" << std::endl;
	// }catch(std::exception const& e){
	//     std::cerr << e.what() << std::endl;
	// }

	// delete myPet;
	// delete myOwner;

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
