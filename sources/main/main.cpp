#include "crow.h"
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> parsFun(std::string str)
{
    std::vector<std::string> vecStr(2);
    std::string output;
    bool flag = false;
    int j = 0;
    for (int i = 0; i < str.size(); i++)
    {  
        if (str[i] == '=')
        {
            str.erase(0, i+1);
            flag = true;
            i = -1;
        }
        else if (str[i] == '&')
        {
            str.erase(0, i+1);
            j += 1;
            flag = false;
        }
        else if (flag == true)
        {
            vecStr[j].push_back(str[i]);
        }
    }
    return vecStr;
}

int
main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){ 
        auto page = crow::mustache::load_text("main.html"); 
        return page;
    });

    CROW_ROUTE(app, "/sum")
        .methods("POST"_method)(
            [&](const crow::request& req)
            {
                std::vector<int> num(2);
                num[0] = stoi(parsFun(req.body)[0]);
                num[1] = stoi(parsFun(req.body)[1]);
                std::cout << "sus\\n";
                return std::to_string(num[0]+num[1]);
            });

    
    app.port(18080).multithreaded().run();
}