#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    Song* next;
    Song* prev;

    Song(string t) {
        title = t;
        next = NULL;
        prev = NULL;
    }
};

class Playlist {
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    Playlist() {
        head = tail = current = NULL;
    }

    // Add a song to the end
    void addSong(string title) {
        Song* newSong = new Song(title);

        if (head == NULL) {
            head = tail = current = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
    }

    // Move to next song
    void nextSong() {
        if (current != NULL && current->next != NULL) {
            current = current->next;
            cout << "Playing: " << current->title << endl;
        } else {
            cout << "Already at the last song.\n";
        }
    }

    // Move to previous song
    void previousSong() {
        if (current != NULL && current->prev != NULL) {
            current = current->prev;
            cout << "Playing: " << current->title << endl;
        } else {
            cout << "Already at the first song.\n";
        }
    }

    // Display playlist from beginning to end
    void displayForward() {
        Song* temp = head;

        cout << "\nPlaylist (Forward): ";
        while (temp != NULL) {
            cout << temp->title << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Display playlist from end to beginning
    void displayBackward() {
        Song* temp = tail;

        cout << "Playlist (Backward): ";
        while (temp != NULL) {
            cout << temp->title << " -> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }

    // Show currently playing song
    void currentSong() {
        if (current != NULL)
            cout << "Current song: " << current->title << endl;
        else
            cout << "Playlist is empty.\n";
    }

    ~Playlist() {
        Song* temp = head;

        while (temp != NULL) {
            Song* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    Playlist playlist;

    playlist.addSong("Shape of You");
    playlist.addSong("Believer");
    playlist.addSong("Perfect");
    playlist.addSong("Blinding Lights");

    playlist.displayForward();
    playlist.displayBackward();

    playlist.currentSong();

    cout << "\nForward navigation:\n";
    playlist.nextSong();
    playlist.nextSong();

    cout << "\nBackward navigation:\n";
    playlist.previousSong();

    return 0;
}
