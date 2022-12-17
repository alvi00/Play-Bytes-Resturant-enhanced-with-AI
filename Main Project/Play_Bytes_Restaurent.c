#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>                     //to get bolian variable



//CENACE definitions
#define INITIAL_POINT "2"
#define MAX_POINT 300
#define MIN_POINT 1
#define WIN_REWORD 3
#define DRAW_REWORD 1
#define PUNISHMENT 1

//Rock Paper Scissors definations
#define ROCK 1
#define PAPER 2
#define SCISSORS 3



//CENACE globals
int  player;
char player_X, player_O;
int  win;
char move, mark;
int  O_move_count;
char O_paths[5][50] = {'\0'};
char gameboard[10]; //this is a string
char auto_train;
int  auto_train_count, total_training_match;
int  exit_CENACE;
int  match, CENACEscore, humanScore;

//Rock Paper Scissors globals
int score, rpsMatch;

//Number Guess globals
int number_guess_game_score;

//Discount checkers
int cenaceDiscount = 0;
int flappyBirdDiscount = 0;
int numberGuessDiscount = 0;
int rockPaperScissorsDiscount = 0;

//Restaurant globals
int token = 0,tokens[50], discountToken[50], payment_counter=0;
int extraGameCharge[50];




//CENACE functions
int  CENACE();
void choose_player();
void inputmove();
void newboard();
void printboard();
int  checkwin();
int  space_in_board();
void updateLearning_data();
void menu();
void CENACE_intro();
void updateGraphing_data();
void scoreUpdate();


//Rock Paper Scissors functions
void game();                            //full function for the game
int rock_paper_scissors();

//Number Guess functions
int  number_guess();
void number_guess_game();
void load();


int main_page();
int menu_order();
void Bill_show(int arID[],int arqty[],int counter);
void Bill_Payment();
int discount();

int main()
{

    char k,j,n,d;
    k = main_page();

    if(k=='1')
    {
        menu_order();

    }

    else if(k=='2')
    {
        Bill_Payment();
    }

    else if(k=='3')
    {
        int billClear = 1;
        system("cls");
        system("color 30");
        printf("\n\n\n\n\n\t\t       @@_@_\n\t\t         `'*'`  Play Bytes Restaurant\n\t\t\t\t\t`'*'`-@@_@\n\n");
        printf("\n\n\n\t\t\tThis session order recieved : %d\n\n",token);
        printf("\t\t\tThis session bill paid      : %d\n\n",payment_counter);
        for(int i = 0; i < 50; i ++)
        {
            if(tokens[i] != 0)
            {
                printf("\t\t\t\tYet to pay          : %dtk (token %d)\n\n",tokens[i], i);
                billClear = 0;
            }
        }
        if(!billClear)
        {
            printf("\n\n\t\t\t\tYou are about to leave without clearing payment.");
            getch();
            Bill_Payment();
        }

        Sleep(2000);
        return 0;
    }

 }


int main_page()
{
    int i;
    system("title Play Bytes Restaurant");
    system("cls");
    system("color 0B");

    printf("\n\n\n\n\n\t\t\t\t      @@_@-\n\t\t\t\t\t    `'*'`\tWelcome\n\t\t\t\t\t\t\t  to\n\t\t\t\t\t\t  Play Bytes Restaurant\t\t \n\t\t\t\t\t\t\t\t\t`'*'`-@@_@\n\n");
    printf("\n\n\n\n\t\t\t\t\t\t      BITE THE BYTE. (^_^)\n\n                       ");
    for (i=0;i<30;i++)
     {
        printf("  ~");
     }
    printf("\n\n");
    printf("\t\t\t                        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $    Select any of them -          $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $    1. New Order.                 $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $    2. Bill Payment.              $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $    3. Exit.                      $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");





    char n;
    while(1)
    {
        fflush(stdin);
        printf("\n\n\n                         Enter Your Choice: ");
        scanf("%c",&n);
        fflush(stdin);
        if(n != '1' && n != '2' && n != '3')
        {
            printf("\n -----------------------You Entered Wrong Number------------------------\n  ------------------------Enter Correct Number------------------------\n");
            continue;
        }
        else break;
    }
    return n;
}


int menu_order()
{

    int arID[100],decision,arqty[100],Bill[100],counter=0;
    work:
    system("cls");
    system("color 4F");
    printf("\n\t\t\t\tFOOD MENU\n\t\t\t\t---------\n");

    printf("\n\tSides :\n\n");
    printf("\t1. French Fries (150gm)                .......................... 90/=\t  \n");
    printf("\t2. Chicken Fingers(5PCS)               .......................... 130/=\t  \n");

    printf("\n\tBURGERS :\n\n");
    printf("\t3. Chicken Burger                      .......................... 150/=\n\n\t(1:1 - Prepared with chicken patty & special sauce)\t\n\n");
    printf("\t4. Chicken Cheese Burger               .......................... 170/=\n\n\t(1:1 - Prepared with chicken patty, cheese & special sauce)\t\n\n");
    printf("\t5. Smocky BBQ Cheese Burger            .......................... 190/=\n\n\t(1:1 - Prepared with chicken patty, bbq sauce & cheese)\t\n\n");
    printf("\t6. Chicken with Baccon Burger          .......................... 220/=\n\n\t(1:1 - Prepared with chicken patty & beef bacon)\t\n\n");
    printf("\t7. Chicken with sausage Burger         .......................... 250/=\n\n\t(1:1 - Prepared with chicken patty, cheese & special sauce)\t\n\n");
    printf("\t8. Chicken Cheese Blast Burger         .......................... 250/=\n\n\t(1:1 - Prepared with 2 pcs melted cheese inside a double chicken patty & cheese outside)\t\n\n");
    printf("\t9. Double Decker Chicken Cheese Burger .......................... 270/=\n\n\t(1:1 - Prepared with 2 pcs chicken patty & 2 pcs cheese)\t\n\n");
    printf("\t10. Giganto Chicken                    .......................... 350/=\n\n\t(1:1 - Prepared with giant chicken patty, 2 pcs cheese, 2 pcs beef bacon & bbq sauce)\t\n\n");

    printf("\n\tCHICKEN :\n\n");
    printf("\t11. Chicken Breast ...................  190/=\n");
    printf("\t12. Chicken Wings ....................  105/=\n");
    printf("\t13. Boneless Strips..... .............  560/=\n");
    printf("\t14. Hot and Crispy Chicken Bucket.....  999/=\n");

    printf("\n\tPizza :\n\n");
    printf("\t15. Spicy Sausage                       .......................... 350/=\n\t\n");
    printf("\t16. Creamy Chicken & Sausage            .......................... 450/=\n\t\n");
    printf("\t17. Kolongko - The Disgrace             .......................... 770/=\n\t\n");
    printf("\t18. Simple Er Modhe Gorgeous (SMG)      .......................... 550/=\n\t\n");

    printf("\n\tLove in a Cup :\n\n");
    printf("\t19. Choco Fudge      .......................... 190/=\n\n\t(A heavenly creation of rich chocolate fudge & smooth chocolate cream in a cup)\t\n\n");
    printf("\t20. Velvety Red      .......................... 190/=\n\n\t(Divine taste of red velvet cake paired up with smooth velvety cream cheese filling for the ultimate dessert pairing)\t\n\n");
    printf("\t21. Oreo & Cheese    .......................... 190/=\n\n\t(Crunchy oreo crust & a creamy cheesecake filling together to make the ultimate cookies & cream dessert)\t\n\n");
    printf("\t22. Tiro-Miss-U      .......................... 190/=\n\n\t(An elegant & rich layed italian dessert made with cookies & cheese, combined with fluffy coffee-flavored goodness)\t\n\n ");


    printf("\n\tDRINKS :\n\n");
    printf("\t23. Coca-Cola      ........................ 40/=\n");
    printf("\t24. Pepsi          ........................ 40/=\n");
    printf("\t25. Mountain Dew   ........................ 40/=\n");
    printf("\t26. Water          ........................ 15/=\n");
    printf("\n\n\tOrder your dish: (Enter 0 to finish order)\n");
    for(;;)
    {
        counter++;
        give_arID_again:
        printf("\t Enter Food ID: ");
        scanf("%d",&arID[counter-1]);
        if(arID[counter-1]>26)
        {
            printf("\n -----------------------You Entered Wrong Number------------------------\n  ------------------------Enter Correct Number------------------------\n");
            goto give_arID_again;
        }

        if(arID[counter-1]==0)
        {
            break;
        }
        give_arqtry_again:
        printf("\t Enter Quantity: ");
        scanf("%d",&arqty[counter-1]);
        if(arqty[counter-1]<0)
        {
         printf("\n -----------------------You Entered Wrong Number------------------------\n  ------------------------Enter Correct Number------------------------\n");
         goto give_arqtry_again;
        }

    }
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\t\tThanks for your order. We are getting ready the dishes.\n\t\tUntil then, have play games to get discount. Enjoy!\n\n\n\n\n\t\t\t  <Enter 1 to check your bill>\n\t\t\tEnter your choice: ");

    scanf("%d",&decision);
    printf("\n\n\n\n\n\n\n\n");

    counter--;

    if(decision==1)
    {
        Bill_show(arID,arqty,counter);
    }

    else if(decision==2)
    {
       goto work;
    }

    else if(decision==3)
    {
        main();
    }

}

