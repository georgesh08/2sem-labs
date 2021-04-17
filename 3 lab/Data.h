#ifndef INC_3_LAB_DATA_H
#define INC_3_LAB_DATA_H
#include "pugixml.hpp"
#include <map>
using namespace std;
using namespace pugi;

class Data {
public:
    vector<string> get_routes(const char delimiter, string a) {
        vector<string> tmp;
        while (!a.empty()) {
            int x = a.find(delimiter);
            if (x == -1) {
                tmp.push_back(a);
                break;
            }
            tmp.push_back(a.substr(0, x));
            a.erase(0, x + 1);
        }
        return tmp;
    }

    void find_max_route(int& route_length, string& route_number){
        for(auto& item : this->dict) {
            int x = item.second;
            if (x > route_length) {
                route_length = item.second;
                route_number = item.first;
            }
        }
    }

    void make_routes(string const& str, pugi::xml_document& doc){
        doc.load_file("data.xml");
        for (pugi::xml_node node = doc.child("dataset").first_child(); node; node = node.next_sibling()) {
            string type_of_vehicle = node.child("type_of_vehicle").text().as_string();
            if (type_of_vehicle != str)
                continue;
            string routes = node.child("routes").text().as_string();
            vector<string> tmp;
            if (routes.find(',') != -1)
                tmp = get_routes(',', routes);
            if(routes.find('.') != -1)
                tmp = get_routes('.', routes);
            if(routes.find(',') == -1 && routes.find('.') == -1)
                tmp.push_back(routes);
            for(auto& route : tmp){
                this->dict[route]++;
            }
        }
    }

    void clear(){
        this->dict.clear();
    }
private:
    map<string, int> dict;
};


#endif
