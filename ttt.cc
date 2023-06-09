
#include <iostream>
#include <Windows.h>
#include <random>
#include <string>
#include <cstdlib>
#include <ctime>




//OOPS CONCEPT USED:

// Classes: My code defines multiple classes such as change, printboard, win, AI, dumbAI, and geniusAI. These classes encapsulate related data and behavior.
// Objects: Instances of the classes are created using the class definitions. For example, objects of classes change, printboard, win, dumbAI, and geniusAI are created throughout the code. all mainly in the base code, main function.
// Encapsulation: The classes in my code encapsulate related data and methods within themselves. They define private member variables and provide public member functions to interact with those variables.
// Abstraction: The AI class defines a pure virtual function putshape(), making it an abstract class. Other classes (dumbAI and geniusAI) inherit from this class and override the putshape() function with their own implementations. You can see the comment i used before implementing them
// Inheritance: The classes dumbAI and geniusAI inherit from the AI class. They inherit the common behavior defined in the base class and provide their specific implementations for the putshape() function.
// Polymorphism: The code demonstrates polymorphism through function overriding. The putshape() function is defined as a virtual function in the AI class and is overridden in the derived classes dumbAI and geniusAI with their respective implementations, no need to use overloading though, so didnt use.


using namespace std;


//creating CLASS. I created many classes and objects throughout the code, wherever you see "class" keyword, know that I created a class which 
//is nothing but a protoype

//this class have changing() functions is used to change the abcdefghi which is the input from user into 2d array index like (1,2) etc.
class change{

    public:

        void changing(string chose, int &chosedx, int &chosedy){

            if(chose=="a"){
                chosedx=0;
                chosedy=0;
            }

            else if(chose=="b"){
                chosedx=0;
                chosedy=1;
            }

            else if(chose=="c"){
                chosedx=0;
                chosedy=2;
            }

            else if(chose=="d"){
                chosedx=1;
                chosedy=0;
            }

            else if(chose=="e"){
                chosedx=1;
                chosedy=1;
            }

            else if(chose=="f"){
                chosedx=1;
                chosedy=2;
            }

            else if(chose=="g"){
                chosedx=2;
                chosedy=0;
            }

            else if(chose=="h"){
                chosedx=2;
                chosedy=1;
            }
            
            else if(chose=="i"){
                chosedx=2;
                chosedy=2;
            }
        
        }

};


//As the name suggests, this class have printboard funciton to print the current board taking the 2d array input

class printboard{

//main 
// Printboard p = new Printboard(3); - - - X 0
    // private:
    // int size;
    // int arr1[][];

    public:
    /*
    printboard(int m){
        int arr[m][m];
         for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    -----
                }
            }
            this->size=m;
            this->arr1= arr;
    }
    */

        void printing(string arr[3][3]){

            for(int i=0;i<3;i++){
                cout<<"|";
                for(int j=0;j<3;j++){
                    cout<<arr[i][j]<<"|";
                }

                cout<<"\n";
            }
        }
};



//this one is used to check if someone won or not, called everytime user or computer gives input to the array

class win{

    public:

        void winornot(string arr[3][3], int &winner){

            string str1,str2,str3,str4;

            str3=" ";
            str4=" ";

            for(int i=0;i<3;i++){

                str1=" ";
                str2=" ";
                for(int j=0;j<3;j++){
                    str1+=arr[i][j];
                    str2+=arr[j][i];
                }
                str3+=arr[i][i];
                str4+=arr[0][2]+arr[1][1]+arr[2][0];

                if(str1==" XXX" || str2==" XXX" || str3==" XXX" || str4==" XXX"){
                    winner=1;
                    return;
                }
                else if(str1==" OOO" || str2==" OOO" || str3==" OOO" || str4==" OOO"){
                    winner=2;
                    return;
                }
            }
        }
};


//base class of 2 AI named dumbAI and genius AI to later be called from inheritence and do the logic I wrote

class AI{

    public:

