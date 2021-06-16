//This program will calculate a students year marks for all
//the students subjects. The program must:
//Read assignment code, two contributing assignment marks and
//the percentage the student achieved for each of the assign-
//ments for each subject.
//Read file line by line, calculate the students year mark
//for the subject as a percentage.


#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;


void calc_student_mark(ifstream &inputfile, ofstream &outputfile);
//This function takes the input and output files as parameters to
//read the file, calculate the students year mark for each of the
//subjects they are registered for and write the subject code and
//the year mark as a percentage to the output file. The students
//mark for each assignment is a percentage so the mark has to be
//converted to the assignments actual mark so we can get a final
//mark for a total of 100%. A while loop is used to read for the
//end of file.

int main()
{
    ifstream fin;
    ofstream fout;


    fin.open("assignments.dat");
    if(fin.fail())
    {
        cout << "The input file assignments.dat failed to open.";
        exit(1);
    }


    fout.open("yearmark.dat");
    if(fout.fail())
    {
        cout << "The output file yearmark.dat failed to open.";
        exit(1);
    }


    calc_student_mark(fin, fout);


    fin.close();


    fout.close();
}


void calc_student_mark(ifstream &inputfile, ofstream &outputfile)
{

    string sub_code;
    int contrib_1, contrib_2;
    float final_mark = 0, mark_1, mark_2, m1_contrib, m2_contrib;


    while (!inputfile.eof())
    {
        inputfile >> sub_code >> contrib_1 >> mark_1 >> contrib_2 >> mark_2;
        cout << sub_code << " " <<contrib_1 << " " << mark_1 << " " << contrib_2 << " " << mark_2 << endl;
        m1_contrib = (mark_1 / 100) * contrib_1;
        m2_contrib = (mark_2 / 100) * contrib_2;
        final_mark = m1_contrib + m2_contrib;
        outputfile.setf(ios::fixed);
        outputfile.setf(ios::showpoint);
        outputfile.precision(2);
        outputfile << sub_code << " " << final_mark << "%" << endl;;
    }

}


