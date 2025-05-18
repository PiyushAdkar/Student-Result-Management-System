// You can view the student.txt file for the example student data. In the student.txt file, first field is student Id (which the code may ask) 
// and the last field is password which you have to enter if asked.
#include <iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<string>
using namespace std;

class Student
{
    private:
    string id,name;
    public:
    Student()
    {
        id=".";
        name=".";
    }
    void getinfo()
    {
        cout<<"Enter ID: "<<endl;
        getline(cin,id);
        cout<<"Enter name:";
        getline(cin,name);
    }
    void writeinfo()
    {
        ofstream out("student.txt",ios::app);
        if (out.is_open()) 
        {
            out<<id<<"|"<<name<<"|";
            out.close();
        } 
        else 
        {
            cout<<"Error opening the file!"<<endl;
        }
    }
    void display_one(string i_d)
{
    ifstream in("student.txt");
    string s, a, a1, a2, a3, a4, a5, a6, a7, a8, a9;
    bool found = false;

    // Create an output file stream to write the HTML content
    ofstream file("output.html");

    if (file.is_open()) {
        // Start the HTML structure with some styling
        file << "<html>\n";
        file << "<head><title>Student Result</title>\n";
        file << "<style>\n";
        file << "body { font-family: Arial, sans-serif; background-color: #f4f4f9; color: #333; margin: 40px; }\n";
        file << "h1 { color: #2c3e50; text-align: center; }\n";
        file << "table { width: 80%; margin: 20px auto; border-collapse: collapse; background-color: #fff; box-shadow: 0 2px 10px rgba(0, 0, 0, 0.1); }\n";
        file << "th, td { padding: 12px 20px; text-align: left; }\n";
        file << "th { background-color: #3498db; color: #fff; font-size: 18px; }\n";
        file << "td { background-color: #ecf0f1; font-size: 16px; }\n";
        file << "tr:nth-child(even) td { background-color: #f9f9f9; }\n";
        file << "tr:hover td { background-color: #dfe6e9; }\n";
        file << "p { font-size: 18px; text-align: center; color: #e74c3c; }\n";
        file << "</style>\n";
        file << "</head>\n";
        file << "<body>\n";
        file << "<h1>Student Result</h1>\n";

        // Write a table to display the student's data
        file << "<table>\n";
        file << "<tr><th>Field</th><th>Value</th></tr>\n";
        
        while (getline(in, s))
        {
            stringstream ss(s);   
            getline(ss, a, '|');

            if (i_d == a)
            {
                found = true;
                getline(ss, a1, '|');
                getline(ss, a2, '|');
                getline(ss, a3, '|');
                getline(ss, a4, '|');
                getline(ss, a5, '|');
                getline(ss, a6, '|');
                getline(ss, a7, '|');
                getline(ss, a8, '|');
                getline(ss, a9, '|');

                // Write the student's data in the HTML table
                file << "<tr><td><strong>ID</strong></td><td>" << a << "</td></tr>\n";
                file << "<tr><td><strong>Name</strong></td><td>" << a1 << "</td></tr>\n";
                file << "<tr><td><strong>QP Marks</strong></td><td>" << a2 << "</td></tr>\n";
                file << "<tr><td><strong>SIC Marks</strong></td><td>" << a3 << "</td></tr>\n";
                file << "<tr><td><strong>IEEE Marks</strong></td><td>" << a4 << "</td></tr>\n";
                file << "<tr><td><strong>MFR Marks</strong></td><td>" << a5 << "</td></tr>\n";
                file << "<tr><td><strong>OOPC Marks</strong></td><td>" << a6 << "</td></tr>\n";
                file << "<tr><td><strong>Total Marks</strong></td><td>" << a7 << "</td></tr>\n";
                file << "<tr><td><strong>Percentage</strong></td><td>" << a8 << "</td></tr>\n";
                file << "<tr><td><strong>Grade</strong></td><td>" << a9 << "</td></tr>\n";

                // End the table and HTML
                file << "</table>\n";
                file << "</body>\n";
                file << "</html>\n";

                break;
            }
        }

        // If student not found, display an error message
        if (!found) {
            file << "<p>No student found with ID: " << i_d << "</p>\n";
            file << "</body>\n";
            file << "</html>\n";
        }

        file.close(); // Close the file

        // Open the generated HTML file automatically in the default browser
        system("start output.html"); // For Windows, use `xdg-open` for Linux, or `open` for macOS

    } else {
        cout << "Unable to open file for writing.\n";
    }

    in.close(); // Close the input file
}
    void delete_one(string i_dd)
    {
        ofstream out("temp.txt");
        ifstream in("student.txt");
        string s,a;
        bool t = false;

        while(getline(in,s))
        {
            stringstream ss(s);   
            getline(ss,a,'|');     

            if(i_dd != a)
            {
                out<<s<<endl;
            }
            else
            {
                t = true;
                continue;
            }  
        }   
        in.close();
        out.close();
        if(t == true)
        {
            remove("student.txt");
            rename("temp.txt","student.txt");
            cout<<"Records of the student with ID "<<i_dd<<" are deleted successfully."<<endl;
        }
        else
        {
            remove("temp.txt");
            cout<<"No student found with ID: "<<i_dd<<endl;
            cin.ignore();
        }  
    }
    void display_list()
{
    ifstream in("student.txt");
    string s, a, a1, a2, a3, a4, a5, a6, a7, a8, a9;

    // Create an output file stream to write the HTML content
    ofstream file("student_list.html");

    if (file.is_open()) {
        // Start the HTML structure with some styling
        file << "<html>\n";
        file << "<head><title>All Students List</title>\n";
        file << "<style>\n";
        file << "body { font-family: Arial, sans-serif; background-color: #f4f4f9; color: #333; margin: 40px; }\n";
        file << "h1 { color: #2c3e50; text-align: center; }\n";
        file << "table { width: 80%; margin: 20px auto; border-collapse: collapse; background-color: #fff; box-shadow: 0 2px 10px rgba(0, 0, 0, 0.1); }\n";
        file << "th, td { padding: 12px 20px; text-align: left; }\n";
        file << "th { background-color: #3498db; color: #fff; font-size: 18px; }\n";
        file << "td { background-color: #ecf0f1; font-size: 16px; }\n";
        file << "tr:nth-child(even) td { background-color: #f9f9f9; }\n";
        file << "tr:hover td { background-color: #dfe6e9; }\n";
        file << "</style>\n";
        file << "</head>\n";
        file << "<body>\n";
        file << "<h1>All Students List</h1>\n";

        // Write a table to display the students' data
        file << "<table>\n";
        file << "<tr><th>ID</th><th>Name</th><th>QP Marks</th><th>SIC Marks</th><th>IEEE Marks</th><th>MFR Marks</th><th>OOPC Marks</th><th>Total Marks</th><th>Percentage</th><th>Grade</th></tr>\n";
        
        // Read the student records and write them to the HTML table
        while (getline(in, s))
        {
            stringstream ss(s);
            getline(ss, a, '|');
            getline(ss, a1, '|');
            getline(ss, a2, '|');
            getline(ss, a3, '|');
            getline(ss, a4, '|');
            getline(ss, a5, '|');
            getline(ss, a6, '|');
            getline(ss, a7, '|');
            getline(ss, a8, '|');
            getline(ss, a9, '|');

            // Write each student's data in the HTML table
            file << "<tr>\n";
            file << "<td>" << a << "</td>\n";
            file << "<td>" << a1 << "</td>\n";
            file << "<td>" << a2 << "</td>\n";
            file << "<td>" << a3 << "</td>\n";
            file << "<td>" << a4 << "</td>\n";
            file << "<td>" << a5 << "</td>\n";
            file << "<td>" << a6 << "</td>\n";
            file << "<td>" << a7 << "</td>\n";
            file << "<td>" << a8 << "</td>\n";
            file << "<td>" << a9 << "</td>\n";
            file << "</tr>\n";
        }

        // End the table and HTML
        file << "</table>\n";
        file << "</body>\n";
        file << "</html>\n";

        file.close(); // Close the file

        // Open the generated HTML file automatically in the default browser
        system("start student_list.html"); // For Windows, use `xdg-open` for Linux, or `open` for macOS

    } else {
        cout << "Unable to open file for writing.\n";
    }

    in.close(); // Close the input file
}
    void class_topper() {
    int count, max = 0;
    ifstream in("student.txt");
    string s, a;

    // Create an output file stream to write the HTML content
    ofstream file("topper.html");

    if (file.is_open()) {
        // Start the HTML structure with some styling
        file << "<html>\n";
        file << "<head><title>Class Topper</title>\n";
        file << "<style>\n";
        file << "body { font-family: Arial, sans-serif; background-color: #f4f4f9; color: #333; margin: 40px; }\n";
        file << "h1 { color: #2c3e50; text-align: center; }\n";
        file << "table { width: 80%; margin: 20px auto; border-collapse: collapse; background-color: #fff; box-shadow: 0 2px 10px rgba(0, 0, 0, 0.1); }\n";
        file << "th, td { padding: 12px 20px; text-align: left; }\n";
        file << "th { background-color: #3498db; color: #fff; font-size: 18px; }\n";
        file << "td { background-color: #ecf0f1; font-size: 16px; }\n";
        file << "tr:nth-child(even) td { background-color: #f9f9f9; }\n";
        file << "tr:hover td { background-color: #dfe6e9; }\n";
        file << "</style>\n";
        file << "</head>\n";
        file << "<body>\n";
        file << "<h1>Class Topper</h1>\n";

        // First pass: Find the maximum marks
        while (getline(in, s)) {
            stringstream ss(s);
            count = 0;
            while (getline(ss, a, '|')) {
                if (count == 7) { // Assuming marks are at index 7
                    int marks = stoi(a);
                    if (marks > max) {
                        max = marks;
                    }
                }
                count++;
            }
        }

        // Reset the file pointer and process it again
        in.clear();
        in.seekg(0, ios::beg);

        // Write the table header
        file << "<table>\n";
        file << "<tr><th>ID</th><th>Name</th><th>QP Marks</th><th>SIC Marks</th><th>IEEE Marks</th><th>MFR Marks</th><th>OOPC Marks</th><th>Total Marks</th><th>Percentage</th><th>Grade</th></tr>\n";

  // Second pass: Write the top scorer(s)
while (getline(in, s)) {
    stringstream ss(s);
    count = 0;
    while (getline(ss, a, '|')) {
        if (count == 7) { // Total marks index
            if (stoi(a) == max) {
                // Write each topper's data to HTML (excluding password)
                file << "<tr>\n";
                stringstream ss_s(s);
                int temp_count = 0;
                while (getline(ss_s, a, '|')) {
                    if (temp_count <= 9) { // Write only fields till Grade (skip password)
                        file << "<td>" << a << "</td>\n";
                    }
                    temp_count++;
                }
                file << "</tr>\n";
            }
        }
        count++;
    }
}


        // End the table and HTML
        file << "</table>\n";
        file << "</body>\n";
        file << "</html>\n";

        file.close(); // Close the file

        // Open the generated HTML file automatically in the default browser
        system("start topper.html"); // For Windows, use `xdg-open` for Linux, or `open` for macOS

    } else {
        cout << "Unable to open file for writing.\n";
    }

    in.close(); // Close the input file
}
};