        //using of ABSTRACTION
        virtual void putshape(int already[9],string arr[3][3], int &chosedx, int &chosedy, int &randr) = 0; //using virtual keyword to make pure virtual function to abstract the function.
                                    //whenever i create class inherited from this class, then that inherited one should have putshape function
                                    //which must override this putshape function
                                    //and this is how I used ABSTRACTION

};



//I used POLYMORPHISM to define difference classes with same functions name, later will use overriding for calling functions in base main()



//this will give index of a random number which is in array bound index and and not "O" and "X"

//creating dumbAI inherited from AI class, and this is called INHERITANCE

class dumbAI: public AI{
    // dumbAI da = new dumbAI();
    //AI a = new 
    //dA.putshake()


    //ENCAPTULATION
    //I declared variables in private which are only accessible in the same class, it is encaptulating the data
    //encaptulation is used to achieve data abstraction and data hiding, so this is one of the way to use encaptulation
    //if i want to, i can modify this private members (getter and setter), but only in the same class

    private:

        int chosedx,chosedy;
        int whilebreaker,randr;

    public:

        void putshape(int already[9],string arr[3][3], int &chosedx, int &chosedy, int &randr) override{

            whilebreaker=0;
            while(whilebreaker==0){

            //seeding srand through time which will help me generate different random number with different time
            srand(time(nullptr));
            this -> randr = (rand() % (9)) + 0 ;

                //if the array already have "X" or "O";
                if(already[this->randr]==1){
                    whilebreaker=0;
                }

                //if not then run the logic to return x and y as per the random generated
                else if(already[this->randr]==0){

                    int integer_value = this->randr + 97; // Integer value for ASCII character 'a'

                    // Convert integer to ASCII character
                    char ascii_char = char(integer_value);

                    // Convert ASCII character to string
                    string char_string=" ";
                    char_string[0]=ascii_char;

                    change coor;
                    coor.changing(char_string, this->chosedx, this->chosedy); //used THIS keyword, personally the best and most useful keyword 
                                                                                //for OOPS user
                    //wherever "this->" is, it denotes the variable declared in the class and not the variable came from function parameters.
                    chosedx=this->chosedx;
                    chosedy=this->chosedy;
                    randr=this->randr;
                    
                    whilebreaker=1;

                }
                else{
                    continue;
                }
            }
        }
};



//geniusAI as you can guess have logic to give the index of 2d array which is best to win. I created logic and this is the biggest class throughout the code

class geniusAI: public AI{

    public:

        //function to change 1d array index into 2d array index, used for already[] array to convert into arr[][], what are these array? you will know in base funciton main()
        void randrchange(int chosedx,int chosedy,int &randr){
            randr = chosedx * 3 + chosedy;
        }

        char strcross(string& str){
            int countXO=0;
            for(char c : str){
                if(c=='X' || c=='O'){
                    countXO+=1;
                }
            }
            if(countXO==3){
                return 'b';
            }
            return str[0];
        }

        //function for if neither it defences nor it attacks, then return the the one which group have only one O, then we will have more chance to win later

        char strnone(string& str){
            int countAlpha=0;
            int countO = 0;
            for (char c : str){
                if(c!='O' && c!='X' && c!=' '){
                    countAlpha++;
                }
                if(c=='O'){
                    countO++;
                }
            }

            if(countAlpha == 2){
                if(countO == 1){
                    for (int i = 1; i<4; i++){
                        if(str[i]!='O'){
                            return str[i];
                        }
                    }
                }
            }

            return str[0];
        }


        //strcheckO for attacking, when any group have 2 "O" then return the array to fill non "O"

        char strcheckO(string& str){
            int countO = 0;
            for (char c : str) {
                if (c == 'O') {
                    countO++;
                }
            }

            if (countO == 2) {
                for (int i = 1; i < 4; i++) {
                    if (str[i] != 'X' && str[i] != 'O') {
                        return str[i];
                    }
                }
            }
            return str[0];
        }

        //strcheckX for defence, if the group have 2 "X" then block by putting one "O" in non "X"

