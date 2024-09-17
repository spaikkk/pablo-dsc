#include "db.hpp"

void remove_space(std::string &pablo){
    pablo.erase(std::remove_if(pablo.begin(), pablo.end(), isspace), pablo.end());
}


void push_bytes(std::vector<char>& buffer, int num){
    buffer.push_back(num);
    buffer.push_back(num>>8);
    buffer.push_back(num>>16);
    buffer.push_back(num>>24);
}

int write(){


    //INVERT THE MAP
    std::unordered_map<std::string, code_param> invert;
    for(auto i = db.begin(); i != db.end(); ++i){
        code_param pair;
        pair.opcode = i->first;
        pair.len = i->second.len;
        std::string key = i->second.command.data();
        invert.insert({key, pair});
    }
    
    //push dsc version value
    std::vector<char> buffer;
    int ver = 353510679;
    push_bytes(buffer, ver);

    //save original path 
    auto dir_path = std::filesystem::current_path();
    // open a dialog box to select the file
    char path[MAX_PATH] = {};
    OPENFILENAME ofn = {sizeof(ofn)};
    ofn.hwndOwner = NULL;
    ofn.lpstrFilter = "All Files\0*.*\0";
    ofn.lpstrFile = path;
    ofn.nMaxFile = ARRAYSIZE(path);

    BOOL open_ok = GetOpenFileName(&ofn);
    if(!open_ok){
        std::cerr << "error opening file" << std::endl;
        return 1;
    }
    std::string command;
    std::string str_path(path);

    std::ifstream txt_file(str_path);
    if(txt_file.is_open()){
        while(std::getline(txt_file, command)){
            
            remove_space(command);
            int str_len = command.length();
            int l_bracket = command.find("(");
            if(l_bracket == std::string::npos){
                std::cerr << "ERROR: Missing '('" << std::endl;
            }
            int r_bracket = command.find(")");
            if(r_bracket==std::string::npos){
                std::cerr << "ERROR: Missing ')'" << std::endl;
            }
            
            //find the opcode and len, stored in an inverted map
            std::string result = command.substr(0, l_bracket);
            
            auto data = invert.find(result);
            
            push_bytes(buffer, data->second.opcode);

            if(data->second.len!=0){
                //get the parameters
                std::string parameters = command.substr(l_bracket+1, (r_bracket-l_bracket)-1);
                std::cout << parameters << std::endl;
                

                std::vector<int> par_count;
                par_count.push_back(0);
                for(int i=0; i<parameters.size(); i++){
                    if(parameters[i]==','){
                        par_count[0]+=1;
                        par_count.push_back(i);
                    }
                }
                par_count.push_back(parameters.size());
                
                std::vector<int> values;
                int starting = 0;
                for(int k=1; k<par_count[0]+2; k++){
                    if(k==1){
                        values.push_back(std::stoi(parameters.substr(0, par_count[k])));
                    }else{
                        values.push_back(std::stoi(parameters.substr(starting+1, (par_count[k]-starting)-1)));
                    }
                    starting = par_count[k];
                }
                for(int p=0; p<values.size(); p++){
                    push_bytes(buffer, values[p]);
                }
            }

        }
    }
    txt_file.close();
    
    std::ofstream dsc_output("./provasc.dsc", std::ios::binary | std::ios::out);

    dsc_output.write(buffer.data(), buffer.size());

    dsc_output.close();


    


    
    return 0;
}
