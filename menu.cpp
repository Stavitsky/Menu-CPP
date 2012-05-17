#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>

using namespace std;
int const lim=6; // количество строк

int getch(){ //для работы getch
        int ch;
        struct termios oldt, newt;
        tcgetattr( STDIN_FILENO, &oldt );
        newt = oldt;
        newt.c_lflag &= ~( ICANON | ECHO );
        tcsetattr( STDIN_FILENO, TCSANOW, &newt );
        ch = getchar();
        tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
        return ch;
}
void func(){
    cout<<"hi";
    getch();
}

class Menu{
    private:
    string menu[lim];
    string menuelements[lim];
    int kol;
    public:
    Menu() {kol=0;};
        void Add(string Str){
            menuelements[kol]=Str;
            kol++;
            for(int i=0;i<kol;i++){
            menu[i]="   "+menuelements[i]; //
            }
        }
        void Print(){
           cout<< endl;
        for(int i=0;i<kol;i++){
            for (int j=0;abs(j)< menu[i].size();j++){ //как двумерный
            cout<<menu[i][j];
            }
      cout<< endl;
            }
        }
        void Push(int item){//реакция на нажатие
            menu[item]=" > "+menuelements[item]; //движение выделения (стрелочки)
            int i=0;
            while (i<kol){//невыделенные жлементы
            if (i!=item){
                menu[i]="   "+menuelements[i]; //пробелы, для ровности
                }
                i++;
            }
        }
        int Sum(){
        return kol;
        }
};

