#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5+5,MOD = 998244353,INF = 2e18;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
ll n, m, t, q, x;
struct info
{
    string fname;
    string lname;
    string bloodtype;
    char gender;
    string age;
    string mobilenumber;
};
deque<info> department[6];
class parent{
private:
    info take_data()
    {
        cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
        cout<< "  Please enter data for patient\n\n  ";
        string fname,lname,bloodtype,phone,age,check = "0123456789";
        char gender;
        cout <<"First name     : ";
        cin >> fname;
        cout <<"\n  Last name      : ";
        cin >> lname;
        while(1)
        {
            cout <<"\n  Blood Type     : ";
            cin >> bloodtype;
            for(auto &it:bloodtype)
                it = tolower(it);
            if(bloodtype == "a+" || bloodtype == "a-" || bloodtype == "b+" || bloodtype == "b-"
                    || bloodtype == "ab+" || bloodtype == "ab-")
                break;
            cout << "\n  Invalid Blood Group Try Again.. \n";
        }
        while(1)
        {
            cout <<"\n  Gender(m/f)     : ";
            cin >> gender;
            gender = towlower(gender);
            if(gender == 'm' || gender == 'f')
                break;
            cout << "\n  Invalid Gender Try Again.. \n";
        }
        while(1){
            cout <<"\n  Age            : ";
            cin >> age;
            int ok = (age[0] != '0');
            for(auto it:age)
            {
                int tmm = 0;
                for(auto it2 : check)
                {
                    if(it2 == it)
                        tmm = 1;
                }
                ok &= tmm;
            }
            if(ok)
                break;
            cout << "\n  Invalid Age Try Again.. \n";
        }
        while(1)
        {
            cout << "\n  Mobile number  : ";
            cin >> phone;
            int ok = (phone[0] == '0' && phone.size() == 11);
            for(auto it:phone)
            {
                int tmm = 0;
                for(auto it2 : check)
                {
                    if(it2 == it)
                        tmm = 1;
                }
                ok &= tmm;
            }
            if(ok)
                break;
            cout << "\n  Invalid Number Try Again.. \n";
        }
        return {fname,lname,bloodtype,gender,age,phone};
    }
    void confirm(info data,int ch,int i)
    {
        if((ch == 2 && i==0) || ch != 2)
            system("CLS");
        cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
        cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
        if(ch == 1)
            cout<<"  ----------PATIENT ADDED----------- ";
        viewdata(data);
        return;
    }
    void viewdata(info data)
    {
        cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
        cout<<"   Patient data:  \n\n";
        cout<<"  First Name         : ";
        cout<< data.fname << '\n';
        cout<<"  Last Name          : ";
        cout<< data.lname << '\n';
        cout<<"  Gender             : ";
        cout<< data.gender << '\n';
        cout<<"  Blood Group        : ";
        cout<< data.bloodtype << '\n';
        cout<<"  Mobile Number      : ";
        cout<< data.mobilenumber << '\n';
    }
    void view(int idx)
    {
        for(int i = 0; i < department[idx].size() ;++i){
            confirm(department[idx][i],2,i);
        }
    }
    void print(string dep)
    {

        cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
        cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
        cout<<"  " << dep << "\n\n  ";
        cout<<"[1]: Add normal patient \n  ";
        cout<<"[2]: Add critically ill patient \n  ";
        cout<<"[3]: Display list \n  ";
        cout<<"[4]: EXIT \n\n  ";
        cout<<"Please enter your choice : ";
        return;
    }
    friend class run;
};
class run:public parent
{
private:
    void make_choose()
    {
        string x;
        do
        {
            cin >> x;
            if(x == "1"){
                GENERAL();
                return;
            }else if(x == "2"){
                HEART();
                return;
            }else if(x == "3"){
                LUNG();
                return;
            }else if(x == "4"){
                PLASTIC();
                return;
            }
        }
        while(x != "5");
        system("CLS");
        cout <<"\n\t\tThank you! \n";
    }
    void GENERAL()
    {
        system("CLS");
        print("GENERAL CLINIC");
        string x,y;
        do
        {
            cin >> x;
            if(x == "1"){
                info tmp = take_data();
                confirm(tmp,1,0);
                department[1].push_back(tmp);
                cout << "\n   Press any key";
	    		cin >> y;
	 			GENERAL();
	 			return;
            }
            else if(x == "2")
            {
                info tmp = take_data();
                confirm(tmp,1,0);
                department[1].push_front(tmp);
                cout << "\n   Press any key";
                cin >> y;
	 			GENERAL();
	 			return;
            }
            else if(x == "3")
            {
                view(1);
                cout << "\n   Press any key  " << department[1].size() << endl;
	    		cin >> y;
	 			GENERAL();
	 			return;
            }
            else if(x == "4"){
                main_view();
                return;
            }else{
                GENERAL();
                return;
            }
        }
        while(x != "4");
    }
    void HEART()
    {
        system("CLS");
        print("HEART CLINIC");
        string x,y;
        do
        {
            cin >> x;
            if(x == "1"){
                info tmp = take_data();
                confirm(tmp,1,0);
                department[2].push_back(tmp);
                cout << "\n   Press any key";
	    		cin >> y;
	 			HEART();
	 			return;
            }
            else if(x == "2")
            {
                info tmp = take_data();
                confirm(tmp,1,0);
                department[2].push_front(tmp);
                cout << "\n   Press any key";
                cin >> y;
	 			HEART();
	 			return;
            }
            else if(x == "3")
            {
                view(2);
                cout << "\n   Press any key";
	    		cin >> y;
	 			HEART();
	 			return;
            }
            else if(x == "4"){
                main_view();
                return;
            }else{
                HEART();
                return;
            }
        }
        while(x != "4");
    }
    void LUNG()
    {
        system("CLS");
        print("LUNG CLINIC");
        string x,y;
        do
        {
            cin >> x;
            if(x == "1"){
                info tmp = take_data();
                confirm(tmp,1,0);
                department[3].push_back(tmp);
                cout << "\n   Press any key";
	    		cin >> y;
	 			LUNG();
	 			return;
            }
            else if(x == "2")
            {
                info tmp = take_data();
                confirm(tmp,1,0);
                department[3].push_front(tmp);
                cout << "\n   Press any key";
                cin >> y;
	 			LUNG();
	 			return;
            }
            else if(x == "3")
            {
                view(3);
                cout << "\n   Press any key";
	    		cin >> y;
	 			LUNG();
	 			return;
            }
            else if(x == "4"){
                main_view();
                return;
            }else{
                LUNG();
                return;
            }
        }
        while(x != "4");
    }
    void PLASTIC()
    {
        system("CLS");
        print("PLASTIC CLINIC");
        string x,y;
        do
        {
            cin >> x;
            if(x == "1"){
                info tmp = take_data();
                confirm(tmp,1,0);
                department[4].push_back(tmp);
                cout << "\n   Press any key";
	    		cin >> y;
	 			PLASTIC();
	 			return;
            }
            else if(x == "2")
            {
                info tmp = take_data();
                confirm(tmp,1,0);
                department[4].push_front(tmp);
                cout << "\n   Press any key";
                cin >> y;
	 			PLASTIC();
	 			return;
            }
            else if(x == "3")
            {
                view(4);
                cout << "\n   Press any key";
	    		cin >> y;
	 			PLASTIC();
	 			return;
            }
            else if(x == "4"){
                main_view();
                return;
            }else{
                PLASTIC();
                return;
            }
        }
        while(x != "4");
    }
public:
    void main_view()
    {
        system("CLS");
        cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
        cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
        cout<<"   Main Menu\n\n  ";
        cout<<"[1]: GENERAL CLINIC \n  ";
        cout<<"[2]: HEART CLINIC \n  ";
        cout<<"[3]: LUNG CLINIC \n  ";
        cout<<"[4]: PLASTIC SURGERY \n  ";
        cout<<"[5]: EXIT \n\n  ";
        cout<<"Please enter your choice : ";
        make_choose();
    }

};
int main()
{
    run start;
    start.main_view();
    return 0;
}