void Bill_show(int arID[],int arqty[],int counter)
{

    int n;
    system("cls");
    system("color B0");

    int i,sum=0;
    int costs[100]={90,130,150,170,190,220,250,250,270,350,190,105,560,999,350,450,770,550,190,190,190,190,40,40,40,15};
    char items[100][100]={"French Fries (150gm)","Chicken Fingers(5PCS)","Chicken Burger","Chicken Cheese Burger","Smocky BBQ Cheese Burger","Chicken with Baccon Burger","Chicken with sausage Burger","Chicken Cheese Blast Burger","Double Decker Chicken Cheese Burger","Giganto Chicken","Chicken Breast","Chicken Wings","Boneless Strips","Hot and Crispy Chicken Bucket","Spicy Sausage","Creamy Chicken & Sausage","Kolongko - The Disgrace","Simple Er Modhe Gorgeous (SMG)","Choco Fudge","Velvety Red","Oreo & Cheese","Tiro-Miss-U","Coca-Cola","Pepsi","Mountain Dew","Water"};
    printf("\n\nYour Bill:\n\n\n\t\tItem(s)\t\t\t\t     Quantity\t\t\t Cost\n\n\n\n");

    for(i=0;i<counter;i++)
    {
        printf("\t%2d. %-30s ________\t%-5d piece(s) ____ %7d\n",i+1,items[arID[i]-1],arqty[i],arqty[i]*costs[arID[i]-1]);
        sum=sum+(costs[arID[i]-1]*arqty[i]);
    }

    printf("\n\n\n\n\t\t\t\t\t\t\t  Total = %d\n\n\n\n",sum);
    token ++;
    tokens[token]=sum;
    printf("\tYour token number is %d. Use this token while paying the bill.\n\n\n\n\n\t\t\t",token);
    //printf("<enter (1) to give another order>\n\n\t\t\t<enter (2) to go to the main menu>");
   // printf("\n\t\n\t\t\t<enter (3) to win some discount>");
    printf("\n\n");
    printf("\t\t\t                        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $    Select any of them -          $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $    1. to give another order.     $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $    2. to go to the main menu.    $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $    3. to win some discount.      $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $                                  $\n");
    printf("\t\t\t                        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");


    do{
        printf("\n\n\t\n\t\t\tEnter your choice: ");
        scanf("%d",&n);
        if(n != 1 && n != 2 && n != 3)
        {
            printf("\n -----------------------You Entered Wrong Number------------------------\n  ------------------------Enter Correct Number------------------------\n");

        }
    }while(n != 1 && n != 2 && n != 3);


    if(n==1)
    {
        menu_order();
    }
    else if(n==2)
    {
        main();
    }
    else if(n == 3)
    {
        discount();
        printf("\n\n\t\n\t\t\tPay your bill from main menu.");
        getch();
        main();
    }

}

