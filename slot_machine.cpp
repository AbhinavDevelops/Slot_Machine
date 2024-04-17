#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<map>
#include<array>
#include<cstdlib>
#include<set>
#include<random>


enum class ValAgents {
    Jett,
    Reyna,
    Raze,
    Iso,
    Pheonix,
    Yoru
};

std::ostream& operator<<(std::ostream& os, const ValAgents& agent) {
    switch (agent) {
        case ValAgents::Jett: os << "Jett"; break;
        case ValAgents::Reyna: os << "Reyna"; break;
        case ValAgents::Raze: os << "Raze"; break;

        case ValAgents::Iso: os << "Iso"; break;

        case ValAgents::Pheonix: os << "Pheonix"; break;

        case ValAgents::Yoru: os << "Yoru"; break;
        // Add other agents here
    }
    return os;
}


std::map<int, ValAgents> AgentMap {{1,ValAgents::Jett},{2, ValAgents::Reyna},{3,ValAgents::Raze},{4,ValAgents::Pheonix},{5,ValAgents::Iso},{6,ValAgents::Yoru}};

// use a dictionary to make more intuitive on how the agents are selected

ValAgents agent_picker (){

    int user_number = 3;


    std::cout << "Pick your agent from Jett: 1, Reyna: 2, Raze:3, Iso:4, Pheonix:5, Yoru:6" << std::endl;

    std::cin >> user_number;


    ValAgents user_selection = AgentMap[user_number];

  //  std:: cout << "The agent the user selected:" << user_selection << std::endl;

    return user_selection;
}

std::array<int, 3> generate_reel() {
    std::array<int, 6> numbers = {1, 2, 3, 4, 5, 6};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(numbers.begin(), numbers.end(), gen);

    std::array<int, 3> reel;
    for (int i = 0; i < 3; ++i) {
        reel[i] = numbers[i];
      //  std::cout << "rand is " << reel[i] << std::endl;
    }

    return reel;
}

int calc_win_award(std::array<int,3> reel, int* bet, ValAgents user_selection){

    float moneyWon = -(*bet) ;

    float multiplier = 1;

    bool same = (reel[0] == reel[1] && reel[2]== reel[1]);

    for (int i = 0; i<3; ++i){
       if (AgentMap[reel[i]] == user_selection){

        multiplier = multiplier + 0.15;

        std:: cout << "you should have won and multiplier is " << multiplier << std::endl;

      //  std:: cout << AgentMap[reel[i]] << " " << user_selection << std::endl;
       }
    }

    if(same) multiplier *= 2;

    moneyWon = moneyWon*(-multiplier) - *bet;

   // std::cout << "multiplier is" << multiplier << std::endl;
   return moneyWon;

}



int run_roll (ValAgents user_selection, int* bet){


    srand(time(nullptr));


    // for (auto const& pair : AgentMap){
    //     std::cout << "Key:" << pair.first << "Value:" << pair.second << std::endl;
    // }

    
    
    
    std::cout << "How many rounds do you want to play" << std::endl;
    
    int rounds;

    int money_gained = rounds * (*bet);

    std::array <int,3> reel = generate_reel();

    for (int i:reel){
            std::cout << AgentMap[i] << std::endl;
    }

    int moneywon = calc_win_award(reel, bet, user_selection);

    std::cout << "You have made " << moneywon << " dollars" << std::endl;

    return moneywon;
}

int main(){


    ValAgents user_selection = agent_picker();

    int jackpot = 0;


    int moneywon;


    int rounds;

    std::cout << "Enter number of rounds you want to play" << std::endl;

    std::cin >> rounds;

    for (int i = 0; i <= rounds; i++){


        int* bet = new int;

        std::cout << "How much do you want to bet for this roll, enter an integer value" << std::endl;


        std::cin >> *bet;

        int win = run_roll (user_selection ,bet );
 

        std::cout << "Money won in round: " << i << " is: " << win << std::endl;

        jackpot += win;


        std::cout << "jackpot is: " << jackpot << std::endl; 

        
    }

    return 0;

}