class Result;

class Marks : public virtual Student
{
    private:
    int qp,sic,ieee,mfr,oopc;
    public:
    void getmarks()
    {
        cout<<"Enter the marks out of 30:"<<endl;
        cout<<"QP: "; cin>>qp;
        if(qp>30 || qp<0)
        {
            cout<<"Please enter marks till 30."<<endl;
            cout<<"QP: "; cin>>qp;
        }
        cout<<"SIC: "; cin>>sic;
        if(sic>30 || sic<0)
        {
            cout<<"Please enter marks till 30."<<endl;
            cout<<"SIC: "; cin>>sic;
        }
        cout<<"IEEE: "; cin>>ieee;
        if(ieee>30 || ieee<0)
        {
            cout<<"Please enter marks till 30."<<endl;
            cout<<"IEEE: "; cin>>ieee;
        }
        cout<<"MFR: "; cin>>mfr;
        if(mfr>30 || mfr<0)
        {
            cout<<"Please enter marks till 30."<<endl;
            cout<<"MFR: "; cin>>mfr;
        }
        cout<<"OOPC: "; cin>>oopc;
        if(oopc>30 || oopc<0)
        {
            cout<<"Please enter marks till 30."<<endl;
            cout<<"OOPC: "; cin>>oopc;
        }
    }  
    void writemarks()
    {
        ofstream out("student.txt",ios::app);
        if (out.is_open()) 
        {
            out<<qp<<"|"<<sic<<"|"<<ieee<<"|"<<mfr<<"|"<<oopc<<"|";
            out.close();
        } 
        else 
        {
            cout<<"Error opening the file!"<<endl;
        }
    } 
    friend class Result;
}; 

