#include <iostream>
#include <string>
using namespace std;


struct Node
{
    string teamName;
    Node *next;
};


class CircularLinkedList
{
private:
    Node *last;

public:
	CircularLinkedList()
    {
        last = NULL;
    }

    
    void addTeam(string name)
    {
        Node *newNode = new Node;

        newNode->teamName = name;

        if (last == NULL)
        {
            last = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }
	
	
	    
       void displayTeams()
    {
        if (last == NULL)
        {
            cout << "No teams available." << endl;
            return;
        }
        
        Noed temp = last->next;
        
        cout << "\nTournament Teams-:" << endl;

        do
        {
            cout << temp->teamName << " -> ";
            temp = temp->next;
        }
        while (temp != last->next);

        cout << "(Back to " << last->next->teamName << ")" << endl;
    }
    
    
    void roundRobin(int rounds)
    {
        if (last == NULL)
        {
            cout << "No teams available." << endl;
            return;
        }

        Node *current = last->next;

        cout << "\n--- Round Robin Scheduling ---" << endl;

        for (int i = 1; i <= rounds; i++)
        {
            cout << "Round " << i << ": ";
            cout << current->teamName << " gets the turn." << endl;

            current = current->next;
        }
    }
};

int main()
{
    CircularLinkedList tournament;

    int n, rounds;
    string name;

    cout << "Enter number of teams: ";
    cin >> n;

    // Add teams
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter team " << i << " name: ";
        cin >> name;

        tournament.addTeam(name);
    }

    // Display teams
    tournament.displayTeams();

    // Number of rounds
    cout << "\nEnter number of rounds: ";
    cin >> rounds;

    // Simulate Round Robin
    tournament.roundRobin(rounds);

    return 0;
}
