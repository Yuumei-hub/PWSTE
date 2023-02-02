#include <iostream>

int GenerateRandNumber() {

    int rand_num = rand() % 100;
    return rand_num;

}

int GuessNumberforPC(int x, int y){
    int guess=(int)((rand() % x) + y);
    return guess;
}

int main(){
    int rand_num;
    int numberx=-1;
    int guess = -1;
    char answer;
    int attempts=1;
    while (true) {
        Y1:
        rand_num = GenerateRandNumber();
        std::cout << "Guess the number " << std::endl;
        X1:
        std::cin >> guess;
        if(guess == rand_num)
        {
            std::cout << "Congrats! You've guessed the number correct. Do you want to play again? Y/N"<< std::endl ;
            std::cin>> answer;
            if (answer == 'Y')
                goto Y1;
            else
                break;
        }
        else if (guess > rand_num)
        {
            std::cout << "Your guess is bigger than the actual number. Try again" << std::endl;
            goto X1;
        }
        else if (guess < rand_num)
        {
            std::cout << "Your guess is smaller than the actual number. Try again" << std::endl;
            goto X1; 
        }
    }
    
    while(true){
            std::cout << "Pick a number between 1 and 100" << std::endl;
            std::cin >> numberx;
            guess=GenerateRandNumber();
            X2:
            if(guess==numberx){
                std::cout<<"The number you picked has been found in " << attempts << "times of attempt";
                break;
            }
            else if(guess>numberx){
                guess=GuessNumberforPC(guess,0);
                attempts+=1;
                goto X2;
            }
            else if(guess<numberx){
                guess=GuessNumberforPC(guess,100);
                attempts+=1;
                goto X2;
            }
            
    }
}