int discount()
{
    cenaceDiscount = 0; //0 = false, 1 = true
    flappyBirdDiscount = 0;
    numberGuessDiscount = 0;
    rockPaperScissorsDiscount = 0;

    int choice;

    //Category 1
    system("cls");
    printf("\n\n\tCategory 1: Play this game to get discount: 10%c",'%');

    printf("\n\n\t\t1. Play Tic Tac Toe with CENACE");
    //printf("\n\n\t\t2. Play Flappy Bird");

    do{
        printf("\n\n\t\tEnter your choice: ");
        scanf("%d", &choice);

    }while(choice != 1/* && choice != 2*/);


    if(choice == 1)//Play Tic Tac Toe with CENACE
    {
        system("cls");
        printf("\n\n\t\tPlay at least 5 matches to win discount");
        printf("\n\t\tPress any key to continue");
        getch();
        system("cls");
        Sleep(250);
        CENACE();
        if(match > 5) extraGameCharge[token] += (match - 5);

        if(match >= 5 && (humanScore > CENACEscore))
        {
            printf("\n\tCongratulations! You have got 10%c discount.\n",'%');
            getch();
            cenaceDiscount = 1;
            discountToken[token] += 10;

        }
        else
        {
            printf("\n\tBetter luck next time :)");
            getch();
            system("cls");
        }
    }

    // else if(choice == 2)
    // {
    //     system("cls");
    //     printf("\n\n\t\tPlay at least 5 matches to win discount");
    //     printf("\n\t\tPress any key to continue");
    //     getch();
    //     system("cls");
    //     Sleep(250);
    //     //flappyBird();
    //     if(1)//score > 10
    //     {
    //         printf("\n\tCongratulations! You have got 10%c discount.\n",'%');
    //         getch();
    //         flappyBirdDiscount = 1;
    //     }
    //     else
    //     {
    //         printf("\n\tBetter luck next time :)");
    //         getch();
    //         system("cls");
    //     }
    // }

    //Category 2
    system("cls");
    printf("\n\n\tCategory 2: Play any one of these games to get discount: 5%c",'%');

    printf("\n\n\t\t1. Play Number Guess");
    printf("\n\n\t\t2. Play Rock paper scissors");

    do{
        printf("\n\n\t\tEnter your choice: ");
        scanf("%d", &choice);

    }while(choice != 1 && choice != 2);


    if(choice == 1)// Play Number Guess
    {
        system("cls");
        printf("\n\n\t\tGuess the number to win discount");
        printf("\n\t\tPress any key to continue");
        getch();
        system("cls");
        Sleep(250);
        number_guess();
        if(number_guess_game_score > 0)
        {
            printf("\n\tCongratulations! You have got 5%c discount.\n",'%');
            getch();
            numberGuessDiscount = 1;
            discountToken[token] += 5;
        }
        else
        {
            printf("\n\tBetter luck next time :)");
            getch();
            system("cls");
        }
    }

    else if(choice == 2)// Play Rock paper scissors
    {
        system("cls");
        printf("\n\n\t\tScore at least 5 to win discount");
        printf("\n\t\tPress any key to continue");
        getch();
        system("cls");
        Sleep(250);
        rock_paper_scissors();
        if(rpsMatch > 5) extraGameCharge[token] += (rpsMatch - 5);
        if(score >= 5)
        {
            printf("\n\tCongratulations! You have got 5%c discount.\n",'%');
            getch();
            rockPaperScissorsDiscount = 1;
            discountToken[token] += 5;
        }
        else
        {

            printf("\n\tBetter luck next time :)");
            getch();
            system("cls");
        }
    }
}


void Bill_Payment()
{

    int k,i,cash,changer,n;
    redo:
    system("cls");
    system("color 3F");
    printf("\n\n\n\t\t\tEnter your token number: ");
    scanf("%d",&k);
    printf("\n\t\t\tYour bill is = %d",tokens[k]);
    if(tokens[k]) payment_counter++;

    if(extraGameCharge[k])
    {
        tokens[k] += extraGameCharge[k];
        printf("\n\t\t\tExtra game charge = %d",extraGameCharge[k]);
        printf("\n\t\t\tTotal bill = %d",tokens[k]);
    }
    //calculating distount
    if(discountToken[k])
    {
        tokens[k] -= (int)((float)(tokens[k] * discountToken[k])/100 + 0.5);
        printf("\n\t\t\tTotal discount = %d%c",discountToken[k], '%');
        printf("\n\t\t\tAfter discount = %d", tokens[k]);
    }

    work:
            printf("\n\t\t\tPay your bill: ");
            scanf("%d",&cash);
    changer = cash-tokens[k];
    if(changer == 0)
    {
        printf("\n\t\tThanks for your payment. Have a great day!\n");
    }
    else if (changer<0)
    {
        system("cls");
        printf("\n\t\t\tAmount is not sufficient. :(\n\t\tPlease pay the fair price of your bill\n");
        goto work;
    }
    else
    {
        printf("\n\n\n\t\tHere is your change : (%d - %d) = %d Tk.\n\t\t  ",cash,tokens[k],changer);

            for(i=0;i<19;i++)
            {
                printf("_");
            }
            if(changer>=1000 )
                {printf("\n\t\t1000 Tk. note(s) = %d\n",changer/1000);
                changer=changer%1000;}
            if(changer>=500 && changer<1000)
            {printf("\n\t\t 500 Tk. note(s) = %d\n",changer/500);
            changer=changer%500;}
            if(changer>=100 && changer<500)
            {printf("\n\t\t 100 Tk. note(s) = %d\n",changer/100);
            changer= changer%100;}
            if(changer>=50 && changer<100)
            {printf("\n\t\t  50 Tk. note(s) = %d\n",changer/50);
            changer=changer%50;}
             if(changer>=10 && changer<50)
            {printf("\n\t\t  10 Tk. note(s) = %d\n",changer/10);
            changer=changer%10;}
            if(changer>=5 && changer<10)
            {printf("\n\t\t   5 Tk. note(s) = %d\n",changer/5);
            changer=changer%5;}
            if(changer>=2 && changer<5)
            {printf("\n\t\t   2 Tk. note(s) = %d\n",changer/2);
            changer=changer%2;}
            if(changer>=1 && changer<2)
            {printf("\n\t\t   1 Tk. note(s) = %d\n",changer/1);
            changer=changer%1;}

            printf("\t\t  ");
            for(i=0;i<19;i++)
            {
                printf("_");
            }

        printf("\n\n\n\n\n\t\t\tThanks for your payment.\n\t\t\t    Have a great day!\n");


        tokens[k] = 0;

    }

    tokens[k] = 0;
    if(discountToken[k])
    {
        cenaceDiscount = 0; //0 = false, 1 = true
        flappyBirdDiscount = 0;
        numberGuessDiscount = 0;
        rockPaperScissorsDiscount = 0;
        discountToken[k] = 0;

    }
    if(extraGameCharge[k])
    {
        extraGameCharge[k] = 0;
    }

    printf("\n\n\t\t\t<Enter (1) to pay another bill.>\n\t\t\t<Enter (2) to go back main menu>\n\n\n\t\t\tEnter your choice: \t");
        scanf("%d",&n);
        if(n==2)
        {
            main();
        }
        else if(n==1)
        {
           goto redo;
        }
}



