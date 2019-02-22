/* Name: Jordan Wermuth
  IDE: CLion
  Date: 20 February 2019
  Instructor: Vielma
*/

#include<iostream>

#include<iomanip>

#include<fstream>

#include<cstring>

#include<string>

#include<sstream>

using namespace std;

struct PERSON
{

    char name[20];

    float balance;


};



void Display(PERSON *persons, int N);

void getHighest(PERSON *persons, int N);

void Deposit(char entryname[],PERSON *persons, int N);

void NewCopy(string firstname, PERSON *persons, int N);

int main()

{

    int N = 0;
    ifstream in;
    in.open("/Users/jordanwermuth/Desktop/assignment1textfile/data.txt");

    if(in.fail())

    {
        cout << "cannot open the file" << endl;
        return 0;
    }

    cout << setprecision(2) << fixed;

    cout << setw(15)<< left << "Name" << "Balance" << endl;

    cout <<"----------------------------"<< endl;






    PERSON *persons = new PERSON[N];

    string firstname, lastname;

    Display(persons, N);

    void getHighest(PERSON *persons, int N);




    getHighest(persons, N);

    char entryname[20];

    cout << "Enter your full name to deposit money: ";

    cin.getline(entryname, 20);

    Deposit(entryname, persons, N);

    NewCopy("data.txt", persons, N);



    return 0;

}

void Display(PERSON *persons, int N )

{


    ifstream in;
    in.open("/Users/jordanwermuth/Desktop/assignment1textfile/data.txt");

    if(in.fail())

    {
        cout << "cannot open the file" << endl;

    }



    /*while (getline(in, line))
        {


            string entryname, balance;

            in >> ws;




        }

    if (in.is_open())
        {
            string line;
            while (getline(in, line))
                {
                    printf("%s", line.c_str());
                }

        }*/







    string line;

    while(!in.eof())
        {
            getline(in, line);

            cout << line << endl;




        }


    in.close();
    /*in.clear();
    in.seekg (0, in.end);        // tried a new method for reading this file, found on cplusplus
    int length = in.tellg();

    in.seekg (0, in.beg);

    char *buffer = new char [length];
    in.read (buffer, length);

    cout.write (buffer, length);


*/


}

void getHighest(PERSON *persons, int N)
{

     /*int max = 0;
     for(int i=0; i < N; i++){
         if(persons[max].balance < persons[i].balance)
             max = i;}*/


    PERSON Highest = persons[0];
    for (int i = 1; i < N; i++)

        {
            if (Highest.balance < persons[i].balance)

                Highest = persons[i];
        }

    cout << "Entry with the highest balance is " << Highest.name << endl;// this prints



}



void Deposit(char entryname[],PERSON *persons, int N)

{

    int i = 0;



    for(int j=0; j< N; j++){

        if(strcmp(entryname, persons[i].name)==0)
        {

            i = j;

            break;

        }


    }

    if(i == -1)

        cout<<"entry not found"<<endl;

    else{

        double deposit;

        cout << " " << entryname <<", how much will you deposit? ";

        cin >> deposit;

        persons[i].balance+=deposit;

        cout<<"New balance is: "<<persons[i].balance<<endl;

    }

}

void NewCopy(string firstname, PERSON *persons, int N) {

    ofstream out;

    out << setprecision(2) << fixed;

    out.open(firstname.c_str());

    for (int i = 0; i < N; i++) {

        out << persons[i].name << " " << persons[i].balance << endl;

    }

    out.close();
}