        char strcheckX(string& str){

            int countX = 0;
            for (char c : str) {
                if (c == 'X') {
                    countX++;
                }
            }

            if (countX == 2) {
                for (int i = 1; i < 4; i++) {
                    if (str[i] != 'X' && str[i] != 'O') {
                            return str[i];
                    }
                }
            }
            return str[0];

        }

        //this function is i created for best return value if the game just started and neither defence nor attack is happening ofcourse because game just got one round 

        char strcheckwhich(string& str){

            int countX=0;
            int countO=0;
            for(char c : str){
                if(c == 'O'){
                    countO++;
                }
                
                if(countO == 1){
                    
                    if(str[1] == 'O' || str[2] == 'O' && str[3] != 'X'){
                        return str[3];
                    }
                    if(str[3] == 'O' && str[1] != 'X'){
                        return str[1];
                    }

                }
            }
            return str[0];

        }


        //the main putshape overridden function to be called by base main() and to call all other necassary funcitons

        void putshape(int already[9],string arr[3][3], int &chosedx, int &chosedy, int &randr) override{

            //we have alreadyp[] array which is explained in main()

            int count=0;
            for(int i=0;i<9;i++){
                if(already[i]==1){
                    count+=1;
                }
            }

            string str1,str2,str3,str4;

            //when the game is gone more than 1 round, it must attack or defence everytime

            if(count>=3){

                //for attack, first priority

                str3=" "+arr[0][0]+arr[1][1]+arr[2][2];
                str4=" "+arr[0][2]+arr[1][1]+arr[2][0];
                for(int i=0;i<3;i++){
                    str1=" ";
                    str2=" ";
                    for(int j=0;j<3;j++){
                        str1+=arr[i][j];
                        str2+=arr[j][i];
                    }

                    char check;
                    string checks;

                    check = strcheckO(str1);
                    checks = string(1,check);
                    if(checks!=" "){
                        change chch;
                        chch.changing(checks , chosedx , chosedy);
                        randrchange(chosedx, chosedy, randr);
                        return;
                    }
                    
                    check = strcheckO(str2);
                    checks = string(1,check);
                    if(checks!=" "){
                        change chch;
                        chch.changing(checks , chosedx , chosedy);
                        randrchange(chosedx, chosedy, randr);
                        return;
                    }

                    check = strcheckO(str3);
                    checks = string(1,check);
                    if(checks!=" "){
                        change chch;
                        chch.changing(checks , chosedx , chosedy);
                        randrchange(chosedx, chosedy, randr);
                        return;
                    }

                    check = strcheckO(str4);
                    checks = string(1,check);
                    if(checks!=" "){
                        change chch;
                        chch.changing(checks , chosedx , chosedy);
                        randrchange(chosedx, chosedy, randr);
                        return;
                    }
                }


                //for defence, second priority

                str3=" "+arr[0][0]+arr[1][1]+arr[2][2];
                str4=" "+arr[0][2]+arr[1][1]+arr[2][0];
                for(int i=0;i<3;i++){
                    str1=" ";
                    str2=" ";
                    for(int j=0;j<3;j++){
                        str1+=arr[i][j];
                        str2+=arr[j][i];
                    }

                    char check = strcheckX(str1);
                    string checks = string(1,check);
                    if(checks!=" "){
                        change chch;
                        chch.changing(checks , chosedx , chosedy);
                        randrchange(chosedx, chosedy, randr);
                        return;
                    }
                    
                    check = strcheckX(str2);
                    checks = string(1,check);
                    if(checks!=" "){
                        change chch;
                        chch.changing(checks , chosedx , chosedy);
                        randrchange(chosedx, chosedy, randr);
                        return;
                    }

                    check = strcheckX(str3);
                    checks = string(1,check);
                    if(checks!=" "){
                        change chch;
                        chch.changing(checks , chosedx , chosedy);
                        randrchange(chosedx, chosedy, randr);
                        return;
                    }

                    check = strcheckX(str4);
                    checks = string(1,check);
                    if(checks!=" "){
                        change chch;
                        chch.changing(checks , chosedx , chosedy);
                        randrchange(chosedx, chosedy, randr);
                        return;
                    }
                    
                }
            }

            //then if the game just started then whatever the positon user chosed, got the best index according to it used logic to get the position

            if(count==1){

                //for if user chosed middle
                if(already[4]==1){

                    //then randomly give any corner
                    srand(static_cast<unsigned>(time(0)));
                    int randomNumber = rand() % 2;
                    chosedx = (randomNumber == 0) ? 0 : 2;
                    chosedy= (randomNumber == 0) ? 0 : 2;
                    randrchange(chosedx, chosedy, randr);
                    return;

                }

                //for if user chosed corner
                if(already[0]==1 || already[2] == 1 || already[6] == 1 || already[8] == 1){

                    //then give middle
                    chosedx=1;
                    chosedy=1;
                    randrchange(chosedx, chosedy, randr);
                    return;
                }


                //for if user chosed side
                if(already[1]==1 || already[3] == 1 || already[5] == 1 || already[7] == 1){

                    //then randomly generate any corner
                    srand(static_cast<unsigned>(time(0)));
                    int randomNumber = rand() % 2;
                    chosedx = (randomNumber == 0) ? 0 : 2;
                    chosedy= (randomNumber == 0) ? 0 : 2;
                    randrchange(chosedx, chosedy, randr);
                    return;

                }
            }


            //for if game just started and goes for one round, neither attack nor defence is possible

            if(count==3){

                str3=" "+arr[0][0]+arr[1][1]+arr[2][2];
                str4=" "+arr[0][2]+arr[1][1]+arr[2][0];

                char check = strcross(str3);
                string checks = string(1,check);
                if(checks!=" "){
                    change chch;
                    chch.changing(checks , chosedx , chosedy);
                    randrchange(chosedx, chosedy, randr);
                    return;
                }

                check = strcross(str4);
                checks = string(1,check);
                if(checks!=" "){
                    change chch;
                    chch.changing(checks , chosedx , chosedy);
                    randrchange(chosedx, chosedy, randr);
                    return;
                }

                for(int i=0;i<3;i++){
                    str1=" ";
                    str2=" ";
                    for(int j=0;j<3;j++){
                        str1+=arr[i][j];
                        str2+=arr[j][i];
                    }

                    check = strcheckwhich(str1);
                    checks = string(1,check);
                    if(checks!=" "){
                        change chch;
                        chch.changing(checks , chosedx , chosedy);
                        randrchange(chosedx, chosedy, randr);
                        return;
                    }

                    check = strcheckwhich(str2);
                    checks = string(1,check);
                    if(checks!=" "){
                        change chch;
                        chch.changing(checks , chosedx , chosedy);
                        randrchange(chosedx, chosedy, randr);
                        return;
                    }
                    
                    check = strcheckwhich(str3);
                    checks = string(1,check);
                    if(checks!=" "){
                        change chch;
                        chch.changing(checks , chosedx , chosedy);
                        randrchange(chosedx, chosedy, randr);
                        return;
                    }

                    check = strcheckwhich(str4);
                    checks = string(1,check);
                    if(checks!=" "){
                        change chch;
                        chch.changing(checks , chosedx , chosedy);
                        randrchange(chosedx, chosedy, randr);
                        return;
                    }
                }

            }


            //for when game goes more that 1 round and neither attack on defence is possible, run this.

            if(count>=3){

                str3=" "+arr[0][0]+arr[1][1]+arr[2][2];
                str4=" "+arr[0][2]+arr[1][1]+arr[2][0];

                for(int i=0;i<3;i++){
                    str1=" ";
                    str2=" ";
                    for(int j=0;j<3;j++){
                        str1+=arr[i][j];
                        str2+=arr[j][i];
                    }
                
                    char check = strnone(str1);
                    string checks = string(1,check);
                    if(checks!=" "){
                        change chch;
                        chch.changing(checks , chosedx , chosedy);
                        randrchange(chosedx, chosedy, randr);
                        return;
                    }

                    check = strnone(str2);
                    checks = string(1,check);
                    if(checks!=" "){
                        change chch;
                        chch.changing(checks , chosedx , chosedy);
                        randrchange(chosedx, chosedy, randr);
                        return;
                    }
                    
                    check = strnone(str3);
                    checks = string(1,check);
                    if(checks!=" "){
                        change chch;
                        chch.changing(checks , chosedx , chosedy);
                        randrchange(chosedx, chosedy, randr);
                        return;
                    }

                    check = strnone(str4);
                    checks = string(1,check);
                    if(checks!=" "){
                        change chch;
                        chch.changing(checks , chosedx , chosedy);
                        randrchange(chosedx, chosedy, randr);
                        return;
                    }
                }    

                
            }

        }
};