//CENACE source code starts here
int CENACE()
{
    auto_train_count = 0;
    O_move_count = 0;
    match = 1;
    CENACEscore = 0;
    humanScore = 0;

    system("title CENACE");
    system("COLOR 0B");
    system("cls");
    CENACE_intro();
    menu();
    if(exit_CENACE)
    {
        system("cls");
        Sleep(250);
        return 0;
    }
    system("mkdir Learning_data");
    system("mkdir Graphing_data");

    start:
    auto_train_count = 0;
    O_move_count = 0;
//    match = 1;
//    CENACEscore = 0;
//    humanScore = 0;

    while(1)
    {
        player = 1;
        newboard();
        choose_player();
        do
        {
            if(player % 2)
            {
                player = 1;
                mark = 'O';
            }
            else
            {
                player = 2;
                mark = 'X';
            }
            system("cls");
            printboard();
            inputmove();

            if(move == '1' && gameboard[0] == ' ')
            {
                gameboard[0] = mark;
            }
            else if(move == '2' && gameboard[1] == ' ')
            {
                gameboard[1] = mark;
            }
            else if(move == '3' && gameboard[2] == ' ')
            {
                gameboard[2] = mark;
            }
            else if(move == '4' && gameboard[3] == ' ')
            {
                gameboard[3] = mark;
            }
            else if(move == '5' && gameboard[4] == ' ')
            {
                gameboard[4] = mark;
            }
            else if(move == '6' && gameboard[5] == ' ')
            {
                gameboard[5] = mark;
            }
            else if(move == '7' && gameboard[6] == ' ')
            {
                gameboard[6] = mark;
            }
            else if(move == '8' && gameboard[7] == ' ')
            {
                gameboard[7] = mark;
            }
            else if(move == '9' && gameboard[8] == ' ')
            {
                gameboard[8] = mark;
            }
            else
            {
                printf("\n\tINVALID MOVE!");
                Beep(800, 500);
                fflush(stdin);
                player --;
            }

            win = checkwin();
            if(win == 1)
            {
                scoreUpdate();
                system("cls");
                printboard();
                if(player == 1)
                {
                    printf("\n\n\t>> Player-O won! <<");
                    if(auto_train != 'y' && auto_train != 'Y')
                    {
                        Beep(500,300);
                        Beep(500,300);
                        Beep(700,500);
                    }
                }
                else
                {
                    printf("\n\n\t>> Player-X won! <<");
                    if(auto_train != 'y' && auto_train != 'Y')
                    {
                        Beep(700,300);
                        Beep(700,300);
                        Beep(500,500);
                    }
                }

                updateLearning_data();
                updateGraphing_data();
            }
            else if(win == -1)
            {
                scoreUpdate();
                system("cls");
                printboard();
                printf("\n\n\t>> Draw! <<");
                if(auto_train != 'y' && auto_train != 'Y')
                {
                    Beep(400,250);
                    Beep(500,250);
                }

                updateLearning_data();
                updateGraphing_data();
            }

            player ++;

        }while(win == 0);

        //Printing all paths
        printf("\nFile paths: ");
        for(int i = 0; i < O_move_count; i++)
        {
            printf("\n   %s", O_paths[i]);
        }

        //Asking user if he/she wants to play again
        if(auto_train != 'y' && auto_train != 'Y')
        {
            char ask;
            if(match == 5)
            {
                printf("\n\n\tYou have already played 5 matches.\n\tIf you play more taka 1 will be added to your bill per match.");
                Beep(500,500);
                getch();
            }
            printf("\n\n\tPlay again? (y/n) --> ");
            while(1)
            {
                ask = getch();
                printf("%c",ask);
                if(ask == 'y' || ask == 'Y')
                {
                    O_move_count = 0;
                    break;
                }
                else if(ask == 'n' || ask == 'N')
                {
                    system("cls");
                    O_move_count = 0;
                    menu();
                    if(exit_CENACE)
                    {
                        system("cls");
                        Sleep(250);
                        return 0;
                    }
                    else goto start;
                }
                else if(ask == 8)
                {
                    printf(" \a");
                }
                else if(ask == 13)
                {
                    printf("\t                      ");
                    printf("\n\n\tPlay again? (y/n) --> ");
                }
                else
                {
                    printf("\b \b\a");
                }
            }
        }

        if(auto_train == 'y' || auto_train == 'Y')
        {
            auto_train_count ++;
            O_move_count = 0;
            if(auto_train_count == total_training_match)
            {
                printf("\n\n\tTraining complete.");
                printf("\n\tPress any key to continue. ");
                getch();
                auto_train = 'n';
                system("cls");
                menu();
                if(exit_CENACE)
                {
                    system("cls");
                    Sleep(250);
                    return 0;
                }
                else goto start;
            }
        }
        match ++;
    }
}

void choose_player()
{
    player_O = '2'; //2 = Computer(CENACE)
    player_X = '1'; //1 = Human


    // while(1)
    // {
    //     printf("\n\n\tChoose Player-X: 1. Human");
    //     printf("\n\t                 2. Computer");
    //     printf("\n\n\t==> ");
    //     player_X = getch();
    //     printf("%c", player_X);
    //     if(player_X != '1' && player_X != '2')
    //     {
    //         printf("\n\tINVALID OPTION!\n");
    //         continue;
    //     }
    //     break;
    // }

    // while(1)
    // {
    //     printf("\n\n\tChoose Player-O: 1. Human");
    //     printf("\n\t                 2. Computer");
    //     printf("\n\n\t==> ");
    //     player_O = getch();
    //     printf("%c", player_O);
    //     if(player_O != '1' && player_O != '2')
    //     {
    //         printf("\n\tINVALID OPTION!\n");
    //         continue;
    //     }
    //     break;
    // }

}

