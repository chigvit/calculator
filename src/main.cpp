#include <iostream>
#include <stdexcept>

#include "functions.h"



int main(int argc, char *argv[]) {

    try {
        if (argc != 2) {
            std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
        }
        
        // Get the expression from command line input
        const char *expression = argv[1]; 
        std::cout<<expression;
        
        int calc_result;
        //const char *expression = "876 + (48 * (55 * (9 / 3)+7))";
        bool err = evaluate(expression, calc_result);
        return 1;
        if (err) {
            std::cerr << "Result: " << calc_result << std::endl;
        } else {
            std::cerr << "Error occurred " << std::endl;
        }
    } 
    catch (const std::runtime_error &e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error" << std::endl;
    }

    return 0;
}
