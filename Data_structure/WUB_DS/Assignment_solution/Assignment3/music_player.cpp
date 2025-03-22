#include <iostream>
#include <string>

using namespace std;

// Define a structure for a song node in the linked list
struct Song
{
    string title;
    string artist;
    int duration; // Duration in seconds
    Song *next;
};

// Function to create a new song node
Song *createSong(string title, string artist, int duration)
{
    Song *newSong = new Song();
    newSong->title = title;
    newSong->artist = artist;
    newSong->duration = duration;
    newSong->next = nullptr;
    return newSong;
}

// Function to display the playlist
void displayPlaylist(Song *head)
{
    if (head == nullptr)
    {
        cout << "Playlist is empty.\n";
        return;
    }
    Song *current = head;
    int count = 1;
    cout << "\nPlaylist:\n";
    while (current != nullptr)
    {
        cout << count << ". " << current->title << " by " << current->artist
             << " (" << current->duration << " sec)\n";
        current = current->next;
        count++;
    }
}

// Function to add a song to the end of the playlist
void addSong(Song *&head, string title, string artist, int duration)
{
    Song *newSong = createSong(title, artist, duration);
    if (head == nullptr)
    {
        head = newSong;
        return;
    }
    Song *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newSong;
}

// Function to delete a song by position
void deleteSong(Song *&head, int position)
{
    if (head == nullptr)
    {
        cout << "Playlist is empty. Cannot delete.\n";
        return;
    }
    if (position == 1)
    {
        Song *temp = head;
        head = head->next;
        delete temp;
        cout << "Song deleted.\n";
        return;
    }
    Song *current = head;
    Song *prev = nullptr;
    int count = 1;
    while (current != nullptr && count < position)
    {
        prev = current;
        current = current->next;
        count++;
    }
    if (current == nullptr)
    {
        cout << "Invalid position. No song deleted.\n";
        return;
    }
    prev->next = current->next;
    delete current;
    cout << "Song deleted.\n";
}

// Function to rearrange a song within the playlist
void moveSong(Song *&head, int oldPos, int newPos)
{
    if (head == nullptr || oldPos == newPos)
    {
        cout << "No changes made to the playlist.\n";
        return;
    }

    Song *prevOld = nullptr;
    Song *currentOld = head;
    int count = 1;
    while (currentOld != nullptr && count < oldPos)
    {
        prevOld = currentOld;
        currentOld = currentOld->next;
        count++;
    }
    if (currentOld == nullptr)
    {
        cout << "Invalid old position.\n";
        return;
    }

    if (prevOld != nullptr)
    {
        prevOld->next = currentOld->next;
    }
    else
    {
        head = currentOld->next;
    }

    if (newPos == 1)
    {
        currentOld->next = head;
        head = currentOld;
        return;
    }

    Song *prevNew = nullptr;
    Song *currentNew = head;
    count = 1;
    while (currentNew != nullptr && count < newPos)
    {
        prevNew = currentNew;
        currentNew = currentNew->next;
        count++;
    }
    currentOld->next = currentNew;
    if (prevNew != nullptr)
    {
        prevNew->next = currentOld;
    }
    cout << "Song moved.\n";
}

int main()
{
    Song *playlist = nullptr; // Initialize an empty playlist
    int choice;

    do
    {
        cout << "\nMusic Playlist Management System\n";
        cout << "1. Add a song\n";
        cout << "2. Delete a song\n";
        cout << "3. Display playlist\n";
        cout << "4. Rearrange a song\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string title, artist;
            int duration;
            cout << "Enter song title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter artist name: ";
            getline(cin, artist);
            cout << "Enter song duration (in seconds): ";
            cin >> duration;
            addSong(playlist, title, artist, duration);
            break;
        }
        case 2:
        {
            int position;
            cout << "Enter the position of the song to delete: ";
            cin >> position;
            deleteSong(playlist, position);
            break;
        }
        case 3:
        {
            displayPlaylist(playlist);
            break;
        }
        case 4:
        {
            int oldPos, newPos;
            cout << "Enter the current position of the song: ";
            cin >> oldPos;
            cout << "Enter the new position: ";
            cin >> newPos;
            moveSong(playlist, oldPos, newPos);
            break;
        }
        case 5:
        {
            cout << "Exiting the system. Goodbye!\n";
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    // Clean up the memory used by the linked list
    while (playlist != nullptr)
    {
        Song *temp = playlist;
        playlist = playlist->next;
        delete temp;
    }

    return 0;
}
