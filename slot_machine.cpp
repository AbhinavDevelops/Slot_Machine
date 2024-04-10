#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<map>
#include<array>
#include<cstdlib>

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

    std:: cout << "The agent the user selected:" << user_selection << std::endl;

    return user_selection;
}

std::array<int,3> generate_reel(){

    std::array<int,3> reel;

    for (static int i = 0; i< 3; ++i){
        int random = rand()%6 + 1;

        // could add a sleep function here to imitate the slow rolling of the reel

        reel[i] = random;
        // std::cout << "rand is" << random << std::endl;
    }

    return reel;
}

int calc_win_award(std::array<int,3> reel,int bet, ValAgents user_selection){

    int moneyWon = -bet ;

    int multiplier = 1;

    bool same = (reel[0] == reel[1] && reel[2]== reel[1]);

    for (int i = 0; i<3; ++i){
       if (reel[i] == static_cast<int>(user_selection)){
        multiplier += 0.15;

        std:: cout << AgentMap[reel[i]] << " " << user_selection << std::endl;
       }
    }

    if(same) multiplier *= 2;


    std::cout << "multiplier is" << multiplier << std::endl;
    if (multiplier > 1) return moneyWon * -multiplier;
   return moneyWon;

}

int simulate_roll (int bet, ValAgents user_selection){


    srand(time(nullptr));


    std::array<int,3> reel = generate_reel();

      for (int i: reel){

        // std::cout << i << std::endl;
        
        std::cout << "rows are " << AgentMap[i] << std::endl;

    }




    int money_won = calc_win_award(reel,bet, user_selection);

    std::cout << "You won " << money_won << " Dollars" << std::endl;

    return money_won;
}

int main (){


    // for (auto const& pair : AgentMap){
    //     std::cout << "Key:" << pair.first << "Value:" << pair.second << std::endl;
    // }


    ValAgents user_selection = agent_picker();

    

    int bet;

    std::cout << "How much do you want to bet for this roll, enter an integer value" << std::endl;
    
    std::cin >> bet;
    
    std::cout << "How many rounds do you want to play" << std::endl;
    
    int rounds;

    std::cin >> rounds;

    int money_gained = rounds * bet;

    for (static int i = 1; i <= rounds; ++i){
        int money_won = simulate_roll(bet, user_selection);
        money_gained += money_won;
    }

    std::cout << "You have made " << money_gained << " dollars";

    return 0;
}
