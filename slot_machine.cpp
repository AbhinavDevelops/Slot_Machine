#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<map>

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

// use a dictionary to make more intuitive on how the agents are selected

ValAgents agent_picker (){

    ValAgents user_selection;

    std::cout << "Pick your agent from Jett,Reyna,Raze,Iso,Pheonix,Yoru";

    std::cin >> user_selection;

    return user_selection;
}


int main (){


    std::map<ValAgents, std::string> AgentMap {{ValAgents::Jett, "Jett"},{ValAgents::Reyna, "Reyna"}};

    for (auto const& pair : AgentMap){
        std::cout << "Key:" << pair.first << "Value:" << pair.second << std::endl;
    }

    std::string lang;

    lang = "skhdfdsh";
    
    std::cout << lang ;

    std::cout << lang;

    ValAgents user_selection = agent_picker();

    return 0;
}