void inputmove()
{
    //Input from human or auto input move while in auto train
    if(player == 2)
    {
        if(auto_train != 'y' && auto_train != 'Y')
        {
            printf("\n\n\tEnter your move (1-9): ");
            move = getch();
        }

        else
        {
            char anti_mark;
            if(mark == 'X') anti_mark = 'O';
            else anti_mark = 'X';

            if     (gameboard[0] == mark && gameboard[1] == mark && gameboard[2] == ' ') move = '3';
            else if(gameboard[1] == mark && gameboard[2] == mark && gameboard[0] == ' ') move = '1';
            else if(gameboard[0] == mark && gameboard[2] == mark && gameboard[1] == ' ') move = '2';

            else if(gameboard[3] == mark && gameboard[4] == mark && gameboard[5] == ' ') move = '6';
            else if(gameboard[4] == mark && gameboard[5] == mark && gameboard[3] == ' ') move = '4';
            else if(gameboard[3] == mark && gameboard[5] == mark && gameboard[4] == ' ') move = '5';

            else if(gameboard[6] == mark && gameboard[7] == mark && gameboard[8] == ' ') move = '9';
            else if(gameboard[7] == mark && gameboard[8] == mark && gameboard[6] == ' ') move = '7';
            else if(gameboard[6] == mark && gameboard[8] == mark && gameboard[7] == ' ') move = '8';

            else if(gameboard[0] == mark && gameboard[3] == mark && gameboard[6] == ' ') move = '7';
            else if(gameboard[3] == mark && gameboard[7] == mark && gameboard[0] == ' ') move = '1';
            else if(gameboard[0] == mark && gameboard[6] == mark && gameboard[3] == ' ') move = '4';

            else if(gameboard[1] == mark && gameboard[4] == mark && gameboard[7] == ' ') move = '8';
            else if(gameboard[4] == mark && gameboard[7] == mark && gameboard[1] == ' ') move = '2';
            else if(gameboard[1] == mark && gameboard[7] == mark && gameboard[4] == ' ') move = '5';

            else if(gameboard[2] == mark && gameboard[5] == mark && gameboard[8] == ' ') move = '9';
            else if(gameboard[5] == mark && gameboard[8] == mark && gameboard[2] == ' ') move = '3';
            else if(gameboard[2] == mark && gameboard[8] == mark && gameboard[5] == ' ') move = '6';

            else if(gameboard[0] == mark && gameboard[4] == mark && gameboard[8] == ' ') move = '9';
            else if(gameboard[4] == mark && gameboard[8] == mark && gameboard[0] == ' ') move = '1';
            else if(gameboard[0] == mark && gameboard[8] == mark && gameboard[4] == ' ') move = '5';

            else if(gameboard[2] == mark && gameboard[4] == mark && gameboard[6] == ' ') move = '7';
            else if(gameboard[4] == mark && gameboard[6] == mark && gameboard[2] == ' ') move = '3';
            else if(gameboard[2] == mark && gameboard[6] == mark && gameboard[4] == ' ') move = '5';


            else if(gameboard[0] == anti_mark && gameboard[1] == anti_mark && gameboard[2] == ' ') move = '3';
            else if(gameboard[1] == anti_mark && gameboard[2] == anti_mark && gameboard[0] == ' ') move = '1';
            else if(gameboard[0] == anti_mark && gameboard[2] == anti_mark && gameboard[1] == ' ') move = '2';

            else if(gameboard[3] == anti_mark && gameboard[4] == anti_mark && gameboard[5] == ' ') move = '6';
            else if(gameboard[4] == anti_mark && gameboard[5] == anti_mark && gameboard[3] == ' ') move = '4';
            else if(gameboard[3] == anti_mark && gameboard[5] == anti_mark && gameboard[4] == ' ') move = '5';

            else if(gameboard[6] == anti_mark && gameboard[7] == anti_mark && gameboard[8] == ' ') move = '9';
            else if(gameboard[7] == anti_mark && gameboard[8] == anti_mark && gameboard[6] == ' ') move = '7';
            else if(gameboard[6] == anti_mark && gameboard[8] == anti_mark && gameboard[7] == ' ') move = '8';

            else if(gameboard[0] == anti_mark && gameboard[3] == anti_mark && gameboard[6] == ' ') move = '7';
            else if(gameboard[3] == anti_mark && gameboard[7] == anti_mark && gameboard[0] == ' ') move = '1';
            else if(gameboard[0] == anti_mark && gameboard[6] == anti_mark && gameboard[3] == ' ') move = '4';

            else if(gameboard[1] == anti_mark && gameboard[4] == anti_mark && gameboard[7] == ' ') move = '8';
            else if(gameboard[4] == anti_mark && gameboard[7] == anti_mark && gameboard[1] == ' ') move = '2';
            else if(gameboard[1] == anti_mark && gameboard[7] == anti_mark && gameboard[4] == ' ') move = '5';

            else if(gameboard[2] == anti_mark && gameboard[5] == anti_mark && gameboard[8] == ' ') move = '9';
            else if(gameboard[5] == anti_mark && gameboard[8] == anti_mark && gameboard[2] == ' ') move = '3';
            else if(gameboard[2] == anti_mark && gameboard[8] == anti_mark && gameboard[5] == ' ') move = '6';

            else if(gameboard[0] == anti_mark && gameboard[4] == anti_mark && gameboard[8] == ' ') move = '9';
            else if(gameboard[4] == anti_mark && gameboard[8] == anti_mark && gameboard[0] == ' ') move = '1';
            else if(gameboard[0] == anti_mark && gameboard[8] == anti_mark && gameboard[4] == ' ') move = '5';

            else if(gameboard[2] == anti_mark && gameboard[4] == anti_mark && gameboard[6] == ' ') move = '7';
            else if(gameboard[4] == anti_mark && gameboard[6] == anti_mark && gameboard[2] == ' ') move = '3';
            else if(gameboard[2] == anti_mark && gameboard[6] == anti_mark && gameboard[4] == ' ') move = '5';

            else
            {
                while(1)
                {
                    //Note that: 1. 'move' is a char.
                    //           2. adding 48 converts an int into a char.
                    move = (char)((rand() % 10) + 48 + 1);
                    if(gameboard[(int)(move - 48) - 1] == ' ')//Accepting computer's input only if there is a blank space
                    {
                        gameboard[9] = '\0';
                        break;
                    }
                    else continue;
                }
            }
        }
    }

    //Input from computer
    else
    {
        FILE* file;
        int  i, j = 0, k;
        char current_board[10], cmd[50] = "md Learning_data\\";

        char path[50] = "Learning_data\\";
        char temp[2] = "i";
        char point[4]; //This is a string to store the point read from file
        int  point_list[space_in_board()];
        int  point_pose[space_in_board()];
        int  sum_of_available_move_point = 0;



        //Creating folder inside learning data starts here

        for(i = 0; i <= 8; i ++)
        {
            if(gameboard[i] == ' ')
            {
                current_board[i] = '-';
            }
            else
            {
                current_board[i] = gameboard[i];
            }
        }
        current_board[9] = '\0';//end of string

        strcat(cmd, current_board);
        system(cmd);
        //Creating folder inside learning data ends here

        //Creating the .txt files inside "Learning_data\<FOLDER NAME>\...." starts here
        for(i = 0; i < space_in_board(); i ++)
        {
            point_list[i] = 0;
            point_pose[i] = 0;
        }

        for(i = 0; i < 9; i ++)
        {
            if(gameboard[i] == ' ')
            {
                strcat(path, current_board);
                strcat(path, "\\");
                temp[0] = (char)(i + 1 + 48);
                strcat(path, temp);
                strcat(path, ".txt");
                file = fopen(path, "r");
                    if(file == NULL)//If file doesn't exist then creat file
                    {
                        file = fopen(path, "w");
                        fprintf(file, INITIAL_POINT);
                        fclose(file);

                        file = fopen(path, "r");
                        fgets(point, 4, file);
                        sum_of_available_move_point += atoi(point);
                        point_list[j] = atoi(point);
                        fclose(file);
                    }
                    else
                    {
                        fgets(point, 4, file);
                        sum_of_available_move_point += atoi(point);
                        point_list[j] = atoi(point);
                        fclose(file);
                    }
                    point_pose[j] = i;
                    j ++;
                if(i < 8) strcpy(path, "Learning_data\\");
            }
        }
        //Creating the .txt files inside "Learning_data\<FOLDER NAME>\...." ends here

        //Taking input from learning data
        int move_priority[sum_of_available_move_point];

        for(i = 0, j = 0; i < space_in_board(); i ++)
        {
            for(k = 0; k < point_list[i]; k ++)
            {
                move_priority[j] = point_pose[i] + 1;
                j ++;
            }
        }

        printf("\n\n\tEnter your move (1-9): ");
        srand(time(NULL));

        while(1)
        {
            //Note that: 1. 'move' is a char.
            //           2. adding 48 converts an int into a char.
            int move_pose = (rand() % sum_of_available_move_point);
            move = (char)(move_priority[move_pose] + 48);
            if(gameboard[(int)(move - 48) - 1] == ' ')//Accepting computer's input only if there is a blank space
            {
                gameboard[9] = '\0';
                break;
            }
            else continue;
        }
        printf("%c", move);

        //final current-path for given move
        char name_of_txt_file [2] = {move, '\0'};
        strcpy(path, "Learning_data\\");
        strcat(path, current_board);
        strcat(path, "\\");
        strcat(path, name_of_txt_file);
        strcat(path, ".txt");

        strcpy(O_paths[O_move_count], path);
        O_move_count ++;
    }
}