//--------------------------





//YAYY base function

int main(){

    //initially arr[] array which is the main baord, containing alphabets
    string arr[3][3] = {{"a","b","c"},{"d","e","f"},{"g","h","i"}};

    //creating INSTANCE OF THE VARIABLE to create objects and use it.
    //did many times in the code this is the first so i added comment, if you see anything like this which will have difference name of class.

    cout<<"\nWELCOME TO MY TIC TAC TOE GAME, I AM CREATED BY SHAHAN'S LOGIC, HOW DO YOU SUPPOSE TO BEAT ME THEN?\n"<<endl;

    printboard firstboard;
    firstboard.printing(arr);

    int n;

    cout<<"\nEnter number corresponding to the AI you want to play with: "<<endl;
    cout<<"1. Dumb AI \n2. Genius AI"<<endl;
    cin>>n;

    string chose;
    int chosedx,chosedy;
    int randr,winner=0;
    int moves = 0;

    //already[] array which is used to get whether the arr[][] position is filled with 'X' or 'O' or not.
    //put 1 if the arr[][] position is filled and leave 0 if position is free to use
    int already[9]={0,0,0,0,0,0,0,0,0};


    //if chosed dumbAI
    if(n==1){

        cout<<"\noh so you are afraid of losing, well done loser, now lets play the game\n";

        while(winner!=1 && winner!=2 && moves!=9){
            
            cout<<"\nhere is your table of tic tac toe: \n"<<endl;
            firstboard.printing(arr);

            cout<<"\n\nEnter the letter you want to play, its your turn, chose from a,b,c,d,e,f,g,h,i"<<endl;
            cin>>chose;
            
            change coor;
            coor.changing(chose,chosedx,chosedy);

            if(chose!="a" || chose!="b" || chose!="c" || chose!="d" || chose!="e" || chose!="f" || chose!="g" || chose!="h" || chose!="i" || arr[chosedx][chosedy]=="O" || arr[chosedx][chosedy]=="X"){
                while(chose!="a" && chose!="b" && chose!="c" && chose!="d" && chose!="e" && chose!="f" && chose!="g" && chose!="h" && chose!="i" || arr[chosedx][chosedy]=="O" || arr[chosedx][chosedy]=="X"){
                    cout<<"Enter right value sir\n";
                    cout<<"Chose from a,b,c,d,e,f,g,h,i\n";
                    coor.changing(chose,chosedx,chosedy);
                    cin>>chose;
                }
            }
            cout<<"\n";

            char character= chose[0];
            int x= int(character)-97;

            already[x]=1;
            arr[chosedx][chosedy]="X";

            moves++;

            printboard tempboard;
            tempboard.printing(arr);
            
            win checkwin;
            checkwin.winornot(arr, winner);

            if(winner==1){
                cout<<"WELL DONE YOU WON, BUT YOU STILL DUMB"<<endl;
                break;
            }

            else if(winner==2){
                cout<<"I WON! HOW CAN YOU BE SUCH STUPID AND DUMB THAT YOU LOST THIS LEVEL,YOU ARTS STUDENT OR WUT? GO PRACTISE DUDE";
                break;
            }

            else if (moves == 9) {
                // All positions filled, it's a draw
                cout<<"DRAW! IS THAT ALL YOU GOT";
                break;
            }

            cout<<"\nLet me think...\n";
            Sleep(2000);

            //POLYMORPHISM
            //I have putshape in AI*, but assigning dumbAI to it lead to use putshape function of dumbAI and not other putshape()
            //I used OVERRIDING which is a runtime polymorphism

            dumbAI ans;
            ans.putshape(already, arr, chosedx, chosedy, randr);

            already[randr]=1;
            arr[chosedx][chosedy]="O";

            moves++;

            cout<<"\nThis is my answer\n"<<endl;
            tempboard.printing(arr);

            checkwin.winornot(arr, winner);

            if(winner==1){
                cout<<"\nWELL DONE YOU WON, BUT YOU STILL DUMB"<<endl;
                break;
            }

            else if(winner==2){
                cout<<"\nI WON, YOU ARE SO STUPID LOL";
                break;
            }
            
            else if (moves == 9) {
                // All positions filled, it's a draw
                cout<<"\nIT'S A DRAW! HOW STUPID ARE YOU?"<<endl;
                break;
            }

        }

    }


    //if chosed geniusAI
    if(n==2){
        
        cout<<"\nSo you accept the real chalenge han?, lets see what you got. \n";

        while(winner!=1 && winner!=2 && moves!=9){
            
            cout<<"\nhere is your table of tic tac toe: \n"<<endl;
            firstboard.printing(arr);

            cout<<"\n\nEnter the letter you want to play, its your turn first, chose from a,b,c,d,e,f,g,h,i"<<endl;
            cin>>chose;
            
            change coor;
            coor.changing(chose,chosedx,chosedy);

            if(chose!="a" || chose!="b" || chose!="c" || chose!="d" || chose!="e" || chose!="f" || chose!="g" || chose!="h" || chose!="i" || arr[chosedx][chosedy]=="O" || arr[chosedx][chosedy]=="X"){
                while(chose!="a" && chose!="b" && chose!="c" && chose!="d" && chose!="e" && chose!="f" && chose!="g" && chose!="h" && chose!="i" || arr[chosedx][chosedy]=="O" || arr[chosedx][chosedy]=="X"){
                    cout<<"And you want to play me, cant type the right letter?\n";
                    cout<<"Chose from a,b,c,d,e,f,g,h,i\n";
                    coor.changing(chose,chosedx,chosedy);
                    cin>>chose;
                }
            }
            cout<<"\n";
            char character= chose[0];
            int x= int(character)-97;

            already[x]=1;
            arr[chosedx][chosedy]="X";

            moves++;

            printboard tempboard;
            tempboard.printing(arr);
            
            win checkwin;
            checkwin.winornot(arr, winner);

            if(winner==1){
                cout<<"\nOUUH NICE ONE, YOU ARE PRETTY GENIU.... NAH YOU STILL DUMB. "<<endl;
                break;
            }

            else if(winner==2){
                cout<<"\nI WON, Dont cry alelele";
                break;
            }

            else if (moves == 9) {
                // All positions filled, it's a draw
                cout<<"\nDRAW! IS THAT ALL YOU GOT?";
                break;
            }

            cout<<"\nLet me think...\n";
            Sleep(2000);

            //POLYMORPHISM again
            //I have putshape in AI*, but assigning geniusAI to it lead to use putshape function of geniusAI and not other putshape()
            //I used OVERRIDING which is a runtime polymorphism

            geniusAI ans;
            ans.putshape(already, arr, chosedx, chosedy, randr);

            already[randr]=1;
            arr[chosedx][chosedy]="O";

            moves++;

            cout<<"\nThis is my answer\n"<<endl;
            tempboard.printing(arr);

            checkwin.winornot(arr, winner);

            if(winner==1){
                cout<<"\nOUUH NICE ONE, YOU ARE PRETTY GENIU.... NAH YOU STILL DUMB. "<<endl;
                break;
            }

            else if(winner==2){
                cout<<"\nI WON, Dont cry alelele";
                break;
            }

            else if (moves == 9) {
                // All positions filled, it's a draw
                cout<<"\nDRAW! IS THAT ALL YOU GOT?";
                break;
            }

        }
    }
}

