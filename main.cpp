#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define enl "\n"

struct Patient
{
    string Id, Name, Date, Gendre, Phone, Address;
};
struct Doc
{
    string Id, Name, Speciatly, Gendre, Phone;
};
void Cin_Data_Patient()
{
    fstream f;
    f.open("E:\\Just Patient.txt", ios::in | ios::out);
    f.seekp(ios::end);
    string Id, Name, Date, Gendre, Phone, Address;
    cin >> Id >> Name >> Date >> Gendre >> Phone >> Address;
    f << Id << Name << Date << Gendre << Phone << Address << enl;
    f.close();
}
void Cin_Data_Doc()
{
    fstream f;
    f.open("E:\\Just Doc.txt", ios::in | ios::out);
    f.seekp(ios::end);
    string Id, Name, Speciatly, Gendre, Phone;
    cin >> Id >> Name >> Speciatly >> Gendre >> Phone;
    f << Id << Name << Speciatly << Gendre << Phone << enl;
    f.close();
}
void ADD_Data(string k)
{
    if (k == "Doc")Cin_Data_Doc();
    else Cin_Data_Patient();
}
void READ_Data_DOC()
{
    map<string, int>mp_Doc;
    vector<Doc>Print_Doc;
    fstream f;
    f.open("E:\\Just Doc.txt", ios::in | ios::out);
    int pos = 0;
    while (!f.fail())
    {
        string Id, Name, Speciatly, Gendre, Phone;
        f >> Id >> Name >> Speciatly >> Gendre >> Phone;
        Print_Doc.push_back({ Id,Name,Speciatly,Gendre,Phone });
        mp_Doc[Id] = pos;mp_Doc[Name] = pos;mp_Doc[Speciatly] = pos;
        mp_Doc[Gendre] = pos;mp_Doc[Phone] = pos;
        pos++;
    }
    cout << "If Want View Complete Doc data Press 1" << enl;
    cout << "else press 2" << enl;
    int key;cin >> key;
    if (key == 1)
    {

        cout << "Write record" << enl;
        int record;cin >> record;
        cout << "ID : " << Print_Doc[record].Id << enl
            << "Name : " << Print_Doc[record].Name << enl
            << "Speciatly : " << Print_Doc[record].Speciatly << enl
            << "Gendre : " << Print_Doc[record].Gendre << enl
            << "Phone : " << Print_Doc[record].Phone << enl
            << enl;
    }
    else
    {
        cout << "Write Attribute" << enl;
        string Attribute;cin >> Attribute;
        if (!mp_Doc.count(Attribute)) { cout << "This Attribute is Not Found" << enl; }
        cout << "To Show Id By Attribute Press 1" << enl;
        cout << "To Show Name By Attribute Press 2" << enl;
        cout << "To Show Speciatly By Attribute Press 3" << enl;
        cout << "To Show Gendre By Attribute Press 4" << enl;
        cout << "To Show Phone By Attribute Press 5" << enl;
        int op;cin >> op;
        if (op == 1)cout << "ID : " << Attribute << " Is '" << Print_Doc[mp_Doc[Attribute]].Id << "'" << enl;
        else if (op == 2)cout << "Name : " << Attribute << " Is '" << Print_Doc[mp_Doc[Attribute]].Name << "'" << enl;
        else if (op == 3)cout << "Speciatly : " << Attribute << " Is '" << Print_Doc[mp_Doc[Attribute]].Speciatly << "'" << enl;
        else if (op == 4)cout << "Gendre : " << Attribute << " Is '" << Print_Doc[mp_Doc[Attribute]].Gendre << "'" << enl;
        else if (op == 5)cout << "Phone : " << Attribute << " Is '" << Print_Doc[mp_Doc[Attribute]].Phone << "'" << enl;
    }
}
void READ_Data_Patient()
{
    map<string, int>mp_Patient;
    vector<Patient>Print_Patient;
    fstream f;
    f.open("E:\\Just Patient.txt", ios::in | ios::out);
    int pos = 0;
    while (!f.fail())
    {
        string Id, Name, Date, Gendre, Phone, Address;
        f >> Id >> Name >> Date >> Gendre >> Phone >> Address;
        Print_Patient.push_back({ Id,Name,Date,Gendre,Phone,Address });
        mp_Patient[Id] = pos;mp_Patient[Name] = pos;mp_Patient[Date] = pos;
        mp_Patient[Gendre] = pos;mp_Patient[Phone] = pos;mp_Patient[Address] = pos;
        pos++;
    }
    cout << "If Want View Complete Patient Data Press 1" << enl;
    cout << "Else press 2" << enl;
    int key;cin >> key;
    if (key == 1)
    {

        cout << "Write Record" << enl;
        int record;cin >> record;
        cout << "ID : " << Print_Patient[record].Id << enl
            << "Name : " << Print_Patient[record].Name << enl
            << "Date : " << Print_Patient[record].Date << enl
            << "Gendre : " << Print_Patient[record].Gendre << enl
            << "Phone : " << Print_Patient[record].Phone << enl
            << "Phone : " << Print_Patient[record].Address << enl
            << enl;
    }
    else
    {
        cout << "Write Attribute" << enl;
        string Attribute;cin >> Attribute;
        if (!mp_Patient.count(Attribute)) { cout << "This Attribute is Not Found" << enl; }
        cout << "To Show Id By Attribute Press 1" << enl;
        cout << "To Show Name By Attribute Press 2" << enl;
        cout << "To Show Date By Attribute Press 3" << enl;
        cout << "To Show Gendre By Attribute Press 4" << enl;
        cout << "To Show Phone By Attribute Press 5" << enl;
        cout << "To Show Address By Attribute Press 6" << enl;
        int op;cin >> op;
        if (op == 1)cout << "ID : " << Attribute << " Is '" << Print_Patient[mp_Patient[Attribute]].Id << "'" << enl;
        else if (op == 2)cout << "Name : " << Attribute << " Is '" << Print_Patient[mp_Patient[Attribute]].Name << "'" << enl;
        else if (op == 3)cout << "Date : " << Attribute << " Is '" << Print_Patient[mp_Patient[Attribute]].Date << "'" << enl;
        else if (op == 4)cout << "Gendre : " << Attribute << " Is '" << Print_Patient[mp_Patient[Attribute]].Gendre << "'" << enl;
        else if (op == 5)cout << "Phone : " << Attribute << " Is '" << Print_Patient[mp_Patient[Attribute]].Phone << "'" << enl;
        else if (op == 6)cout << "Phone : " << Attribute << " Is '" << Print_Patient[mp_Patient[Attribute]].Address << "'" << enl;
    }
}
void READ_Data(string k)
{
    if (k == "Doc")READ_Data_DOC();
    else READ_Data_Patient();
}
int main()
{
    cout << "Welcome ^ ^" << enl;
    string esc;
    while (1) {
        cout << "If TO continue Write AnyThing Else Write Ex" << enl;
        cin >> esc;
        if (esc == "Ex") {
            cout << "Thank You For Used This Program ^ ^" << enl;
            break;
        }
        cout << "If TO ADD Press 1" << enl << "If TO READ Press 2" << enl;
        string k;
        cin >> k;
        if (k == "1") {
            cout << "If TO ADD_DOC Write Doc" << enl << "If TO ADD_Patient Write Pateint" << enl;
            string o;
            cin >> o;
            ADD_Data(o);
        }
        else {
            cout << "If TO READ_DOC Write Doc" << enl << "If TO READ_Patient Write Pateint" << enl;
            string o;
            cin >> o;
            READ_Data(o);
        }
    }
    return 0;
}
