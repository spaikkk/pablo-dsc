#include "db.hpp"


//function to interpret 4 signed bytes into a 32bit integer with little endianness
int read_asint(std::vector<char>& data, int index){
    std::vector<unsigned char>  bytes;
    bytes.push_back(data[index]);
    bytes.push_back(data[index+1]);
    bytes.push_back(data[index+2]);
    bytes.push_back(data[index+3]);
    int result = bytes[0] | (bytes[1]<<8) | (bytes[2]<<16) | (bytes[3]<<24);
    return result;
}

int read(){
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
    }

    std::string str_path(path);

    //check if the extension is correct
    std::filesystem::path path_obj = str_path;
    if(path_obj.extension() != ".dsc"){
        std::cerr << "File extension not recognised" << std::endl;
    }

    //read the file and store it in array
    std::ifstream dsc_file(str_path, std::ios::in | std::ios::binary);
    uint32_t const fsize = std::filesystem::file_size(str_path);
    std::vector<char> data(fsize);
    dsc_file.read(data.data(), fsize);
    dsc_file.close();

    //Create the file to store the decoded data, saved by default in build/debug
    dir_path += "\\output.txt";
    std::cout << dir_path << std::endl;
    std::ofstream outf(dir_path);
    outf << "debug";

    //read the first 4 bytes to detect the format 
    int first_value = read_asint(data, 0);

    //format auto identifier not implement yet
    std::cout << "Format Identifier: " << first_value << " = Future Tone DSC" << std::endl;

    //index starts at 4, format first value ignored
    for(int i=4; i<data.size(); i+=4){
        std::string line;
        int opcode = read_asint(data, i);
        auto element = db.find(opcode);
        if (element != db.end()){
            int len = element->second.len;
            std::vector<int> cmds;
            for(int j=0; j<len; j++){
                i+=4;
                cmds.push_back(read_asint(data, i));      
            }
            line += element->second.command.data();
            if(cmds.size()>0){
                line += "(";
                for (int k=0; k<cmds.size(); k++){
                    line += std::to_string(cmds[k]);
                    if(k==(cmds.size()-1)){
                        line += ");";
                    }else{
                        line += ", ";
                    }
                }
            }else{

                line += "();";
            }
            outf << line << std::endl;

        }else{
            std::cerr << "Opcode not recognised\n";
        }

        
    }
    return 0;
}
