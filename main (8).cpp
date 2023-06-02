#include <iostream>
#include <vector>
#include <string>
#include <ctime>

struct Note {
    std::string title;
    std::string content;
    std::time_t createdDate;
};

// Function untuk membuat sebuah catatan/note
void createNote(std::vector<Note>& notes) {
    Note newNote;
    std::cout << "Masukkan judul catatan: ";
    std::cin.ignore();
    std::getline(std::cin, newNote.title);
    std::cout << "Masukkan isi catatan: ";
    std::getline(std::cin, newNote.content);
    newNote.createdDate = std::time(nullptr);
    notes.push_back(newNote);
    std::cout << "Catatan sukses dibuat!\n";
}

// Fungsi untuk mencari indeks catatan berdasarkan judul
int MencariIndeksCatatan(const std::vector<Note>& notes, const std::string& title) {
    for (size_t i = 0; i < notes.size(); ++i) {
        if (notes[i].title == title ) {
            return i;
        }
    }
    return 1; // Return 1 jika catatan tidak ditemukan
}

// Function untuk menampilkan semua catatan yang ada
void displayNotes(const std::vector<Note>& notes) {
    if (notes.empty()) {
        std::cout << "Tidak ada catatan ditemukan!\n";
        return;
    }

    std::cout << "--------------------------------\n";
    std::cout << "Daftar catatan yang ada\n";
    std::cout << "--------------------------------\n";
    for (const auto& note : notes) {
        std::cout << "Judul: " << note.title << "\n";
        std::cout << "Tanggal pembuatan: " << std::ctime(&note.createdDate);
        std::cout << "--------------------------------\n";
    }
}

// Function untuk melihat isi catatan berdasakan judul 
   void viewNoteContent(const std::vector<Note>& notes) {
    std::cout << "Masukkan judul catatan=";
    std::cin.ignore();
    std::string title;
    std::getline(std::cin,title);
    int index =MencariIndeksCatatan(notes,title);

    if (index !=1) {
        std::cout << "--------------------------------\n";
        std::cout << "Judul: " << notes[index].title << "\n";
        std::cout << "Isi: " << notes[index].content << "\n";
        std::cout << "Tanggal pembuatan: " << std::ctime(&notes[index].createdDate);
        std::cout << "--------------------------------\n";
    } else {
        std::cout << "Judul catatan tidak valid!\n";
    }
}

// Function untuk mengedit catatan
void editNoteContent(std::vector<Note>& notes) {
    std::cout << "Masukkan judul catatan=";
    std::cin.ignore();
    std::string title;
    std::getline(std::cin, title);
    int index =MencariIndeksCatatan(notes, title);

    if (index !=-1) {
        std::cout << "Masukkan isi terbaru catatan: ";
        std::cin.ignore();
        std::getline(std::cin, notes[index].content);
        std::cout << "Isi catatan sudah terupdate!\n";
    } else {
        std::cout << "Judul catatan tidak valid!\n";
    }
}

// Function untuk menghapus catatan
void deleteNote(std::vector<Note>& notes) {
    std::cout << "Masukkan judul catatan=";
    std::cin.ignore();
    std::string title;
    std::getline(std::cin,title);
    int index =MencariIndeksCatatan(notes,title);

    if (index != -1) {
        notes.erase(notes.begin() + index);
        std::cout << "Catatan berhasil dihapus!\n";
    } else {
        std::cout << "Judul catatan tidak valid!\n";
    }
}

//menampilkan pilihan dan menerima input user
    int notesManager () { 
    int choice;
    
        std::cout << "Menu\n";
        std::cout << "1. Membuat catatan baru\n";
        std::cout << "2. Melihat semua catatan\n";
        std::cout << "3. Melihat isi catatan berdasarkan judul\n";
        std::cout << "4. Mengedit isi catatan\n";
        std::cout << "5. Menghapus catatan\n";
        std::cout << "6. Keluar\n";
        std::cout << "Masukkan pilihanmu: ";
        std::cin >> choice;
        return choice;
    }
  
  
int main() {
    std::vector<Note> notes;
       int choice;
       
       do {
         choice = notesManager ();
       
        switch (choice) {
            case 1 :
                createNote(notes);
                break;
            case 2:
                displayNotes(notes);
                break;
            case 3:
                viewNoteContent(notes);
                break;
            case 4:
                editNoteContent(notes);
                break;
            case 5:
                deleteNote(notes);
                break;
            case 6:
                std::cout << "Keluar dari program...\n";
                return 0;
            default:
                std::cout << "Pilihan tidak valid!\n";
                break;
        }
        
        std::cout << std::endl;
    } while (choice != 6);

    return 0;
}