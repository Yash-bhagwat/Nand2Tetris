#include <bits/stdc++.h>
using namespace std;
map<string,string> mp_dest;
map<string,string> mp_jump;
map<string,string> mp_comp;
map<string,int> symbolTable;

void maps();
void clr_comments_whitespace(string &str){
	str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
    string temp="";
    int i=0;
    while(i< (int) str.length() and str[i]!='/'){
        temp.push_back(str[i]);
        i++;
    }
    str=temp;
}
bool is_number(const string &str) {return str.find_first_not_of("0123456789") == string::npos;}

int main(int argc, char *argv[]){
	//Handling IO
    ofstream fout;
    string ipinput = argv[1];
    ifstream input_file(ipinput);
    string output_file = ipinput.substr(0, ipinput.length() - 4) + ".hack";
    ofstream WritingTo(output_file);
	//Processing
	maps();
	//First pass, looking only at labels
	string cur_line; 
	int instruction_number = 0;
	while (getline(input_file, cur_line)) {
        clr_comments_whitespace(cur_line);
        if(cur_line.length()==0) continue;
        if(cur_line[0]=='('){ //denotes label
            string temp=cur_line.substr(1,cur_line.length()-2);
            symbolTable[temp]=instruction_number;
        }
        else instruction_number++;
    }
    //Second pass
    input_file.clear();
    input_file.seekg(0,std::ios::beg);
    
    int allocated = 16;
    while (getline(input_file, cur_line)) {
        clr_comments_whitespace(cur_line);
        if(cur_line.length()==0 || cur_line[0]!='@') continue; //Not a variable
        string temp=cur_line.substr(1,cur_line.length()-1);
        if(is_number(temp)) continue;
        if(symbolTable.find(temp) == symbolTable.end()){
			symbolTable[temp] = allocated++;
		}
    }
    //Third pass : Actual Conversion
    input_file.clear();
    input_file.seekg(0,std::ios::beg);
    
    //for(auto i : symbolTable){
		//cout << i.first << " " << i.second << endl;
	//}
	//return 0;
    
    while (getline(input_file, cur_line)) {
        clr_comments_whitespace(cur_line);
        //if empty
        if(cur_line.length() == 0) continue;
        //if A instruction
        int int_cur_line;
        if(cur_line[0] == '@'){
			string opt;
			string strip0 = cur_line.substr(1,cur_line.length()-1);
			if(is_number(strip0)) int_cur_line = stoi(strip0);
			else {int_cur_line = symbolTable[strip0];
				 //cout << cur_line << " " << int_cur_line << endl;
				 }
			int sizeofopt = 15;
			while(sizeofopt--){ //Converting to binary
				opt += to_string(int_cur_line % 2);
				int_cur_line /= 2;
			}
			opt += '0'; //A instruction
			reverse(opt.begin(),opt.end());
			WritingTo<<opt<<endl;
		}
		//ignoring labels
		else if(cur_line[0] == '(') continue;
		else{
			//basically a 'C' instruction, so the first 3 bits have to be '111'
			string opt = "111";
			// dest=comp;jump ==> this is the format
			int sz = cur_line.size();
			bool contains_equal = false;
			bool contains_semicolon = false;
			for(int i = 0; i < sz; i++){
				if(cur_line[i] == '=') contains_equal = true;
				if(cur_line[i] == ';') contains_semicolon = true;
			}
			if(!contains_equal){
				//comp;jump
				string compr, jumpr;
				bool colons = false;
				for(int i = 0; i < sz; i++){
					if(!colons && cur_line[i]!=';') compr += cur_line[i];
					if(colons) jumpr += cur_line[i];
					if(cur_line[i] == ';') colons = true;
				}
				opt += mp_comp[compr] + "000" + mp_jump[jumpr];
			}
			else if(!contains_semicolon){
				//dest=comp
				string destr, compr;
				bool equals = false;
				for(int i = 0; i < sz; i++){
					if(!equals && cur_line[i]!='=') destr += cur_line[i];
					if(equals) compr += cur_line[i];
					if(cur_line[i] == '=') equals = true;
				}
				opt += mp_comp[compr] + mp_dest[destr] + "000";
			}else{
				//dest=comp;jump
				string destr, compr, jumpr;
				bool equals = false;
				bool colons = false;
				for(int i = 0; i < sz; i++){
					if(cur_line[i] != '=' && cur_line[i] != ';'){
						if(!equals) destr += cur_line[i];
						else if(equals && !colons) compr += cur_line[i];
						else jumpr += cur_line[i];
					}
					else if(cur_line[i] == '=') equals = true;
					else if(cur_line[i] == ';') colons = true;
					
				}
				opt += mp_comp[compr] + mp_dest[destr] + mp_jump[jumpr];	
			}		
			WritingTo<<opt<<endl;	
		}
    }
   
}

void maps(){
    //dest map
	mp_dest["M"]="001";
	mp_dest["D"]="010";
	mp_dest["MD"]="011";
	mp_dest["A"]="100";
	mp_dest["AM"]="101";
	mp_dest["AD"]="110";
	mp_dest["AMD"]="111";
    //jump map
	mp_jump["JGT"]="001";
	mp_jump["JEQ"]="010";
	mp_jump["JGE"]="011";
	mp_jump["JLT"]="100";
	mp_jump["JNE"]="101";
	mp_jump["JLE"]="110";
	mp_jump["JMP"]="111";
    //comp map
    //All the different operations
	mp_comp["0"]="0101010";
	mp_comp["1"]="0111111";
	mp_comp["-1"]="0111010";
	mp_comp["D"]="0001100";
	mp_comp["A"]="0110000";
	mp_comp["!D"]="0001101";
	mp_comp["!A"]="0110001";
	mp_comp["-D"]="0001111";
	mp_comp["-A"]="0110011";
	mp_comp["D+1"]="0011111";
	mp_comp["A+1"]="0110111";
	mp_comp["D-1"]="0001110";
	mp_comp["A-1"]="0110010";
	mp_comp["D+A"]="0000010";
	mp_comp["D-A"]="0010011";
	mp_comp["A-D"]="0000111";
	mp_comp["D&A"]="0000000";
	mp_comp["D|A"]="0010101";
	mp_comp["M"]="1110000";
	mp_comp["!M"]="1110001";
	mp_comp["-M"]="1110011";
	mp_comp["M+1"]="1110111";
	mp_comp["M-1"]="1110010";
	mp_comp["D+M"]="1000010";
	mp_comp["D-M"]="1010011";
	mp_comp["M-D"]="1000111";
	mp_comp["D&M"]="1000000";
	mp_comp["D|M"]="1010101";
    //symbolTable
    symbolTable["SP"]= 0;
	symbolTable["LCL"]= 1;
	symbolTable["ARG"]= 2;
	symbolTable["THIS"]= 3;
	symbolTable["THAT"]= 4;
	symbolTable["R0"]= 0;
	symbolTable["R1"]= 1;
	symbolTable["R2"]= 2;
	symbolTable["R3"]= 3;
	symbolTable["R4"]= 4;
	symbolTable["R5"]= 5;
	symbolTable["R6"]= 6;
	symbolTable["R7"]= 7;
	symbolTable["R8"]= 8;
	symbolTable["R9"]= 9;
	symbolTable["R10"]=10;
	symbolTable["R11"]=11;
	symbolTable["R12"]=12;
	symbolTable["R13"]=13;
	symbolTable["R14"]=14;
	symbolTable["R15"]=15;
	symbolTable["SCREEN"]= 16384;
	symbolTable["KBD"]= 24576;
}
