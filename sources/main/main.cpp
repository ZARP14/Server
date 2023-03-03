#include "crow.h"
#include <iostream>
#include <string>

std::string parsFun(std::string str)
{
    std::string output;
    int numBuf = 0;
    str.erase(0,1);
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i] == '=')
        {
            str.erase(numBuf, i-numBuf);
        }
        else if (str[i] == '&')
        {
            numBuf = i;
        }
    }
    return str;
}

int
main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){ 
        auto page = crow::mustache::load_text("main.html"); 
        return page;
    });

    CROW_ROUTE(app, "/sum/<string>")([](std::string str){ 
       return crow::response(parsFun(str));
    });
    app.port(18080).multithreaded().run();
}