#include"includes.hpp"

std::vector<std::vector<int>> parseInputFile() {
    std::ifstream file("input2.txt");
    std::vector<std::vector<int>> result;
    std::string line;

    // Check if file is opened successfully
    if (!file.is_open()) {
        // std::cerr << "Error: Could not open file " << filename << std::endl;
        std::cout<<"err\n";
        return result;
    }

    // Read the file line by line
    while (std::getline(file, line)) {
        // Skip empty lines
        if (line.empty()) continue;

        // Create a vector to store current line's numbers
        std::vector<int> current_line;
        std::istringstream iss(line);
        int num;

        // Parse each number in the line
        while (iss >> num) {
            current_line.push_back(num);
        }

        // Add the line's vector to the 2D vector
        if (!current_line.empty()) {
            result.push_back(current_line);
        }
    }

    return result;
}

///////////////////////////////////////////////[PART 1]//////////////////////////////////////////////////////////////////////////////////////////// 
bool safety(Arr &vec)
{

    for(int i =0;i<vec.size()-1;i++)
    {
        int diff=std::abs(vec[i]-vec[i+1]);
        if(diff < 1  or diff> 4) return false;
    }
    return true;
}

int solve(tArr& arr)
{
    int safe=0;
    for(int i=0;i<arr.size();i++)
    {
        if(safety(arr[i])) ++safe;
    }
    return safe;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    tArr arr=parseInputFile();
    Arr x={12 ,15 ,17 ,21 ,24, 29};

    std::cout<<safety(x);
}