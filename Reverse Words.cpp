#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct qnode {
    string s;

	qnode* next;

	qnode(string wrds, qnode* nptr = NULL)
	{
	    s = wrds;
	    next = nptr;
	}

};

qnode* qfront = NULL;
qnode* qback = NULL;
int qsize = 0;

void Push(string ss);   // Modified Queue Push function to insert from the Front
void Pop();             // Function to Output Front Node and remove it from the queue in that sequence

int main()
{

    string str;         // Variable to hold a line of input
    string wrds;        // Variable to Push word by word
    int cases;          // Total Number of cases
    int cnum = 1;       // Current Case Number

    fstream f1;
    f1.open("RW.in", ios::in);

    f1 >> cases;        // Read Total Number of cases
    getline(f1, str);

    while(cases != 0)
    {
        getline(f1, str);       // Read line from file
        stringstream ss(str);   // Insert line into a String Stream

        while(ss >> wrds)
        {
            Push(wrds);         // Push word by word
        }

        cout << "Case# " << cnum << " : ";      // Display Case#

        do
        {
            Pop();      // Remove item from Queue

        }while(qsize > 0);

        cout << endl;

        cases--;
        cnum++;
    }


    return 0;
}


void Push(string wrds)
{
	qnode *newNode = new qnode(wrds);

	if(qfront == NULL)
    {
		qfront = newNode;
        qback = newNode;
	}

    else
    {
        newNode->next = qfront;
        qfront = newNode;
    }

	qsize++;

}

void Pop()
{

	if(qsize == 0)
        return;

    else
    {
        qnode *p = qfront;

        cout << p->s << " ";
        qfront = qfront->next;

        if(qfront == NULL)
            qback = NULL;

        delete p;

        qsize--;
    }

}

