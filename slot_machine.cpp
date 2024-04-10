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



    int row1 = rand()%6 + 1;
    int row2 = rand()%6 + 1;
    int row3 = rand()%6 + 1;

    reel[0] = row1;
    reel[1] = row2;
    reel[2] = row3;

    return reel;
}

int calc_money_made(std::array<int,3> reel, int bet, ValAgents user_selection){



}


int main (){



    for (auto const& pair : AgentMap){
        std::cout << "Key:" << pair.first << "Value:" << pair.second << std::endl;
    }


    ValAgents user_selection = agent_picker();

    std::array<int,3> reel = generate_reel();


    return 0;
}
