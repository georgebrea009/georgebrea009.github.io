//CIS-265_098WB
//George Brea
//Project 10 Movie Data
//Due March 31, 2024

#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

struct MovieData
{
    string title, director;
    int yearReleased, runningTime;
};

void displayMovies(MovieData *);

int main()
{
    MovieData
    action = {"Rambo: First Blood", "Ted Kotcheff", 1982, 93},
    scifi = {"Blade Runner", "Ridley Scott", 1982, 110};
    displayMovies(&action);
    displayMovies(&scifi);
    return 0;
}

void displayMovies(MovieData *d)
{
    cout << setprecision(3);
    cout << "The Tile of this movie is: " << (*d).title <<endl;
    cout << (*d).title << "'s Director's name is: " << (*d).director <<endl;
    cout << (*d).title <<" was first released in: " << (*d).yearReleased <<endl;
    cout << (*d).title <<"'s running time is: " << (*d).runningTime << " minutes.\n\n";
    
}