void newboard()
{
    int i;
    gameboard[9] = '\0';
    for(i = 0; i < 9; i ++)
    {
        gameboard[i] = ' ';
    }
}

void printboard()
{
    //printf("\n\t\t 1|2|3");
    //printf("\n\t\t 4|5|6");
    //printf("\n\t\t 7|8|9\n");
    if(auto_train == 'y' || auto_train == 'Y')
    {
        printf("\n\t      Match:%4d", match);
        printf("\n      ___________________________");
        printf("\n     |              /            |");
        printf("\n     | CENACE:%4d vs HUMAN:%4d |", CENACEscore, humanScore);
        printf("\n     |_____________/_____________|");
    }

    else
    {
        printf("\n\t      Match:%4d", match);
        printf("\n      ___________________________");
        printf("\n     |              /            |");
        printf("\n     | CENACE:%4d vs HUMAN:%4d |", CENACEscore, humanScore);
        printf("\n     |_____________/_____________|");
    }

    if(player == 1)
    {
        printf("\n\n\t  Player-O, your turn\n");
    }
    else
    {
        printf("\n\n\t  Player-X, your turn\n");
    }

    printf("\n\t       |       |       ");
    printf("\n\t   %c   |   %c   |   %c   ", gameboard[0], gameboard[1], gameboard[2]);
    printf("\n\t_______|_______|_______");
    printf("\n\t       |       |       ");
    printf("\n\t   %c   |   %c   |   %c   ", gameboard[3], gameboard[4], gameboard[5]);
    printf("\n\t_______|_______|_______");
    printf("\n\t       |       |       ");
    printf("\n\t   %c   |   %c   |   %c   ", gameboard[6], gameboard[7], gameboard[8]);
    printf("\n\t       |       |       \n");
}

int checkwin() //1 = win, -1 = draw
{
    if     (gameboard[0] == 'X' && gameboard[1] == 'X' && gameboard[2] == 'X') return 1;
    else if(gameboard[3] == 'X' && gameboard[4] == 'X' && gameboard[5] == 'X') return 1;
    else if(gameboard[6] == 'X' && gameboard[7] == 'X' && gameboard[8] == 'X') return 1;
    else if(gameboard[0] == 'X' && gameboard[3] == 'X' && gameboard[6] == 'X') return 1;
    else if(gameboard[1] == 'X' && gameboard[4] == 'X' && gameboard[7] == 'X') return 1;
    else if(gameboard[2] == 'X' && gameboard[5] == 'X' && gameboard[8] == 'X') return 1;
    else if(gameboard[0] == 'X' && gameboard[4] == 'X' && gameboard[8] == 'X') return 1;
    else if(gameboard[2] == 'X' && gameboard[4] == 'X' && gameboard[6] == 'X') return 1;

    else if(gameboard[0] == 'O' && gameboard[1] == 'O' && gameboard[2] == 'O') return 1;
    else if(gameboard[3] == 'O' && gameboard[4] == 'O' && gameboard[5] == 'O') return 1;
    else if(gameboard[6] == 'O' && gameboard[7] == 'O' && gameboard[8] == 'O') return 1;
    else if(gameboard[0] == 'O' && gameboard[3] == 'O' && gameboard[6] == 'O') return 1;
    else if(gameboard[1] == 'O' && gameboard[4] == 'O' && gameboard[7] == 'O') return 1;
    else if(gameboard[2] == 'O' && gameboard[5] == 'O' && gameboard[8] == 'O') return 1;
    else if(gameboard[0] == 'O' && gameboard[4] == 'O' && gameboard[8] == 'O') return 1;
    else if(gameboard[2] == 'O' && gameboard[4] == 'O' && gameboard[6] == 'O') return 1;

    else if(gameboard[0] != ' ' && gameboard[1] != ' ' && gameboard[2] != ' ' && gameboard[3] != ' ' && gameboard[4] != ' ' && gameboard[5] != ' ' && gameboard[6] != ' ' && gameboard[7] != ' ' && gameboard[8] != ' ')
        return -1;

    else return 0;
}

int space_in_board()
{
    int i, spc = 0;
    for(i = 0; i < 9; i ++)
    {
        if(gameboard[i] == ' ') spc++;
    }
    return spc;
}

void updateLearning_data()
{
    FILE* file;
    int i;
    char point[4];
    int intpoint;

    for(i = 0; i < O_move_count; i ++)
    {
        file = fopen(O_paths[i], "r");
        fgets(point, 4, file);
        intpoint = atoi(point);
        fclose(file);

        if(win == 1 && player == 1) intpoint += WIN_REWORD; //player 1 = CENACE
        else if(win == -1) intpoint += DRAW_REWORD;
        else intpoint -= PUNISHMENT;

        if(intpoint >= MAX_POINT) intpoint = MAX_POINT;
        else if(intpoint <= MIN_POINT) intpoint = MIN_POINT;

        sprintf(point, "%d", intpoint);

        file = fopen(O_paths[i], "w");
        fprintf(file, point);
        fclose(file);
    }

}

