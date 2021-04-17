#ifndef INC_3_LAB_DATA_H
#define INC_3_LAB_DATA_H
#include "pugixml.hpp"
#include <map>
using namespace std;
using namespace pugi;

class Data {
public:
    static vector<string> find_by_delimetr(const char delimiter, string a, const string& type) {
        vector<string> tmp;
        while (!a.empty()) {
            int x = a.find(delimiter);
            if (x == -1) {
                tmp.push_back(a);
                break;
            }
            tmp.push_back(a.substr(0, x));
            if(type == "route")
                a.erase(0, x + 1);
            else
                a.erase(0, x + 2);
        }
        return tmp;
    }

    void find_max_route(int& length, string& name){
        for(auto& item : this->dict) {
            if (item.second > length) {
                length = item.second;
                name = item.first;
            }
        }
    }

    void make_routes(string const& str, pugi::xml_document& doc){
        doc.load_file("data.xml");
        this->dict.clear();
        for (pugi::xml_node node = doc.child("dataset").first_child(); node; node = node.next_sibling()) {
            string type_of_vehicle = node.child("type_of_vehicle").text().as_string();
            if (type_of_vehicle != str)
                continue;
            string routes = node.child("routes").text().as_string();
            vector<string> tmp;
            if (routes.find(',') != -1)
                tmp = find_by_delimetr(',', routes, "route");
            if(routes.find('.') != -1)
                tmp = find_by_delimetr('.', routes, "route");
            if(routes.find(',') == -1 && routes.find('.') == -1)
                tmp.push_back(routes);
            for(auto& route : tmp){
                this->dict[route]++;
            }
        }
    }
    void max_street_stops(pugi::xml_document& doc){
        doc.load_file("data.xml");
        this->dict.clear();
        for(pugi::xml_node node = doc.child("dataset").first_child(); node; node = node.next_sibling()){
            string streets = node.child("location").text().as_string();
            vector<string> tmp = find_by_delimetr(',', streets, "street");
            for(auto& street : tmp)
                this->dict[street]++;
        }
    }
private:
    map<string, int> dict;
};


#endif
