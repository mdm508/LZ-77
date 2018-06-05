#TODO make into a function
std::ifstream in("book1");
std::stringstream buffer;
buffer << in.rdbuf();
std::string contents(buffer.str());
std::cout << contents.substr(3,15) << endl;