void menu()
{
    menu:
    exit_CENACE = 0;

    printf("\n\n\t1. Auto Train CENACE");
    printf("\n\t2. Play");
    printf("\n\t3. Rules");
    printf("\n\t4. About");
    printf("\n\t5. Exit");
    printf("\n\n\t--> ");

    char choice = getch();
    printf("%c", choice);

    switch (choice)
    {
        case '1':
        system("cls");

        printf("\n\tTraining may take some time.");
        printf("\n\tDo not exit the program during training.");
        printf("\n\tContinue? (y/n) --> ");

        auto_train = getch();
        printf("%c", auto_train);

        if(auto_train == 'y' || auto_train == 'Y')
        {
            printf("\n\tMatches to be played --> ");
            scanf("%d", &total_training_match);
            fflush(stdin);
        }
        else
        {
            system("cls");
            goto menu;
        }
        return;
        break;

        case '2':
        return;
        break;

        case '3':
        system("cls");
        printf("\n\tRULES:");
        printf("\n\t1. CENACE will always go first.");
        printf("\n\t2. Move positions are from 1 to 9 on the game board.\n");
        printf("\n\t\t       |       |       ");
        printf("\n\t\t   1   |   2   |   3   ");
        printf("\n\t\t_______|_______|_______");
        printf("\n\t\t       |       |       ");
        printf("\n\t\t   4   |   5   |   6   ");
        printf("\n\t\t_______|_______|_______");
        printf("\n\t\t       |       |       ");
        printf("\n\t\t   7   |   8   |   9   ");
        printf("\n\t\t       |       |       \n");
        printf("\n\t3. +3 for win, +1 for draw, -1 for lose.");

        getch();
        system("cls");
        goto menu;
        break;

        case '4':
        system("cls");
        printf("\n     _______________________________________________________");
        printf("\n    |                                                       |");
        printf("\n    | Computer Educable Noughts and Crosses Engine (CENACE) |");
        printf("\n    |_______________________________________________________|\n");

        printf("\n\tAuthor: Aaban Saad Preyanta");
        printf("\n\tNSU ID: 2233389642");
        printf("\n\tBachelor of Computer Science and Engineering");
        printf("\n\tDepartment of Electrical and Computer Engineering");
        printf("\n\tNorth South University, Dhaka, Bangladesh\n");

        printf("\n\tThe name CENACE originated from the 1961 MENACE reinforcement learning model by Donald Michie. ");
        printf("\n\tI have programmed CENACE as a computer simulation of Michie's MENACE. ");
        printf("\n\tInstead of matchboxes, CENACE uses folders and text files to keep track of its moves.\n");
        printf("\n  ____________________________________________________________________________________________________\n\n");

        printf("\n\tMENACE: The Matchbox Educable Noughts and Crosses Engine was a ");
        printf("\n\tmechanical computer made from 304 matchboxes designed and built by ");
        printf("\n\tartificial intelligence researcher Donald Michie in 1961. ");
        printf("\n\tIt was designed to play human opponents in games of noughts and crosses (tic-tac-toe) ");
        printf("\n\tby returning a move for any given state of play ");
        printf("\n\tand to refine its strategy through reinforcement learning. (Wikipedia)");


        getch();
        system("cls");
        goto menu;
        break;

        case '5':
        exit_CENACE = 1;
        return;
        break;

        default:
        getch();
        system("cls");
        goto menu;
        break;

    }
}

