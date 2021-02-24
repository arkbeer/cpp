/*
The MIT License (MIT)

Copyright (c) 2021 arkbeer.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<array>

std::vector<std::string> split(std::string& input, const char delimiter){
	std::istringstream stream(input);
	std::string field;
	std::vector<std::string> result{};
	while (getline(stream, field, delimiter)) {
		result.push_back(field);
	}
	return result;
}

auto read_csv(const std::string filename) {
	std::vector<std::vector<std::string>> result{};
	std::ifstream ifs(filename);
	std::string line;
	if (!ifs) { 
		std::cout << "error, " << filename << " does not exist."<<std::endl; 
		return result;
	}
	while (std::getline(ifs, line)) {

		std::vector<std::string> strvec = split(line, ',');
		result.push_back(strvec);
	}

	return result;
}

bool write_csv(const std::string filename, const std::vector<std::vector<std::string>>& output,const int mode=std::ios::out) {
	std::ofstream ofs(filename);
	if (!ofs) {
		return false;
	}
	ofs << output<<std::endl;
	return true;
}