class Result
{
    int total;
    float Percentage;
    string Grade,pass;
    public:
    void calc_percentage(Marks m)
    {
        total = m.qp + m.sic + m.ieee + m.mfr + m.oopc;
        Percentage = (((float)total/150)*100);
    }
    void calc_grade()
    {
        if(Percentage>=90)
        {
            Grade = "A+";
        }
        else if(Percentage>=80)
        {
            Grade = "A";
        }
        else if(Percentage>=70)
        {
            Grade = "B+";
        }
        else if(Percentage>=60)
        {
            Grade = "B";
        }
        else if(Percentage>=50)
        {
            Grade = "C+";
        }
        else if(Percentage>=40)
        {
            Grade = "C";
        }
        else if(Percentage>=35)
        {
            Grade = "C-";
        }
        else
        {
            Grade = "F";
        }
    }
    void writeresult()
    {
        ofstream out("student.txt",ios::app);
        if (out.is_open()) 
        {
            out<<total<<"|"<<fixed<<setprecision(2)<<Percentage<<"|"<<Grade<<"|";
            cout<<"Give a password: ";
            cin>>pass;
            out<<pass<<endl;
            out.close();
        } 
        else 
        {
            cout<<"Error opening the file!"<<endl;
        }
    } 

};

class student_system : public virtual Student , public Marks , public Result
{
    int choice;
    string id;
    public:
    void menu()
    {
        cout<<"\nStudent result management system:\n1.Add new student\n2.Delete records of an existing student\n3.Display records of a student\n4.Update details of a student\n5.Display all students\n6.Display class topper\n7.Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        cin.ignore();
        string idd,a,s;
        bool t;
        switch(choice)
        {
            case 1:
            {
            cout<<"Enter ID:";
            getline(cin,idd);
            ifstream in("student.txt");
            t = true;
            while (getline(in, s))
            {
                stringstream ss(s);   
                getline(ss, a, '|');

                if (idd == a)
                {
                    t = false;
                    cout<<"Records of Student with ID "<<idd<<" already exists."<<endl;
                    break;
                }
            }
                if(t == true)
                {
                    getinfo();
                    writeinfo();
                    getmarks();
                    writemarks();
                    calc_percentage(*this);
                    calc_grade();
                    writeresult();
                    cout<<"Student records added successfully! "<<endl;
                    in.close();
                }
                char x;
                cout<<"Do you want to see list of all the students?(Enter Y/y for yes) "<<endl; 
                cin>>x;           
                if(x=='Y' || x=='y')
                {
                    goto dis;
                }
                break;
            }
            case 2:
            {
            string p,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
            cout<<"Enter student ID: "<<endl;
            cin>>id;
            cout<<"Enter password: "<<endl;
            cin>>p;
            ifstream in("student.txt");
            t = false;
            while (getline(in, s))
            {
                stringstream ss(s);   
                getline(ss, a, '|');

                if (id == a)
                {
                    t = true;
                    getline(ss, a1, '|');
                    getline(ss, a2, '|');
                    getline(ss, a3, '|');
                    getline(ss, a4, '|');
                    getline(ss, a5, '|');
                    getline(ss, a6, '|');
                    getline(ss, a7, '|');
                    getline(ss, a8, '|');
                    getline(ss, a9, '|');
                    getline(ss, a10, '|');
                    if(a10 == p)
                    {
                        in.close();
                        delete_one(id);
                        char x;
                        cout<<"Do you want to see list of all the students?(Enter Y/y for yes) "<<endl; 
                        cin>>x;           
                        if(x=='Y' || x=='y')
                        {
                            goto dis;
                        }
                    }
                    else
                    {
                        cout<<"The password is wrong!"<<endl;
                    }
                    break;
                }
            }

            if (t==false) {
            cout<<"No student found with ID "<<id<<endl;
            }
            in.close();
            break;
            }    
            case 3:
            {
            string p,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
            cout<<"Enter student ID: "<<endl;
            cin>>id;
            cout<<"Enter password: "<<endl;
            cin>>p;
            ifstream in("student.txt");
            t = false;
            while (getline(in, s))
            {
                stringstream ss(s);   
                getline(ss, a, '|');

                if (id == a)
                {
                    t = true;
                    getline(ss, a1, '|');
                    getline(ss, a2, '|');
                    getline(ss, a3, '|');
                    getline(ss, a4, '|');
                    getline(ss, a5, '|');
                    getline(ss, a6, '|');
                    getline(ss, a7, '|');
                    getline(ss, a8, '|');
                    getline(ss, a9, '|');
                    getline(ss, a10, '|');
                    if(a10 == p)
                    {
                        in.close();
                        display_one(id);
                    }
                    else
                    {
                        cout<<"The password is wrong!"<<endl;
                    }
                    break;
                }
            }

            if (t==false) {
            cout<<"No student found with ID "<<id<<endl;
            }
            in.close();
            break;
            } 
            case 4:
            {
                string p,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
                cout<<"Enter ID:";
                getline(cin,idd);
                cout<<"Enter password: "<<endl;
                cin>>p;
                ifstream in("student.txt");
                t = false;
                while (getline(in, s))
                {
                    stringstream ss(s);   
                    getline(ss, a, '|');
                    if (idd == a)
                {
                    t = true;
                    getline(ss, a1, '|');
                    getline(ss, a2, '|');
                    getline(ss, a3, '|');
                    getline(ss, a4, '|');
                    getline(ss, a5, '|');
                    getline(ss, a6, '|');
                    getline(ss, a7, '|');
                    getline(ss, a8, '|');
                    getline(ss, a9, '|');
                    getline(ss, a10, '|');
                    if(a10 == p)
                    {
                        in.close();
                        delete_one(idd);
                        cout<<"Now enter the updated data."<<endl;
                        cin.ignore();
                        getinfo();
                        writeinfo();
                        getmarks();
                        writemarks();
                        calc_percentage(*this);
                        calc_grade();
                        writeresult();
                        cout<<"Student records updated successfully! "<<endl;
                        char x;
                        cout<<"Do you want to see list of all the students?(Enter Y/y for yes) "<<endl; 
                        cin>>x;           
                        if(x=='Y' || x=='y')
                        {
                            goto dis;
                        }
                    }
                    else
                    {
                        cout<<"The password is wrong!"<<endl;
                    }
                    break;
                }
            }
                if(t == false)
                {
                cout<<"Student with ID "<<idd<<" do no exist."<<endl;
                }
            break;
            }
        dis:case 5:
            {
                display_list();
                break;
            }
            case 6:
            {
                class_topper();
                break;
            }
            case 7:
            {
            cout<<"Exiting the system."<<endl;
            break;
            }
            default:
            {
            cout<<"Enter valid choice (Between 1-4): "<<endl;
            }    
        }
    }
};


int main()
{
    student_system app;
    app.menu();
    return 0;
}
