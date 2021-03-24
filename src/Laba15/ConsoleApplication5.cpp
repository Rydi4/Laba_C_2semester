#include <iostream>
#include <fstream>
#include <string>   
using namespace std;

struct SchoolSize 
{
    int height;
    int width;
    int length;
};

struct School
{
    string adress;
    SchoolSize size;
    int classes;
    int cabinet;
};

int yardage(SchoolSize* size)
{
    int square = size->height * size->width * size->length;
    return square;  
}

istream& operator>> (istream & is, SchoolSize & size)
{
    is >> size.height >> size.width >> size.length; 
    return is;
}

istream& operator>> (istream & is, School & fifth)
{
    is >> fifth.adress >> fifth.classes >> fifth.cabinet;
    return is;
}

int main()
{
    SchoolSize size;    
    ifstream data("SchoolSize.txt", ios_base::in);
    data >> size;
    cout << "School height: " << size.height <<endl;
    cout << "School width: " << size.width << endl;
    cout << "Length of the school: " << size.length << endl;
    cout << "The area of the school is: " << yardage(&size) << endl;

    School fifth; 
    ifstream file("School.txt", ios_base::in);
    file >> fifth;
    cout << "School address: " << fifth.adress << endl;
    cout << "Number of classes in the school: " << fifth.classes << endl;
    cout << "Number of classrooms in the school: " << fifth.cabinet << endl;

    return 0;
} 