int main() {
Menu *MainMenu= new Menu; //строки
	MainMenu->Add("1. Files");
    MainMenu->Add("2. Show");
    MainMenu->Add("3. Add");
    MainMenu->Add("4. Edit");
    MainMenu->Add("5. Delete");
    MainMenu->Add("6. Exit");

    Menu *FileMenu= new Menu;
    FileMenu->Add("1. Open file");
    FileMenu->Add("2. Save changes");
    FileMenu->Add("3. Back to main menu");

 /*   Menu *ShowMenu= new Menu;
    ShowMenu->Add("1.Back to main menu");*/

    Menu *AddMenu= new Menu;
    AddMenu->Add("1. Add in top");
    AddMenu->Add("2. Add in center");
    AddMenu->Add("3. Add after item");
    AddMenu->Add("4. Back to main menu");

    Menu *DeleteMenu= new Menu;
    DeleteMenu->Add("1. Delete first item");
    DeleteMenu->Add("2. Delete item for number");
    DeleteMenu->Add("3. Back to main menu");


    Menu *EditMenu= new Menu;
    EditMenu->Add("1. Change name item");
    EditMenu->Add("2. Change plases");
    EditMenu->Add("3. Back to main menu");

    Menu *ExitMenu= new Menu;
    ExitMenu->Add("1. Yes");
    ExitMenu->Add("2. No");

	int selected_item = 0;
	int selected_item_f = 0;
	//int selected_item_s = 0;
	int selected_item_a = 0;
	int selected_item_d = 0;
	int selected_item_e = 0;
	int selected_item_q = 0;
    MainMenu->Push(selected_item);
	cout << "Main menu:";
	MainMenu->Print();
	while (true){

    //-----------------------------------------Основное меню------------------------------------------------
    switch (getch()) {
	case 65://вверх
            system("clear");
            cout << "Main menu:";
            selected_item--;
            if(selected_item<0){
                selected_item=MainMenu->Sum()-1;
            }

           MainMenu->Push(selected_item);
            MainMenu->Print();
			break;
		case 66://вниз
			system("clear");
			cout << "Main menu:";
			selected_item++;
		if (selected_item>MainMenu->Sum()-1){
		selected_item=0;
		}

		 MainMenu->Push(selected_item);
            MainMenu->Print();

break;
case 49: //цифра 1 "файл"
selected_item=0;

system("clear");
cout << "Main menu:";
 MainMenu->Push(selected_item);
            MainMenu->Print();
break;

case 50: //цифра 2 "просмотр"
selected_item=1;
system("clear");
cout << "Main menu:";
MainMenu->Push(selected_item);
MainMenu->Print();
break;

case 51://цифра 3 "добавить"
selected_item=2;
system("clear");
cout << "Main menu:";
MainMenu->Push(selected_item);
MainMenu->Print();
break;

case 52://цифра 4 "редактировать"
selected_item=3;
system("clear");
cout << "Main menu:";
MainMenu->Push(selected_item);
MainMenu->Print();
break;

case 53://цифра 5 "удалить"
selected_item=4;
system("clear");
cout << "Main menu:";
MainMenu->Push(selected_item);
MainMenu->Print();
break;

case 54://цифра 6 "выход"
selected_item=5;
system("clear");
cout << "Main menu:";
MainMenu->Push(selected_item);
MainMenu->Print();
break;


case 113: // кнопка Q
 goto ex; //одной кнопкой сразу в выход из всего меню
break;

case 10: //enter
    switch (selected_item){
            case 0:
//------------------------------------Вход в подменю "Файл"-------------------------------


            system("clear");
            cout << "File menu:";
            FileMenu->Push(selected_item_f);
            FileMenu->Print();
            int a;
                  do  {
                    a=getch();
                    switch (a) {

                    case 65://вверх
                        system("clear");
                        cout << "File menu:";
                        selected_item_f--;
                        if(selected_item_f<0){
                            selected_item_f=FileMenu->Sum()-1;
                        }

                        FileMenu->Push(selected_item_f);
                        FileMenu->Print();

                    break;
                    case 66://вниз
                        system("clear");
                        cout << "File menu:";
                        selected_item_f++;
                        if(selected_item_f>FileMenu->Sum()-1){
                            selected_item_f=0;
                        }

                        FileMenu->Push(selected_item_f);
                        FileMenu->Print();
                    break;

                  case 27://fail - main
                        system("clear");
                        MainMenu->Print();
                    break;
                        //break;
                        case 10:
                        switch(selected_item_f){//выход в главное
                        case 2:
                        system("clear");
                        cout << "Main menu:";
                        MainMenu->Print();
                        break; }

break;




                    }
                  }
                    while ((a!=10 || selected_item_f!=2 )&& a!=113);
                    system("clear");
                    cout<<"Main menu:";
                    MainMenu->Print();
            break;

/*case 10:
//--------------------------Вход в подменю "Показать"------------
            case 1:
            system("clear");
            cout << "Show menu:";
            ShowMenu->Push(selected_item_s);
            ShowMenu->Print();
            do  {
                    a=getch();
                    switch (a) {
                    case 65://вверх
                        system("clear");
                        cout << "Add menu:";
                        selected_item_s--;
                        if(selected_item_s<0){
                            selected_item_s=AddMenu->Sum()-1;
                        }

                        AddMenu->Push(selected_item_s);
                        AddMenu->Print();

                    break;
                    case 66://вниз
                        system("clear");
                        cout << "Add menu:";
                        selected_item_s++;
                        if(selected_item_s>AddMenu->Sum()-1){
                            selected_item_s=0;
                        }

                        AddMenu->Push(selected_item_s);
                        AddMenu->Print();
break;

                        case 10:
                        switch(selected_item_s){//Exit to main menu
                        case 1:
                        system("clear");
                        cout << "Main menu:";
                        MainMenu->Print();
                        break;
                        }
                        break;
                    }
                    }
                    while ((a!=10 || selected_item_a!=1)&& a!=113);
                    system("clear");
                    cout<<"Main menu:";
                    MainMenu->Print();
           break;




*/
case 10:
//------------------------------Вход в подменю "добавить"-------------------------

            case 2:
            system("clear");
            cout << "Add menu:";
            AddMenu->Push(selected_item_a);
            AddMenu->Print();
                  do  {
                    a=getch();
                    switch (a) {
                    case 65://вверх
                        system("clear");
                        cout << "Add menu:";
                        selected_item_a--;
                        if(selected_item_a<0){
                            selected_item_a=AddMenu->Sum()-1;
                        }

                        AddMenu->Push(selected_item_a);
                        AddMenu->Print();

                    break;
                    case 66://вниз
                        system("clear");
                        cout << "Add menu:";
                        selected_item_a++;
                        if(selected_item_a>AddMenu->Sum()-1){
                            selected_item_a=0;
                        }

                        AddMenu->Push(selected_item_a);
                        AddMenu->Print();
break;

                        case 10:
                        switch(selected_item_a){//Exit to main menu
                        case 3:
                        system("clear");
                        cout << "Main menu:";
                        MainMenu->Print();
                        break;
                        }
                        break;
                    }
                    }
                    while ((a!=10 || selected_item_a!=3)&& a!=113);
                    system("clear");
                    cout<<"Main menu:";
                    MainMenu->Print();
           break;
        case 3:
//---------------------------Вход в подменю "редактировать"----------------------------------------
            system("clear");
            cout << "Edit menu:";
            EditMenu->Push(selected_item_e);
            EditMenu->Print();
                  do  {
                    a=getch();
                    switch (a) {
                    case 65://вверх
                        system("clear");
                        cout << "Edit menu:";
                        selected_item_e--;
                        if(selected_item_e<0){
                            selected_item_e=EditMenu->Sum()-1;
                        }

                        EditMenu->Push(selected_item_e);
                        EditMenu->Print();

                    break;
                    case 66://вниз
                        system("clear");
                        cout << "Edit menu:";
                        selected_item_e++;
                        if(selected_item_e>EditMenu->Sum()-1){
                            selected_item_e=0;
                        }

                        EditMenu->Push(selected_item_e);
                        EditMenu->Print();
                    break;

                        case 10:
                        switch(selected_item_e){//Exit to main menu
                        case 2:
                        system("clear");
                        cout << "Main menu:";
                        MainMenu->Print();
                        break;
                        }
break;



                    }
                  }
                    while ((a!=10 || selected_item_e!=2)&& a!=113);
                    system("clear");
                    cout<<"Main menu:";
                    MainMenu->Print();

            break;
       case 4:
//-------------------------------Вход в подменю "удалить"---------------------------
            system("clear");
            cout << "Delete menu:";
            DeleteMenu->Push(selected_item_d);
            DeleteMenu->Print();
                  do  {
                    a=getch();
                    switch (a) {
                    case 65://вверх
                        system("clear");
                        cout << "Delete menu:";
                        selected_item_d--;
                        if(selected_item_d<0){
                            selected_item_d=DeleteMenu->Sum()-1;
                        }

                        DeleteMenu->Push(selected_item_d);
                        DeleteMenu->Print();

                    break;
                    case 66://вниз
                        system("clear");
                        cout << "Delete menu:";
                        selected_item_d++;
                        if(selected_item_d>DeleteMenu->Sum()-1){
                            selected_item_d=0;
                        }

                        DeleteMenu->Push(selected_item_d);
                        DeleteMenu->Print();
                    break;

                        case 10:
                        switch(selected_item_d){//Exit to main menu
                        case 2:
                        system("clear");
                        cout << "Main menu:";
                        MainMenu->Print();
                        break; }
break;

                    }
                  }
                    while ((a!=10 || selected_item_d!=2)&& a!=113);
                    system("clear");
                    cout<<"Main menu:";
                    MainMenu->Print();

            break;

            case 5:
//------------------------------------Вход в подменю "выход"-------------------
     ex: system("clear");
            cout << "Are you sure?";
            ExitMenu->Push(selected_item_q);
            ExitMenu->Print();
                  do  {
                    a=getch();
                    switch (a) {
                    case 65://вверх
                        system("clear");
                        cout << "Are you sure?";
                        selected_item_q--;
                        if(selected_item_q<0){
                            selected_item_q=ExitMenu->Sum()-1;
                        }

                        ExitMenu->Push(selected_item_q);
                        ExitMenu->Print();

                    break;
                    case 66://вниз
                        system("clear");
                        cout << "Are you sure?";
                        selected_item_q++;
                        if(selected_item_q>ExitMenu->Sum()-1){
                            selected_item_q=0;
                        }

                        ExitMenu->Push(selected_item_q);
                        ExitMenu->Print();
                    break;


                        case 10:
                        switch(selected_item_q){//Exit to main menu
                        case 0:
                        system("clear");
                        cout << "Good bye!";
                        exit(0);
                        break;
                        case 1:
                        system("clear");
                        cout << "Main menu:";
                        MainMenu->Print();
                        break;}
break;



                    }
                  }
                    while ((a!=10 || selected_item_q!=1)&& a!=113);
                    system("clear");
                    cout<<"Main menu:";
                    MainMenu->Print();

            break;
            break;
}

}

}

}


