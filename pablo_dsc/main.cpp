#include "db.hpp"


int main(int argc, char* argv[]){

    /*
        the user need to specify in the command line which 
        script he wants to use by writing one of the options below
        "read" --> reader
        "write" --> writer
    */
    if(argc!=2){
        std::cerr << "Script selection not specified" << std::endl;
        return 1; 
    }
    std::string mode(argv[1]);
    if(mode=="read"){
        int read_result = read();
        if(read_result==1){
            std::cerr << "Something went wrong :(" << std::endl;
        }else{
            std::cout << "File succesfully read, output in /build/debug";
        }
    }else if(mode=="write"){
        int write_result = write();
        if(write_result==1){
            std::cerr << "Something went wrong :(" << std::endl;
        }else{
            std::cout << "File succesfully written, output in /build/debug";
        }
    }else{
        std::cerr << "Script selector argument wrong" << std::endl;
    }

    return 0;
}

















/*
    ▇▅▆▇▆▅▅█ 
*/