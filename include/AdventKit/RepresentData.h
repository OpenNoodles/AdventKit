#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <cassert>

namespace RepresentData 
{


using Section = std::vector<std::string>;
using LSections = std::vector<Section>;
template<class DataType>
void toVector(const Section& section, std::vector<std::pair<DataType, DataType>>& vec, const std::string& delimiter = " ") {
    for (const auto& line : section) {
        DataType valueA, valueB;
        if (delimiter == " ") {
            std::istringstream stream(line);
            stream >> valueA >> valueB;
            vec.push_back(std::make_pair(valueA, valueB));
            continue;
        }
        const auto delimiterPos = line.find(delimiter);
        if (delimiterPos == std::string::npos || delimiterPos >= line.size()) {
            throw std::invalid_argument("Invalid line format: " + line);
        }
        std::istringstream streamA(line.substr(0, delimiterPos));
        std::istringstream streamB(line.substr(delimiterPos + delimiter.size()));
        streamA >> valueA;
        streamB >> valueB;
        vec.push_back(std::make_pair(valueA, valueB));
    }
}

template<class DataType>
void bySplit(const std::vector<std::string>& rawData, std::vector<std::vector<DataType>>& data, const size_t& numberOfCharacters = 1) {
    assert(numberOfCharacters > 0);
    for (const auto& line : rawData) {
        if (line.empty()) {
            continue;
        }
        data.push_back(std::vector<DataType>());
        size_t index = 0;
        while (index < line.size()) {
            std::string tmp;
            for (size_t i = 0; i < numberOfCharacters; ++i) {
                tmp += line.at(index);
                ++index;
            }
            std::istringstream stream(tmp);
            DataType value;
            stream >> value;
            data.back().push_back(value);
        }
    }
}

template<class DataType>
void toVector(const Section& section, std::vector<std::vector<DataType>>& vec, const std::string& delimiter = "") {
    for (const auto& line : section) {
        vec.push_back(std::vector<DataType>());

        if (delimiter == "") {
            for (const auto character : line) {
                std::string tmp = {character};
                std::istringstream stream(tmp);
                DataType value;
                stream >> value;
                vec.back().push_back(value);
            }
            continue;
        }

        if (delimiter == " ") {
            std::istringstream stream(line);
            DataType value;
            while (stream >> value) {
                vec.back().push_back(value);
            }
            continue;
        }
        size_t tail = 0;
        size_t index = line.find(delimiter);
        const size_t limit = line.size();
        while (index < limit) {
            std::istringstream stream(line.substr(tail, index - tail));
            DataType value;
            stream >> value;
            vec.back().push_back(value);
            tail = index + delimiter.size();
            index = line.find(delimiter, index + 1);
        }
        std::istringstream stream(line.substr(tail));
        DataType value;
        stream >> value;
        vec.back().push_back(value);

        // const auto delimiterPos = line.find(delimiter);
        // if (delimiterPos == std::string::npos || delimiterPos >= line.size()) {
        //     throw std::invalid_argument("Invalid line format: " + line);
        // }


        // std::istringstream stream(line.substr(0, delimiterPos));
        // streamA >> value;
        // vec.push_back(value);
        // std::cerr << vec.back().first << "  " << vec.back().second << "\n";
    }
}






template<class DataType>
void toVector(const Section& section, std::vector<DataType>& vec, const std::string& delimiter = " ") {
    for (const auto& line : section) {

        if (delimiter == " ") {
            std::istringstream stream(line);
            DataType value;
            stream >> value;
            vec.push_back(value);
            continue;
        }
        // const auto delimiterPos = line.find(delimiter);
        // if (delimiterPos == std::string::npos || delimiterPos >= line.size()) {
        //     throw std::invalid_argument("Invalid line format: " + line);
        // }


        // std::istringstream stream(line.substr(0, delimiterPos));
        // streamA >> value;
        // vec.push_back(value);
        // std::cerr << vec.back().first << "  " << vec.back().second << "\n";
    }
}



// template<class DataType>
// void toVector(std::vector<DataType>& a, std::vector<DataType>& b) {
//     auto inputFile = openFile();
//     DataType valueA, valueB;
//     while (inputFile >> valueA >> valueB) {
//         a.emplace_back(valueA);
//         b.emplace_back(valueB);
//     }
//     inputFile.close();
// }

// using Chunk = std::string;
// using ChSections = std::vector<Chunk>;
// void byChunksInSections(ChSections& chunkSections, const std::string& delimiter = "") {
//     auto inputFile = openFile();
//     std::stringstream buffer;
//     buffer << inputFile.rdbuf();
//     inputFile.close();
//     if (delimiter.empty()) {
//         chunkSections.push_back(buffer.str());
//         return;
//     }
//     const std::string& bigChunk = buffer.str();
//     size_t tail = 0;
//     size_t index = bigChunk.find(delimiter);
//     const size_t limit = bigChunk.size();
//     while (index < limit) {
//         chunkSections.push_back(bigChunk.substr(tail, index - tail));
//         tail = index;
//         index = bigChunk.find(delimiter, index + 1);
//     }
//     chunkSections.push_back(bigChunk.substr(tail));
//     chunkSections.shrink_to_fit();
// }

// template<class DataType>
// void toMatrix(std::vector<std::vector<DataType>>& vec) {
//     auto inputFile = openFile();
//     std::string line;
//     while (std::getline(inputFile, line)) {
//         std::vector<DataType> row;
//         std::istringstream stream(line);
//         DataType value;
//         while (stream >> value) {
//             row.push_back(value);
//         }
//         if (!row.empty()) {
//             vec.push_back(row);
//         }
//     }
//     vec.shrink_to_fit();
//     inputFile.close();
// }

// std::ifstream openFile() {
//     std::ifstream inputFile("./data");
//     if (!inputFile.is_open()) {
//         throw std::runtime_error("ReadData::openFile: Can't find file");
//     }
//     return inputFile;
// }

}
