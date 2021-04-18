#include "init_ui.h"

void SetNewWindowHeight(int &w,int &h)
{
    std::string w_buffer, h_buffer;
    std::cout << "Requested Window Width (defaults to 960): ";
    std::cin >> w_buffer;

    std::cout << "Requested Window Height (defaults to 540): ";
    std::cin >> h_buffer;
    
    if (StringToInt(w_buffer, w))
    {
        std::cout << "Initializing with width " << w_buffer << "." << std::endl;
    } else
    {
        std::cout << "Error - Defaulting Width." << std::endl;
        w = 960;
    }
    
    if (StringToInt(h_buffer, h))
    {
        std::cout << "Initializing with height " << h_buffer << "." << std::endl;
    } else
    {
        std::cout << "Error - Defaulting Height." << std::endl;
        h = 540;
    }
    
}

bool StringToInt(const std::string &s, int &i)
{
    std::istringstream n_stream(s);
    if (n_stream >> i)
    {
        return true;
    } else
    {
        return false;
    }
    
    
}