/*
bool d_input(string input){
    int length = input.length();
    int point_counter = 0;
    for(int i=0; i<length;i++){

        if(!isdigit(input[i])){
            if(input[i]=='.'){
                point_counter++;
                if(point_counter>1){
                    return false;
                }
            }
            else{
                return false;
            }
        }

    }
    return true;
}

bool i_input(string input){
    int length = input.length();
    for(int i=0; i<length;i++){

        if(!isdigit(input[i])){
            return false;
        }

    }
    return true;
}
*/
//convertir inputs a numeros con stod y stoi