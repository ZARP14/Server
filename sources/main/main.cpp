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
        auto page2 = crow::mustache::load_text("main.html"); 
        return page2;
    });

    CROW_ROUTE(app, "/sum")
        .methods("POST"_method)(
            [&](const crow::request& req)
            {
                auto page = crow::mustache::load_text("main.html"); 
                std::vector<int> num12(2);
                num12[0] = stoi(parsFun(req.body)[0]);
                num12[1] = stoi(parsFun(req.body)[1]);
                int nnn = num12[0]+num12[1];
                std::string cdcdb = std::to_string(nnn);
                //crow::mustache::context ctx ({{"result", b}});
                //return page.render(ctx);
                return crow::response {404};
            });

    
    app.port(18080).multithreaded().run();
}