void CENACE_intro()
{
    system("cls");
    printf("\n\t%c%c%c      %c%c%c   %c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n\t%c%c%c      %c%c%c   %c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n\t%c%c%c      %c%c%c", 219, 219, 219, 219, 219, 219);
    printf("\n\t%c%c%c      %c%c%c   %c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n\t%c%c%c      %c%c%c   %c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n\t%c%c%c      %c%c%c   %c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n\t%c%c%c      %c%c%c   %c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n\t%c%c%c      %c%c%c   %c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    Sleep(1500);
    system("cls");

    printf("\n\t%c%c%c", 219, 219, 219);
    printf("\n\t%c%c%c  %c%c", 219, 219, 219, 219, 219);
    printf("\n\t%c%c%c   %c", 219, 219, 219, 219);
    printf("\n\t%c%c%c      %c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c",219);
    printf("\n\t%c%c%c      %c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c",219);
    printf("\n\t%c%c%c      %c%c%c  %c%c%c  %c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n\t%c%c%c      %c%c%c  %c%c%c  %c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n\t%c%c%c      %c%c%c  %c%c%c  %c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n\t%c%c%c      %c%c%c  %c%c%c  %c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n\t%c%c%c      %c%c%c  %c%c%c  %c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219, 219);

    Sleep(1000);
    system("cls");

    printf("\n\t%c%c%c%c%c%c%c  %c%c%c%c%c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c   %c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("\n\t%c%c       %c%c       ", 219, 219, 219, 219);
    printf("%c%c   %c%c   %c%c", 219, 219, 219, 219, 219, 219);

    printf("\n\t%c%c       %c%c       ", 219, 219, 219, 219);
    printf("%c%c   %c%c   %c%c", 219, 219, 219, 219, 219, 219);

    printf("\n\t%c%c       %c%c%c%c%c%c%c  ", 219, 219, 219, 219);
    printf("%c%c   %c%c   %c%c", 219, 219, 219, 219, 219, 219);

    printf("\n\t%c%c       %c%c       ", 219, 219, 219, 219);
    printf("%c%c   %c%c   %c%c", 219, 219, 219, 219, 219, 219);

    printf("\n\t%c%c       %c%c       ", 219, 219, 219, 219);
    printf("%c%c   %c%c   %c%c", 219, 219, 219, 219, 219, 219);

    printf("\n\t%c%c%c%c%c%c%c  %c%c%c%c%c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c   %c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("\n");

    printf("\n\t%c%c%c%c%c%c%c%c%c%c   ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c   %c%c%c%c%c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("\n\t%c%c      %c%c   ", 219, 219, 219, 219);
    printf("%c%c        %c%c       ", 219, 219, 219, 219);

    printf("\n\t%c%c      %c%c   ", 219, 219, 219, 219);
    printf("%c%c        %c%c       ", 219, 219, 219, 219);

    printf("\n\t%c%c%c%c%c%c%c%c%c%c   ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c        %c%c%c%c%c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("\n\t%c%c      %c%c   ", 219, 219, 219, 219);
    printf("%c%c        %c%c       ", 219, 219, 219, 219);

    printf("\n\t%c%c      %c%c   ", 219, 219, 219, 219);
    printf("%c%c        %c%c       ", 219, 219, 219, 219);

    printf("\n\t%c%c      %c%c   ", 219, 219, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c   %c%c%c%c%c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);


    Sleep(1000);
    printf("\n\n\tLoading CENACE %c     0%c", 196, 37);
    int i;
    for(i = 0; i < 100; i += 12)
    {
        Sleep(100);
        printf("\b\b\b\b\b\b\b\b\\    %2d%c", i, 37);
        Sleep(100);
        printf("\b\b\b\b\b\b\b\b/    %2d%c",i + 2, 37);
        Sleep(100);
        printf("\b\b\b\b\b\b\b\b%c    %2d%c", 196, i + 3, 37);
    }
    Sleep(500);
    system("cls");
    Sleep(1000);
}

void updateGraphing_data()
{
    FILE *file_lastScore, *file_scoreList;
    char path1[] = "Graphing_data\\Last_Score.txt";
    char path2[] = "Graphing_data\\Score_List.txt";
    char score[100];
    int  intscore;

    file_lastScore = fopen(path1, "r");
    if(file_lastScore == NULL)
    {
        file_lastScore = fopen(path1, "w");
        fprintf(file_lastScore, 0);
        fclose(file_lastScore);
    }
    fgets(score, 20, file_lastScore);
    intscore = atoi(score);
    fclose(file_lastScore);

    if(win == 1 && player == 1) intscore += WIN_REWORD;
    else if(win == -1) intscore += DRAW_REWORD;
    else intscore -= PUNISHMENT;

    sprintf(score, "%d", intscore);

    file_lastScore = fopen(path1, "w");
    fprintf(file_lastScore, score);
    fclose(file_lastScore);

    file_scoreList = fopen(path2, "a");
    fprintf(file_scoreList, strcat(score, "\n"));
    fclose(file_scoreList);
}

void scoreUpdate()
{
    if(win == 1 && player == 1)
    {
        CENACEscore += WIN_REWORD;
        humanScore -= PUNISHMENT;
    }
    else if(win == 1 && player == 2)
    {
        humanScore += WIN_REWORD;
        CENACEscore -= PUNISHMENT;
    }
    else if(win == -1)
    {
        CENACEscore += DRAW_REWORD;
        humanScore += DRAW_REWORD;
    }
}
//CENACE source code ends here




//Number Guess code starts here
int number_guess()
{

        printf("\n\n");
        printf("\t\t                        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        printf("\t\t                        $                                  $\n");
        printf("\t\t                        $    Select any of them -          $\n");
        printf("\t\t                        $                                  $\n");
        printf("\t\t                        $    1.  PLAY GAME                 $\n");
        printf("\t\t                        $                                  $\n");
        printf("\t\t                        $                                  $\n");
        printf("\t\t                        $    2.  EXIT                      $\n");
        printf("\t\t                        $                                  $\n");
        printf("\t\t                        $                                  $\n");
        printf("\t\t                        $                                  $\n");
        printf("\t\t                        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        int a;
        scanf("%d",&a);
        system("cls");

        if(a==1)
        {
            load();
            number_guess_game();
        }
        else if(a==2)
        {
            return 0;

        }
        else
        {
        printf("\n -----------------------You Entered Wrong Number------------------------\n  ------------------------Enter Correct Number------------------------\n");
        }

    return 0;
}
void number_guess_game()
{
    number_guess_game_score=0;
    srand(time(NULL));      //seedig random number

    int number=rand() % 100 +1; // to get number beewtween 1 to 100

    printf("YOU WILL GET 5 TRIES TO GUESS\n\n");

    int guess=0,count=0;
    do
    {
        printf("Enter a guess From 1 to 100:");
        scanf("%d",&guess);

        if (guess == number)
        {    system("cls");
            printf("You got it!\n");
            printf("The number is %d\n",number);
            number_guess_game_score++;
            printf("Your score is :%d\n",number_guess_game_score);
            Sleep(1500);
            getch();
            break;
        }
        else if (guess < number)
        {
            printf("Guess higher!\n");
        }
        else
        {
                printf("Guess lower!\n");
        }

        count++;
        if(count==5)
        {
            system("cls");
            printf("Sorry You lose\nThe number was %d\n",number);
            printf("Your Score is :%d",number_guess_game_score);
            Sleep(1500);
            getch();
        }
    } while (count!=5);
    system("cls");
}
//Number Guess code ends here

//Rock paper scissors starts here
int rock_paper_scissors()
{
    score = 0;
    rpsMatch = 1;
    while(1)
    {
        printf("\n\n\t\t\t\t\tYou can play 5 times\n\n");
        printf("\n\n");
        printf("\t\t                        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        printf("\t\t                        $                                  $\n");
        printf("\t\t                        $    Select any of them -          $\n");
        printf("\t\t                        $                                  $\n");
        printf("\t\t                        $    1.  PLAY GAME                 $\n");
        printf("\t\t                        $                                  $\n");
        printf("\t\t                        $                                  $\n");
        printf("\t\t                        $    2.  EXIT                      $\n");
        printf("\t\t                        $                                  $\n");
        printf("\t\t                        $                                  $\n");
        printf("\t\t                        $                                  $\n");
        printf("\t\t                        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        int a;
        scanf("%d",&a);
        system("cls");

        if(rpsMatch == 5)
                printf("\n\n\tYou have already played 5 matches.\n\tIf you play more taka 1 will be added to your bill per match.");

        if(a==1)
        {
            rpsMatch ++;

            load();
            game();
        }
        else if(a==2)
        {
            return 0;
        }
        else
        {
        printf("\n -----------------------You Entered Wrong Number------------------------\n  ------------------------Enter Correct Number------------------------\n");
        }
    }


    return 0;
}
void game()
{
    int t=3;
    while(t--)
    {
    srand(time(NULL));                     //seeding to genarate random numbers with time
    int  n;
    int  player_throw = 0;
    char ch_player_throw;                 //to store the player given numbers
    int  ai_throw=0;                        //to store the ai given numbers
    bool draw=false;                       //it will check the game is draw or not

    do
    {
        printf("Select your throw\n");
        printf("1) ROCK\n");
        printf("2) PAPER\n");
        printf("3) SCISSORS\n");
        printf("SELECTION: ");
        while(1)
        {
            ch_player_throw = getch();          //to store player numbers
            player_throw = (int)(ch_player_throw - 48);

            if(player_throw != 1 && player_throw != 2 && player_throw != 3)
            {
                Beep(450, 250);
                continue;
            }
            else break;
        }
        printf("%c", ch_player_throw);
        getch();


        ai_throw = (rand() % 3) + 1;           //random number will give me 0 to infinity numbers so to get 1 2 3, It will mod that intezer and mod with 3 and it will give me 0,1,2 and to get 1,2,4 there is a plus 1

        if(ai_throw==ROCK)                     // TO LET THE PLAYER KNOW WHAT AI GIVEN THEM
        {
            printf("\n AI GIVES ROCK.\n");
        }
        else if(ai_throw==PAPER)
        {
            printf("\n AI GIVES PAPER.\n");
        }
        else if(ai_throw== SCISSORS)
        {
            printf("\n AI GIVES SCISSORS.\n");
        }

        draw =false;
        if (player_throw == ROCK && ai_throw == SCISSORS)
        {
             printf("\nROCK beats SCISSORS. YOU WIN.\n\n");
             score++;
        }

        else if (player_throw == ROCK && ai_throw == PAPER)
        {
              printf("\nPAPER beats ROCK. YOU LOSE.\n\n");
        }
       else if (player_throw == SCISSORS && ai_throw == PAPER)
        {
              printf("\nSCISSORS beats PAPER. YOU WIN.\n\n");
                score++;
        }
        else if (player_throw == SCISSORS && ai_throw == ROCK)
        {
              printf("\nROCK beats SCISSORS. YOU LOSE.\n\n");
        }
         else if (player_throw == PAPER && ai_throw == ROCK)
         {
              printf("\nPAPER beats ROCK. YOU WIN.\n\n");
               score++;
         }
         else if (player_throw == PAPER && ai_throw == SCISSORS)
         {
         printf("\nSCISSORS beats PAPER. YOU LOSE.\n\n");
         }
    else
    {
      printf("\nDRAW! Play again.\n\n");            // if both player and AI throw the same, it's a draw
      printf("YOUR SCORE IS :%d\n\n",score);
      draw = true;
    }

    } while (draw);                                  // the game will run as long as it is draw
    printf("YOUR SCORE IS :%d\n\n\n",score);
    }
    getch();
    system("cls");
}
//Rock paper scissors ends here

void load()
{
    int r,q;
    printf("\n\n\n\t\t\tloading...");
    for(r=1;r<=20;r++){
    for(q=0;q<=100000000;q++);   //to display the character slowly
    printf("%c",177);}
    system("cls");
}
