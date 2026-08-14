#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    string artist;

    Song* prev;
    Song* next;

    Song(string t, string a) {
        title = t;
        artist = a;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    // Add a song at the end
    void addSong(string title, string artist) {
        Song* newSong = new Song(title, artist);

        if (head == NULL) {
            head = newSong;
            tail = newSong;
            current = newSong;
        }
        else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }

        cout << "Song added: " << title << endl;
    }

    // Print playlist forward
    void printForward() {
        Song* temp = head;

        cout << "\nPlaylist (Forward):\n";

        while (temp != NULL) {
            cout << temp->title << " - "
                 << temp->artist << endl;

            temp = temp->next;
        }
    }

    // Print playlist backward
    void printBackward() {
        Song* temp = tail;

        cout << "\nPlaylist (Backward):\n";

        while (temp != NULL) {
            cout << temp->title << " - "
                 << temp->artist << endl;

            temp = temp->prev;
        }
    }

    // Move to next song
    void nextSong() {
        if (current == NULL) {
            cout << "Playlist is empty." << endl;
        }
        else if (current->next == NULL) {
            cout << "Already at the last song." << endl;
        }
        else {
            current = current->next;

            cout << "Playing: "
                 << current->title << " - "
                 << current->artist << endl;
        }
    }

    // Move to previous song
    void previousSong() {
        if (current == NULL) {
            cout << "Playlist is empty." << endl;
        }
        else if (current->prev == NULL) {
            cout << "Already at the first song." << endl;
        }
        else {
            current = current->prev;

            cout << "Playing: "
                 << current->title << " - "
                 << current->artist << endl;
        }
    }

    // Display current song
    void currentSong() {
        if (current == NULL) {
            cout << "Playlist is empty." << endl;
        }
        else {
            cout << "Current Song: "
                 << current->title << " - "
                 << current->artist << endl;
        }
    }
};

int main() {

    Playlist playlist;

    playlist.addSong("Shape of You", "Ed Sheeran");
    playlist.addSong("Blinding Lights", "The Weeknd");
    playlist.addSong("Perfect", "Ed Sheeran");
    playlist.addSong("Believer", "Imagine Dragons");

    playlist.printForward();
    playlist.printBackward();

    cout << "\n--- Navigation ---\n";

    playlist.currentSong();

    playlist.nextSong();
    playlist.nextSong();

    playlist.previousSong();
    playlist.previousSong();

    return 0;
}
